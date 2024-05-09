/*
 * BAT_PDM.c
 *
 *  Created on: 16.03.2024
 *      Author: FrosterOTG
 */

#include "BAT_PDM.h"


void BAT_PDM_init(void){
  CMU_DPLLInit_TypeDef pllInit = CMU_DPLL_LFXO_TO_40MHZ;

  CMU_OscillatorEnable(cmuOsc_LFXO, true, true);
//  CMU_OscillatorEnable(cmuOsc_HFXO, true, true);
//  CMU_OscillatorEnable(cmuOsc_FSRCO, true, true);
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
//  pllInit.frequency = 2822400;
//  pllInit.m = 5;
//  pllInit.n = 516;
//      pllInit.frequency = 3072000;
//      pllInit.m = 5;
//      pllInit.n = 562;
#endif
  CMU_DPLLLock(&pllInit);

  /* Setup all GPIO's. */
  GPIO_PinModeSet(BAT_MIC_CLK_PORT, BAT_MIC_CLK_PIN, gpioModePushPull, 0);
  GPIO_PinModeSet(BAT_MIC_DATA_PORT, BAT_MIC_DATA_PIN, gpioModeInput, 0);

  // Set fast slew rate on PDM mic CLK and DATA pins
  GPIO_SlewrateSet(BAT_MIC_CLK_PORT, 7U, 7U);

  /* Enable PDM peripheral clock. */
  CMU_ClockEnable(cmuClock_PDM, true);
  /* Select PDM reference clock source and enable it. */
//  CMU_ClockSelectSet(cmuClock_PDMREF, cmuSelect_FSRCO);
//  CMU_ClockSelectSet(cmuClock_PDMREF, cmuSelect_LFXO);
  CMU_ClockSelectSet(cmuClock_PDMREF, cmuSelect_HFRCODPLL);
  CMU_ClockEnable(cmuClock_PDMREF, true);

  /* Route PDM signals to correct GPIO's. */
  GPIO->PDMROUTE.CLKROUTE = (BAT_MIC_CLK_PIN << _GPIO_PDM_CLKROUTE_PIN_SHIFT) | BAT_MIC_CLK_PORT;
  GPIO->PDMROUTE.DAT0ROUTE = (BAT_MIC_DATA_PIN << _GPIO_PDM_DAT0ROUTE_PIN_SHIFT) | BAT_MIC_DATA_PORT;
  GPIO->PDMROUTE.ROUTEEN = 0x1;

  /* sample rate: 44100, downSamplingRate: 32*/
  PDM_Init_TypeDef init = PDM_INIT_DEFAULT;
  init.start = false;
  uint32_t clock_freq = CMU_ClockFreqGet(cmuClock_PDM); /* 20MHz */
  init.dataFormat = pdmDataFormatRight16;
//  init.dataFormat = pdmDataFormatDouble16;
//  init.dataFormat = pdmDataFormatRight24;
  init.enableCh0Ch1Stereo = false;
  init.numChannels = pdmNumberOfChannelsOne;
#if DOWNSAMPLINGRATE == 32
  init.prescaler = 13;  /* Formula: (clock_freq / (sample_rate * downSamplingRate)) - 1 */
  init.dsr = DOWNSAMPLINGRATE;
  init.gain = 5; /* Formula: 31 - (1 + (log10(downSamplingRate^filterOrder) / log10(filterOrder))) */ /*5*/
#endif
#if DOWNSAMPLINGRATE == 64
//    init.prescaler = 1; /* Formula: (clock_freq / (sample_rate * downSamplingRate)) - 1 */
//    init.dsr = DOWNSAMPLINGRATE;
//    init.gain = 17;      /* Formula: 31 - (1 + (log10(downSamplingRate^filterOrder) / log10(filterOrder))) */
  init.prescaler = 0; /* Formula: (clock_freq / (sample_rate * downSamplingRate)) - 1 */
  init.dsr = DOWNSAMPLINGRATE;
  init.gain = 17;      /* Formula: 31 - (1 + (log10(downSamplingRate^filterOrder) / log10(filterOrder))) */
#endif
  PDM_Init(PDM, &init);
  /* disable all interrupts */
  PDM_IntDisable(PDM, PDM_IEN_DV | PDM_IEN_DVL | PDM_IEN_OF | PDM_IEN_UF);
}

void BAT_PDM_deInit(void){

}

void BAT_PDM_readMicrophone(double *buffer, uint16_t samples){
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

void BAT_PDM_convertPCMTodBSPL(double *buffer, uint16_t samples, double *dBSPL){
  double sample;
  double power;
  double mean;
  uint32_t i;

  // Calculate mean
  mean = 0;
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
 *   Apply A filter (Direct form II transposed) onto data
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
void BAT_PDM_applyAWeightingFilter(double *x, double *y, uint16_t k){
  /* coefficients */
  static double A_a_1_koeff[2] = { -0.140536082420711, 0.00493759761554020};
  static double A_a_2_koeff[2] = { -1.88490121742879,  0.886421471816168};
  static double A_a_3_koeff[2] = { -1.99413888126633,  0.994147469444531};
  static double A_b_1_koeff[3] = { 0.216100378798707, 0.432200757597415, 0.216100378798707};
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

void BAT_PDM_convertSPLToString(double dBSPL, char* str){
  /* floating-point support for printf needs to be enabled for this to work
   * Main folder ->  Properties -> C/C++ Build -> Settings -> GNU ARM C Linker -> General -> Printf float*/
  /* convert float to str */
  snprintf(str, 6, "%.2f", dBSPL);
}
