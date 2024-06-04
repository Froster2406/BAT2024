/*
 * BAT_PDM.c
 *
 *  Created on: 16.03.2024
 *      Author: Stefano Nicora
 */

#include "BAT_PDM.h"
#include <stdbool.h>

/***************************************************************************//**
 * @brief
 *   Initialize the PDM peripheral
 *
 ******************************************************************************/
void BAT_PDM_init(void){
  CMU_DPLLInit_TypeDef pllInit = CMU_DPLL_LFXO_TO_40MHZ;
  CMU_LFXOInit_TypeDef lfxoInit = CMU_LFXOINIT_DEFAULT;
  CMU_LFXOInit(&lfxoInit);
  CMU_ClockEnable(cmuOsc_LFXO, true);
  CMU_ClockEnable(cmuOsc_HFXO, true);
  CMU_OscillatorEnable(cmuOsc_LFXO, true, true); /* legacy function call */
  /* Lock PLL
   * Frequency will be Fref*(N+1)/(M+1)
   * https://www.desmos.com/calculator/bnr56drrhv */
#if DOWNSAMPLINGRATE == 32
    pllInit.frequency = 1411209;
    pllInit.m = 14;
    pllInit.n = 645;
#endif
#if DOWNSAMPLINGRATE == 64
    pllInit.frequency = 3072000;
    pllInit.m = 39;
    pllInit.n = 3749;
#endif
  if(!CMU_DPLLLock(&pllInit)){
      while(1){}
  }

  /* Setup all GPIO's. */
  GPIO_PinModeSet(BAT_MIC_CLK_PORT, BAT_MIC_CLK_PIN, gpioModePushPull, 0);
  GPIO_PinModeSet(BAT_MIC_DATA_PORT, BAT_MIC_DATA_PIN, gpioModeInput, 0);

  /*Set fast slew rate on PDM mic CLK and DATA pins */
  GPIO_SlewrateSet(BAT_MIC_CLK_PORT, 7U, 7U);
  GPIO_SlewrateSet(BAT_MIC_DATA_PORT, 7U, 7U);

  /* Select PDM reference clock source and enable it. */
  CMU_ClockSelectSet(cmuClock_EM01GRPBCLK, cmuSelect_HFRCODPLL);
  CMU_Select_TypeDef clk = CMU_ClockSelectGet(cmuClock_EM01GRPBCLK);

  /* Enable PDM peripheral clock. */
  CMU_ClockEnable(cmuClock_EM01GRPBCLK, true);
  CMU_ClockEnable(cmuClock_PDM, true);
  CMU_ClockEnable(cmuClock_PDMREF, true);

  /* Route PDM signals to correct GPIO's. */
  GPIO->PDMROUTE.CLKROUTE = (BAT_MIC_CLK_PIN << _GPIO_PDM_CLKROUTE_PIN_SHIFT) | BAT_MIC_CLK_PORT;
  GPIO->PDMROUTE.DAT0ROUTE = (BAT_MIC_DATA_PIN << _GPIO_PDM_DAT0ROUTE_PIN_SHIFT) | BAT_MIC_DATA_PORT;
  GPIO->PDMROUTE.ROUTEEN = 0x1;

  PDM_Init_TypeDef init = PDM_INIT_DEFAULT;
  init.start = false;
  init.dataFormat = pdmDataFormatRight24;
  init.enableCh0Ch1Stereo = false;
  init.numChannels = pdmNumberOfChannelsOne;
  /* Calculate gain (shift value) based on DSR and filter order */
  uint8_t gain = 31 - (1 + (uint32_t)ceil((log10f(pow(DOWNSAMPLINGRATE, 5)) / log10f(2))));

  /* Calculate necessary prescaler based on desired sample rate and DSR */
  uint32_t clock_freq = CMU_ClockFreqGet(cmuClock_EM01GRPBCLK);
  uint32_t prescaler_val = (clock_freq / (48000 * DOWNSAMPLINGRATE)) - 1;

  init.prescaler = prescaler_val;  /* Formula: (clock_freq / (sample_rate * downSamplingRate)) - 1 */
  init.dsr = DOWNSAMPLINGRATE;
//  init.gain = gain; /* Formula: 31 - (1 + (log10(downSamplingRate^filterOrder) / log10(2))) */
  init.gain = 1; /* Formula: 31 - (1 + (log10(downSamplingRate^filterOrder) / log10(2))) */
  PDM_Init(PDM, &init);
  /* disable all interrupts */
  PDM_IntDisable(PDM, PDM_IEN_DV | PDM_IEN_DVL | PDM_IEN_OF | PDM_IEN_UF);
}

/***************************************************************************//**
 * @brief
 *   Deinitialize the PDM peripheral
 *
 ******************************************************************************/
void BAT_PDM_deInit(void){

}

/***************************************************************************//**
 * @brief
 *   Reads N samples from the microphone to the buffer
 *
 * @param[in] buffer
 *   Data-array that holds PCM data samples
 *
 * @param[in] N
 *   Number of data samples to be stored
 *
 ******************************************************************************/
void BAT_PDM_readMicrophone(int32_t *buffer, uint16_t N){
  PDM_Clear(PDM);
  PDM_FifoFlush(PDM);
  PDM_Start(PDM);
  sl_udelay_wait(18000); /* startup / wakeup time for microphone */
  PDM_FifoFlush(PDM);
  for(uint16_t i = 0; i < N; i++){
      PDM_FifoFlush(PDM);
      buffer[i] = PDM_Rx(PDM);
  }
//  PDM_Stop(PDM);
}

