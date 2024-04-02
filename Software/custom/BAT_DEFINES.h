/*
 * BAT_DEFINES.h
 *
 *  Created on: 17.03.2024
 *      Author: FrosterOTG
 */

#ifndef CUSTOM_BAT_DEFINES_H_
#define CUSTOM_BAT_DEFINES_H_

/* GENERAL */
#define BAT_MEASUREMENT_INTERVAL  1000  /* [ms] */
#define BAT_CHARGING_PORT   gpioPortD   /* voltage divider to check for charge connection */
#define BAT_CHARGING_PIN    2           /* voltage divider to check for charge connection */

/* PDM */
#define BAT_MIC_CLK_PORT    gpioPortA
#define BAT_MIC_CLK_PIN     0
#define BAT_MIC_DATA_PORT   gpioPortB
#define BAT_MIC_DATA_PIN    0

#endif /* CUSTOM_BAT_DEFINES_H_ */
