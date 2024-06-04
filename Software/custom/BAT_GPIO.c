/*
 * BAT_GPIO.c
 *
 *  Created on: 02.04.2024
 *      Author: Stefano Nicora
 */

#include "BAT_GPIO.h"

/***************************************************************************//**
 * @brief
 *   Initialize the GPIO peripheral
 *
 ******************************************************************************/
void BAT_GPIO_init(void){
  // Enable GPIO clock
  CMU_ClockEnable(cmuClock_GPIO, true);

  /* Configure GPIO pin 2 on port D as input */
  /* used to check if device is charging */
  GPIO_PinModeSet(BAT_CHARGING_PORT, BAT_CHARGING_PIN, gpioModeInput, 0);
}

/***************************************************************************//**
 * @brief
 *   Check the status of the charge pin
 *
 * @param[out] bool
 *   returns true if a usb-power connection is enabled
 *
 ******************************************************************************/
bool BAT_GPIO_getChargeStatus(void){
  return GPIO_PinInGet(BAT_CHARGING_PORT, BAT_CHARGING_PIN);
}
