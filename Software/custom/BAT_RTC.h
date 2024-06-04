/*
 * BAT_RTC.h
 *
 *  Created on: 16.03.2024
 *      Author: Stefano Nicora
 */

#ifndef CUSTOM_BAT_RTC_H_
#define CUSTOM_BAT_RTC_H_

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "em_rtcc.h"
#include "em_cmu.h"
#include "sl_sleeptimer.h"
#include "BAT_DEFINES.h"

void BAT_RTC_init(void);

void BAT_RTC_deInit(void);

uint32_t BAT_RTC_getTime(void);

void BAT_RTC_convertTimeToString(uint32_t time, char* str);

#endif /* CUSTOM_BAT_RTC_H_ */
