/*
 * BAT_LETIMER.c
 *
 *  Created on: 02.04.2024
 *      Author: FrosterOTG
 */

#include "BAT_LETIMER.h"

static uint32_t time;
static uint8_t dBSPL;
static char timestamp[9]; /* holds string in format hh:mm:ss */
static char dBSPLstr[3];  /* holds dB SPL value in string format */

void BAT_TIMER_init(void){
  /* Enable clock for LETIMER0 */
  CMU_ClockEnable(cmuClock_LETIMER0, true);

  /* calculate overflow value based on current clock value */
  uint16_t clock = CMU_ClockFreqGet(cmuClock_LETIMER0);
  uint32_t overflowValue = clock * BAT_MEASUREMENT_INTERVAL / 1000;

  /* Initialize LETIMER */
  LETIMER_Init_TypeDef letimerInit = LETIMER_INIT_DEFAULT;
  letimerInit.comp0Top = true;          /* Set COMP0 to generate an interrupt on overflow */
  letimerInit.topValue = overflowValue; /* Set the top value to the maximum to count upwards */
  LETIMER_Init(LETIMER0, &letimerInit);

  /* Set COMP0 to trigger an interrupt every BAT_MEASUREMENT_INTERVAL */
  LETIMER_CompareSet(LETIMER0, 0, overflowValue);

  /* Enable COMP0 interrupt */
  LETIMER_IntEnable(LETIMER0, LETIMER_IF_COMP0);
  NVIC_EnableIRQ(LETIMER0_IRQn);
}

void BAT_TIMER_deInit(void){

}

void LETIMER0_IRQHandler(void)
{
 /* Clear the interrupt flag */
 LETIMER_IntClear(LETIMER0, LETIMER_IF_COMP0);
 /* is device charging? YES: Enable BLE and transmit Data | NO: log data to memory */
 if(GPIO_PinInGet(BAT_CHARGING_PORT, BAT_CHARGING_PIN)){ /* device is charging; transmit data */
//     BAT_SPI_readPage();
 } else{  /* log data */
     /* read microphone */
//     BAT_PDM_readMicrophone();
     /* read RTC */
     time = BAT_RTC_getTime();
     BAT_RTC_convertTimeToString(time, timestamp);
     /* apply filtering */
//     dBSPL = BAT_PDM_applyWeightingFilter();
     /* enable LEDs */
     BAT_I2C_enableLedRange(dBSPL);
     /* store Data in memory if enough data is available */
//     BAT_SPI_writePage();
//     EMU_EnterEM1(); // Enter energy mode 1 to save power
 }
}
