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

//static uint16_t prescaler;
//static uint32_t clock;

void BAT_RTC_init(void){
  /* calculate constants based on the
   * clock and prescaler defined by the BLE stack */
//  prescaler = RTCC->CFG >> 4;
//  clock = CMU_ClockFreqGet(cmuClock_RTCC);
//
//  switch (prescaler){
//          case 0:   prescaler = 1;      break;
//          case 1:   prescaler = 2;      break;
//          case 2:   prescaler = 4;      break;
//          case 3:   prescaler = 8;      break;
//          case 4:   prescaler = 16;     break;
//          case 5:   prescaler = 32;     break;
//          case 6:   prescaler = 64;     break;
//          case 7:   prescaler = 128;    break;
//          case 8:   prescaler = 256;    break;
//          case 9:   prescaler = 512;    break;
//          case 10:  prescaler = 1024;   break;
//          case 11:  prescaler = 2048;   break;
//          case 12:  prescaler = 4096;   break;
//          case 13:  prescaler = 8192;   break;
//          case 14:  prescaler = 16384;  break;
//          case 15:  prescaler = 32768;  break;
//          default: break; /* invalid prescaler value */
//  }
}

void BAT_RTC_deInit(void){
}

/* returns timestamp in seconds */
uint32_t BAT_RTC_getTime(void){
  return sl_sleeptimer_get_time();
}

void BAT_RTC_convertTimeToString(uint32_t time, char* str){
  uint8_t hours = time / 3600;
  uint8_t minutes = (time % 3600) / 60;
  uint8_t seconds = time % 60;

  /* convert int to str */
  snprintf(str, 9, "%02d:%02d:%02d", hours, minutes, seconds);
}
