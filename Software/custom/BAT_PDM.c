/*
 * BAT_PDM.c
 *
 *  Created on: 16.03.2024
 *      Author: FrosterOTG
 */

#include "BAT_PDM.h"
#include "em_pdm.h"
#include "em_cmu.h"

#include "sl_mic.h"

void BAT_PDM_init(void){
//  PDM_Init_TypeDef     pdmInit = PDM_INIT_DEFAULT;
//  CMU_DPLLInit_TypeDef pllInit = CMU_DPLL_LFXO_TO_40MHZ;
//
//  CMU_OscillatorEnable(cmuOsc_LFXO, true, true);
//  // Lock PLL to 1,411,209 Hz to achieve 44,100 kHz PCM sampling rate
//  // when using 32x PDM oversampling
//  pllInit.frequency = 1411209;
//  pllInit.m = 14;
//  pllInit.n = 645;
//  CMU_DPLLLock(&pllInit);
//
//  // Setup all GPIO's.
//  GPIO_PinModeSet(MIC_CLK_PORT, MIC_CLK_PIN, gpioModePushPull, 0);
//  GPIO_PinModeSet(MIC_DATA_PORT, MIC_DATA_PIN, gpioModeInput, 0);
//
//  // Set fast slew rate on PDM mic CLK and DATA pins
//  GPIO_SlewrateSet(MIC_CLK_PORT, 7U, 7U);
//
//  // Enable PDM peripheral clock.
//  CMU_ClockEnable(cmuClock_PDM, true);
//  // Select PDM reference clock source and enable it.
//  CMU_ClockSelectSet(cmuClock_PDMREF, cmuSelect_HFRCO);
//  CMU_ClockEnable(cmuClock_PDMREF, true);
//
//  // Route PDM signals to correct GPIO's.
//  PDM->ROUTELOC0 = (PDM->ROUTELOC0 & ~_PDM_ROUTELOC0_DAT0LOC_MASK)
//                   | (MIC_DATA_PDM_LOC << _PDM_ROUTELOC0_DAT0LOC_SHIFT);
//  PDM->ROUTELOC1 = MIC_CLK_PDM_LOC << _PDM_ROUTELOC1_CLKLOC_SHIFT;
//  PDM->ROUTEPEN |= PDM_ROUTEPEN_CLKPEN | PDM_ROUTEPEN_DAT0PEN;
}

void BAT_PDM_deInit(void){

}

