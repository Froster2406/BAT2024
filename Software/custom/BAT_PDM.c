/*
 * BAT_PDM.c
 *
 *  Created on: 16.03.2024
 *      Author: FrosterOTG
 */

#include "BAT_PDM.h"
#include <stdbool.h>


void BAT_PDM_init(void){
  CMU_DPLLInit_TypeDef pllInit = CMU_DPLL_LFXO_TO_40MHZ;
  CMU_LFXOInit_TypeDef lfxoInit = CMU_LFXOINIT_DEFAULT;
  CMU_LFXOInit(&lfxoInit);
  CMU_ClockEnable(cmuOsc_LFXO, true);
  CMU_ClockEnable(cmuOsc_HFXO, true);
  CMU_OscillatorEnable(cmuOsc_LFXO, true, true); /* legacy function call */
//  CMU_ClockEnable(cmuOsc_HFXO, true);
//  CMU_OscillatorEnable(cmuOsc_HFXO, true, true);
  /* Lock PLL to 1,411,209 Hz to achieve 44,100 kHz PCM sampling rate */
  /* when using 32x PDM oversampling
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

  // Set fast slew rate on PDM mic CLK and DATA pins
  GPIO_SlewrateSet(BAT_MIC_CLK_PORT, 7U, 7U);
  GPIO_SlewrateSet(BAT_MIC_DATA_PORT, 7U, 7U);

  /* Select PDM reference clock source and enable it. */
  CMU_ClockSelectSet(cmuClock_EM01GRPBCLK, cmuSelect_HFRCODPLL);
  CMU_ClockSelectSet(cmuClock_PDMREF, cmuSelect_HFXO);
  /* Enable PDM peripheral clock. */
  CMU_ClockEnable(cmuClock_EM01GRPBCLK, true);
  CMU_ClockEnable(cmuClock_PDM, true);
  CMU_ClockEnable(cmuClock_PDMREF, true);
  /* Route PDM signals to correct GPIO's. */
  GPIO->PDMROUTE.CLKROUTE = (BAT_MIC_CLK_PIN << _GPIO_PDM_CLKROUTE_PIN_SHIFT) | BAT_MIC_CLK_PORT;
  GPIO->PDMROUTE.DAT0ROUTE = (BAT_MIC_DATA_PIN << _GPIO_PDM_DAT0ROUTE_PIN_SHIFT) | BAT_MIC_DATA_PORT;
  GPIO->PDMROUTE.ROUTEEN = 0x1;

  /* sample rate: 44100, downSamplingRate: 32*/
  PDM_Init_TypeDef init = PDM_INIT_DEFAULT;
  init.start = false;

  init.dataFormat = pdmDataFormatRight16;
//  init.dataFormat = pdmDataFormatRight24;
  init.enableCh0Ch1Stereo = false;
  init.numChannels = pdmNumberOfChannelsOne;
  /* Calculate gain (shift value) based on DSR and filter order */
  uint8_t gain = 31 - (1 + (uint32_t)ceil((log10f(pow(DOWNSAMPLINGRATE, 5)) / log10f(2))));

  /* Calculate necessary prescaler based on desired sample rate and DSR */
  uint32_t clock_freq = CMU_ClockFreqGet(cmuClock_EM01GRPBCLK);
  uint32_t prescaler_val = (clock_freq / (48000 * DOWNSAMPLINGRATE)) - 1;

  init.prescaler = prescaler_val;  /* Formula: (clock_freq / (sample_rate * downSamplingRate)) - 1 */
  init.dsr = DOWNSAMPLINGRATE;
  init.gain = gain; /* Formula: 31 - (1 + (log10(downSamplingRate^filterOrder) / log10(2))) */

  PDM_Init(PDM, &init);
  /* disable all interrupts */
  PDM_IntDisable(PDM, PDM_IEN_DV | PDM_IEN_DVL | PDM_IEN_OF | PDM_IEN_UF);
}

void BAT_PDM_deInit(void){

}

void BAT_PDM_readMicrophone(int32_t *buffer, uint16_t samples){
  PDM_Clear(PDM);
  PDM_FifoFlush(PDM);
  PDM_Start(PDM);
  sl_udelay_wait(18000); /* startup / wakeup time for microphone */
  PDM_FifoFlush(PDM);
  for(uint8_t i = 0; i < samples; i++){
      PDM_FifoFlush(PDM);
      buffer[i] = PDM_Rx(PDM);
  }
  PDM_Stop(PDM);
}

