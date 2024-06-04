/*
 * BAT_RTC.c
 *
 *  Created on: 16.03.2024
 *      Author: Stefano Nicora
 */

#include "BAT_RTC.h"

/***************************************************************************//**
 * @brief
 *   Initialize RTC peripheral
 *
 ******************************************************************************/
void BAT_RTC_init(void){
}

/***************************************************************************//**
 * @brief
 *   Initialize RTC peripheral
 *
 ******************************************************************************/
void BAT_RTC_deInit(void){
}

/***************************************************************************//**
 * @brief
 *   Get current device time out of RTC
 *
 * @param[out]
 *   Time in seconds
 *
 ******************************************************************************/
uint32_t BAT_RTC_getTime(void){
  return sl_sleeptimer_get_time();
}

/***************************************************************************//**
 * @brief
 *   Convert time in seconds to a string
 *
 * @param[in] time
 *   Time in seconds
 *
 * @param[in] *str
 *   Array to hold time
 *
 ******************************************************************************/
void BAT_RTC_convertTimeToString(uint32_t time, char* str){
  uint8_t hours = time / 3600;
  uint8_t minutes = (time % 3600) / 60;
  uint8_t seconds = time % 60;

  /* convert int to str */
  snprintf(str, 9, "%02d:%02d:%02d", hours, minutes, seconds);
}
