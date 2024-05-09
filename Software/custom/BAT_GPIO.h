/*
 * BAT_GPIO.h
 *
 *  Created on: 02.04.2024
 *      Author: FrosterOTG
 */

#ifndef CUSTOM_BAT_GPIO_H_
#define CUSTOM_BAT_GPIO_H_

#include <stdbool.h>

#include "em_gpio.h"
#include "em_cmu.h"
#include "em_chip.h"

#include "BAT_DEFINES.h"

void BAT_GPIO_init(void);

#endif /* CUSTOM_BAT_GPIO_H_ */
