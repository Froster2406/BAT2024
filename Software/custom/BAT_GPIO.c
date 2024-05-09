/*
 * BAT_GPIO.c
 *
 *  Created on: 02.04.2024
 *      Author: FrosterOTG
 */

#include "BAT_GPIO.h"

void BAT_GPIO_init(void){
  // Enable GPIO clock
  CMU_ClockEnable(cmuClock_GPIO, true);

  /* Configure GPIO pin 2 on port D as input */
  /* used to check if device is charging */
  GPIO_PinModeSet(BAT_CHARGING_PORT, BAT_CHARGING_PIN, gpioModeInput, 0);
}

/* returns true if charging, false if not */
bool BAT_GPIO_getChargeStatus(void){
  return GPIO_PinInGet(BAT_CHARGING_PORT, BAT_CHARGING_PIN);
}