void BAT_PDM_convertPCMTodBSPL(int32_t *buffer, uint16_t samples, float *dBSPL){
  float sample;
  float power;
  float mean;
  uint32_t i;

  // Calculate mean
  mean = 0.0f;
  for ( i = 1; i < samples; i++) {
    mean += buffer[i];
  }
  mean = mean / samples;

  // Calculate variance
  power = 0;
  for ( i = 1; i < samples; i++) {
    sample = ((buffer[i] - mean) / 32767.0f);
    power += sample * sample;
  }
  power = power / samples;
  // Convert to dBSPL
  *dBSPL = (10.0f * log10f(power) + 120);
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
 * @param[in] x
 *   Number of data samples contained inside x as well as y
 *
 ******************************************************************************/
//void BAT_PDM_applyAWeightingFilter(double *x, double *y, uint16_t k){
//  /* coefficients */
//  static double A_a_1_koeff[2] = { -0.224558458059779, 0.012606625271546};
//  static double A_a_2_koeff[2] = { -1.893870494723071,  0.895159769094661};
//  static double A_a_3_koeff[2] = { -1.994614455993022,  0.994621707014085};
//  static double A_b_1_koeff[3] = { 1, 2, 1};
//  static double A_b_2_koeff[3] = { 1, -2, 1};
//  static double A_b_3_koeff[3] = { 1, -2, 1};
//  /* first iteration */
//  for(uint16_t i = 0; i < k ; i++){
//      y[i+2] = x[i] * A_b_1_koeff[0] + x[i+1] * A_b_1_koeff[1] + x[i+2] * A_b_1_koeff[2] - y[i+1] * A_a_1_koeff[0] - y[i] * A_a_1_koeff[1];
//  }
//  /* second iteration */
//  memcpy(x, y, k);  /* copy output of first stage into input of second stage */
//  for(uint16_t i = 0; i < k ; i++){
//      y[i+2] = x[i] * A_b_2_koeff[0] + x[i+1] * A_b_2_koeff[1] + x[i+2] * A_b_2_koeff[2] - y[i+1] * A_a_2_koeff[0] - y[i] * A_a_2_koeff[1];
//  }
//  /* third iteration */
//  memcpy(x, y, k);  /* copy output of second stage into input of third stage */
//  for(uint16_t i = 0; i < k ; i++){
//      y[i+2] = x[i] * A_b_3_koeff[0] + x[i+1] * A_b_3_koeff[1] + x[i+2] * A_b_3_koeff[2] - y[i+1] * A_a_3_koeff[0] - y[i] * A_a_3_koeff[1];
//  }
//}

///***************************************************************************//**
// * @brief
// *   Apply C filter (Direct form II transposed) onto data | Fs = 48kHz
// *
// * @param[in] x
// *   Data-array that holds PCM data samples
// *
// * @param[in] y
// *   Data-array that holds the filtered PCM data samples
// *
// * @param[in] x
// *   Number of data samples contained inside x as well as y
// *
// ******************************************************************************/
//void BAT_PDM_applyCWeightingFilter(double *x, double *y, uint16_t k){
//  /* coefficients */
//  static double C_a_1_koeff[2] = { -0.224558458059779, 0.012606625271546};
//  static double C_a_2_koeff[2] = { -1.994614455993022,  0.994621707014085};
//  static double C_b_1_koeff[3] = { 1, 2, 1};
//  static double C_b_2_koeff[3] = { 1, -2, 1};
//  /* first iteration */
//  for(uint16_t i = 0; i < k ; i++){
//      y[i+2] = x[i] * C_b_1_koeff[0] + x[i+1] * C_b_1_koeff[1] + x[i+2] * C_b_1_koeff[2] - y[i+1] * C_a_1_koeff[0] - y[i] * C_a_1_koeff[1];
//  }
//  /* second iteration */
//  memcpy(x, y, k);  /* copy output of first stage into input of second stage */
//  for(uint16_t i = 0; i < k ; i++){
//      y[i+2] = x[i] * C_b_2_koeff[0] + x[i+1] * C_b_2_koeff[1] + x[i+2] * C_b_2_koeff[2] - y[i+1] * C_a_2_koeff[0] - y[i] * C_a_2_koeff[1];
//  }
//}

void BAT_PDM_convertSPLToString(double dBSPL, char* str){
  /* floating-point support for printf needs to be enabled for this to work
   * Main folder ->  Properties -> C/C++ Build -> Settings -> GNU ARM C Linker -> General -> Printf float*/
  /* convert float to str */
  snprintf(str, 6, "%.2f", dBSPL);
}
