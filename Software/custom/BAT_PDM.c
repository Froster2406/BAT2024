/*
 * BAT_PDM.c
 *
 *  Created on: 16.03.2024
 *      Author: FrosterOTG
 */

#include "BAT_PDM.h"
#include "BAT_DEFINES.h"
#include "em_pdm.h"
#include "em_cmu.h"

#include "sl_mic.h"

void BAT_PDM_init(void){
  CMU_DPLLInit_TypeDef pllInit = CMU_DPLL_LFXO_TO_40MHZ;

  CMU_OscillatorEnable(cmuOsc_LFXO, true, true);
  // Lock PLL to 1,411,209 Hz to achieve 44,100 kHz PCM sampling rate
  // when using 32x PDM oversampling
  pllInit.frequency = 1411209;
  pllInit.m = 14;
  pllInit.n = 645;
  CMU_DPLLLock(&pllInit);

  // Setup all GPIO's.
  GPIO_PinModeSet(BAT_MIC_CLK_PORT, BAT_MIC_CLK_PIN, gpioModePushPull, 0);
  GPIO_PinModeSet(BAT_MIC_DATA_PORT, BAT_MIC_DATA_PIN, gpioModeInput, 0);

  // Set fast slew rate on PDM mic CLK and DATA pins
  GPIO_SlewrateSet(BAT_MIC_CLK_PORT, 7U, 7U);

  // Enable PDM peripheral clock.
  CMU_ClockEnable(cmuClock_PDM, true);
  // Select PDM reference clock source and enable it.
  CMU_ClockSelectSet(cmuClock_PDMREF, cmuSelect_FSRCO);
  CMU_ClockEnable(cmuClock_PDMREF, true);

  // Route PDM signals to correct GPIO's.
  GPIO->PDMROUTE.CLKROUTE = (BAT_MIC_CLK_PIN << _GPIO_PDM_CLKROUTE_PIN_SHIFT) | BAT_MIC_CLK_PORT;
  GPIO->PDMROUTE.DAT0ROUTE = (BAT_MIC_DATA_PIN << _GPIO_PDM_DAT0ROUTE_PIN_SHIFT) | BAT_MIC_DATA_PORT;
  GPIO->PDMROUTE.ROUTEEN = 0x1;

  PDM_Init_TypeDef init = PDM_INIT_DEFAULT;
  init.start = false;
  // Right-align the 16-bit sample in FIFO
  init.dataFormat = pdmDataFormatRight16;
  init.enableCh0Ch1Stereo = false;
  init.numChannels = pdmNumberOfChannelsOne;
  PDM_Init(PDM, &init);
  uint32_t pBuffer[100] = { 0 };
  PDM_Clear(PDM);
  PDM_FifoFlush(PDM);
  PDM_Start(PDM);
  for(uint16_t i = 0; i < 100; i++){
      pBuffer[i] = PDM_Rx(PDM);
  }
  pBuffer[0] = 0;
}

void BAT_PDM_deInit(void){

}

void BAT_PDM_readMicrophone(void){

}

/* apply A or C filter onto data
 * returns dBSPL-value */
uint8_t BAT_PDM_applyWeightingFilter(void){

}
