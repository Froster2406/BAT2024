/*
 * BAT_RTC.c
 *
 *  Created on: 16.03.2024
 *      Author: FrosterOTG
 */

/*
 * channel 1: timekeeping for data logging (does not overflow)
 * channel 2: wake up microcontroller periodically to read and process data
 * */

#include "BAT_RTC.h"

void BAT_RTC_init(void){
  /* follow this pattern: Set CFG->Set EN->Set CTRL->START CMD->adjust CTRL->STOP CMD */
  RTCC_Init_TypeDef rtccInit = RTCC_INIT_DEFAULT;
  rtccInit.enable = false; /* disable rtc to make config */
  RTCC_Init(&rtccInit);
  RTCC_CCChConf_TypeDef rtccInitCompareChannel = RTCC_CH_INIT_COMPARE_DEFAULT;

  /* Setting RTCC clock source to 1kHz ultra low frequency oscillator */
  CMU_ClockSelectSet(cmuClock_RTCCCLK, cmuSelect_ULFRCO);

  /* Enable RTCC bus clock */
  CMU_ClockEnable(cmuClock_RTCC, true);

  /* Configure Channel 1 to increment each second */
  RTCC_CCChConf_TypeDef ch1Conf = RTCC_CH_INIT_COMPARE_DEFAULT;
  ch1Conf.compBase = rtccCntPresc_1; // No prescaler
  ch1Conf.compMatchOutAction = rtccCompMatchOutActionToggle; // Toggle output on match
  RTCC_ChannelInit(1, &ch1Conf);

//  // Configure Channel 2 to overflow every 500ms and generate an interrupt
//  RTCC_CCChConf_TypeDef ch2Conf = RTCC_CH_INIT_COMPARE_DEFAULT;
//  ch2Conf.compBase = rtccCntPresc_1; // No prescaler
//  ch2Conf.compMatchOutAction = rtccCompMatchOutActionSet; // Set output on match
//  RTCC_ChannelInit(2, &ch2Conf);
//
//  // Enable interrupt for Channel 2
//  RTCC_IntEnable(RTCC_IF_CC2);
//  NVIC_EnableIRQ(RTCC_IRQn);

  RTCC_SyncWait();
  /* Start the RTCC */
  RTCC_Enable(true);
}

void BAT_RTC_deInit(void){
  RTCC_Enable(false);
}

/* handle any generated interrupt */
void BAT_RTC_IRQHandler(void)
{
    // Clear the interrupt flag
    RTCC_IntClear(RTCC_IF_CC1);
    // Handle the interrupt, e.g., toggle an LED
}