/***************************************************************************//**
 * @brief
 *   Converts a PCM data stream to a SPL value | Fs = 48kHz
 *
 * @param[in] buffer
 *   Data-array that holds PCM data samples
 *
 * @param[in] samples
 *   Number of data samples to be converted
 *
 * @param[out] dBSPL
 *   Represents the computed dBSPL data
 *
 ******************************************************************************/
void BAT_PDM_convertPCMTodBSPL(int32_t *buffer, uint16_t samples, float *dBSPL){
  int64_t sample = 0;
  int64_t RMS = 0;
  int64_t mean = 0;
  uint16_t i = 0;

  /* DC-Offset removal (mean calculation) */
  mean = 0.0f;
  for (i = 0; i < samples; i++) {
    mean += buffer[i];
  }
  mean = mean / samples;

  /* RMS value calculation (the signals energy) */
  RMS = 0;
  for ( i = 0; i < samples; i++) {
    sample = buffer[i] - mean;  /* offset removal */
    RMS += (sample * sample);   /* signal quadrature and generate sum */
  }
  RMS = sqrt(RMS / samples);

  /* calculate dB value */
  *dBSPL = 20 * log10f(RMS / 8388607.0f);
  *dBSPL += 129.5;              /* add result to AOP */
}

/***************************************************************************//**
 * @brief
 *   Apply A filter (Direct form II transposed) onto data | Fs = 48kHz
 *
 * @param[in] x
 *   Data-array that holds PCM data samples
 *
 * @param[in] y
 *   Data-array that holds the filtered PCM data samples
 *
 * @param[in] k
 *   Number of data samples contained inside x as well as y
 *
 ******************************************************************************/
void BAT_PDM_applyAWeightingFilter(int32_t *x, int32_t *y, uint16_t k){
  /* coefficients */
  static double A_a_1_koeff[2] = { -0.224558458059779, 0.012606625271546};
  static double A_a_2_koeff[2] = { -1.893870494723071,  0.895159769094661};
  static double A_a_3_koeff[2] = { -1.994614455993022,  0.994621707014085};
  static double A_b_1_koeff[3] = { 1, 2, 1};
  static double A_b_2_koeff[3] = { 1, -2, 1};
  static double A_b_3_koeff[3] = { 1, -2, 1};
  /* first iteration */
  for(uint16_t i = 0; i < k ; i++){
      y[i+2] = x[i] * A_b_1_koeff[0] + x[i+1] * A_b_1_koeff[1] + x[i+2] * A_b_1_koeff[2] - y[i+1] * A_a_1_koeff[0] - y[i] * A_a_1_koeff[1];
  }
  /* second iteration */
  memcpy(x, y, k);  /* copy output of first stage into input of second stage */
  for(uint16_t i = 0; i < k ; i++){
      y[i+2] = x[i] * A_b_2_koeff[0] + x[i+1] * A_b_2_koeff[1] + x[i+2] * A_b_2_koeff[2] - y[i+1] * A_a_2_koeff[0] - y[i] * A_a_2_koeff[1];
  }
  /* third iteration */
  memcpy(x, y, k);  /* copy output of second stage into input of third stage */
  for(uint16_t i = 0; i < k ; i++){
      y[i+2] = x[i] * A_b_3_koeff[0] + x[i+1] * A_b_3_koeff[1] + x[i+2] * A_b_3_koeff[2] - y[i+1] * A_a_3_koeff[0] - y[i] * A_a_3_koeff[1];
  }
}

/***************************************************************************//**
 * @brief
 *   Apply C filter (Direct form II transposed) onto data | Fs = 48kHz
 *
 * @param[in] x
 *   Data-array that holds PCM data samples
 *
 * @param[in] y
 *   Data-array that holds the filtered PCM data samples
 *
 * @param[in] k
 *   Number of data samples contained inside x as well as y
 *
 ******************************************************************************/
void BAT_PDM_applyCWeightingFilter(int32_t *x, int32_t *y, uint16_t k){
  /* coefficients */
  static double C_a_1_koeff[2] = { -0.224558458059779, 0.012606625271546};
  static double C_a_2_koeff[2] = { -1.994614455993022,  0.994621707014085};
  static double C_b_1_koeff[3] = { 1, 2, 1};
  static double C_b_2_koeff[3] = { 1, -2, 1};
  /* first iteration */
  for(uint16_t i = 0; i < k ; i++){
      y[i+2] = x[i] * C_b_1_koeff[0] + x[i+1] * C_b_1_koeff[1] + x[i+2] * C_b_1_koeff[2] - y[i+1] * C_a_1_koeff[0] - y[i] * C_a_1_koeff[1];
  }
  /* second iteration */
  memcpy(x, y, k);  /* copy output of first stage into input of second stage */
  for(uint16_t i = 0; i < k ; i++){
      y[i+2] = x[i] * C_b_2_koeff[0] + x[i+1] * C_b_2_koeff[1] + x[i+2] * C_b_2_koeff[2] - y[i+1] * C_a_2_koeff[0] - y[i] * C_a_2_koeff[1];
  }
}

void BAT_PDM_convertSPLToString(double dBSPL, char* str){
  /* floating-point support for printf needs to be enabled for this to work
   * Main folder ->  Properties -> C/C++ Build -> Settings -> GNU ARM C Linker -> General -> Printf float*/
  /* convert float to str */
  snprintf(str, 6, "%.2f", dBSPL);
}
