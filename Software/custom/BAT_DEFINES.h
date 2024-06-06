/*
 * BAT_DEFINES.h
 *
 *  Created on: 17.03.2024
 *      Author: Stefano Nicora
 */

#ifndef CUSTOM_BAT_DEFINES_H_
#define CUSTOM_BAT_DEFINES_H_

/* GENERAL */
#define BAT_MEASUREMENT_INTERVAL  250  /* [ms] */
#define BAT_CHARGING_PORT   gpioPortD   /* voltage divider to check for charge connection */
#define BAT_CHARGING_PIN    2           /* voltage divider to check for charge connection */
#define BAT_LEN_MEAS_STR    13          /* defines how long one single data-measurement-string is - Format: hh:mm:ss_xxx with xxx = dBSPL-Value */

/* PDM */
#define DOWNSAMPLINGRATE    64
#define BAT_MIC_CLK_PORT    gpioPortA
#define BAT_MIC_CLK_PIN     0
#define BAT_MIC_DATA_PORT   gpioPortB
#define BAT_MIC_DATA_PIN    0
#define BUFFERSIZE          128

/* VISIUAL REPRESENTATION */
#define LED_THRESHOLD_1 76 /* in dB */
#define LED_THRESHOLD_2 79 /* in dB */
#define LED_THRESHOLD_3 82 /* in dB */
#define LED_THRESHOLD_4 85 /* in dB */
#define LED_THRESHOLD_5 88 /* in dB */
#define LED_THRESHOLD_6 91 /* in dB */
#define LED_THRESHOLD_7 94 /* in dB */
#define LED_THRESHOLD_8 97 /* in dB */

/* SPI */
#define BAT_SPI_MISO_PORT gpioPortC
#define BAT_SPI_MISO_PIN  0
#define BAT_SPI_MOSI_PORT gpioPortC
#define BAT_SPI_MOSI_PIN  1
#define BAT_SPI_CS_PORT   gpioPortC
#define BAT_SPI_CS_PIN    2
#define BAT_SPI_CLK_PORT  gpioPortC
#define BAT_SPI_CLK_PIN   3

/* I2C */
#define BAT_I2C_SCL_PORT    gpioPortC
#define BAT_I2C_SCL_PIN     7
#define BAT_I2C_SDA_PORT    gpioPortC
#define BAT_I2C_SDA_PIN     6
#define BAT_I2C_ENABLE_PORT gpioPortA
#define BAT_I2C_ENABLE_PIN  4

#endif /* CUSTOM_BAT_DEFINES_H_ */
