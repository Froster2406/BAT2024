/*
 * BAT_RTC.h
 *
 *  Created on: 16.03.2024
 *      Author: FrosterOTG
 */

#ifndef CUSTOM_BAT_RTC_H_
#define CUSTOM_BAT_RTC_H_

#include <stdbool.h>
#include "em_rtcc.h"
#include "em_cmu.h"

void BAT_RTC_init(void);
void BAT_RTC_deInit(void);

#endif /* CUSTOM_BAT_RTC_H_ */
