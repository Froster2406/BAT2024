/*
 * BAT_LETIMER.h
 *
 *  Created on: 02.04.2024
 *      Author: FrosterOTG
 */

#ifndef CUSTOM_BAT_LETIMER_H_
#define CUSTOM_BAT_LETIMER_H_

#include "em_letimer.h"
#include "em_rtcc.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_chip.h"
#include "em_gpio.h"
#include "em_core.h"

#include "BAT_DEFINES.h"
#include "BAT_RTC.h"
#include "BAT_SPI.h"
#include "BAT_I2C.h"
#include "BAT_PDM.h"
#include "BAT_GPIO.h"

void BAT_TIMER_init(void);

void BAT_TIMER_deInit(void);

#endif /* CUSTOM_BAT_LETIMER_H_ */
