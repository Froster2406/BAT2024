/*
 * BAT_I2C.h
 *
 *  Created on: 16.03.2024
 *      Author: Stefano Nicora
 */

#ifndef CUSTOM_BAT_I2C_H_
#define CUSTOM_BAT_I2C_H_

#include "em_i2c.h"
#include "em_device.h"
#include "em_gpio.h"
#include "em_cmu.h"
#include "sl_udelay.h"
#include "BAT_DEFINES.h"

#define BAT_I2C_ADDR  0x32 /* Configured via ASEL0 and ASEL1 pins */

#define BAT_I2C_ENABLE                        0x0
#define BAT_I2C_ENGINE_CNTRL2                 0x01
#define BAT_I2C_OUTPUT_DIRECT_RATIOMETRIC_MSB 0x02  /* Enables ratiometric dimming for D9 output */
#define BAT_I2C_OUTPUT_DIRECT_RATIOMETRIC_LSB 0X03  /* Enables ratiometric dimming for D1 ... D8 output */
#define BAT_I2C_OUTPUT_ON_OFF_CONTROL_MSB     0X04  /* ON/OFF Control for D9 output */
#define BAT_I2C_OUTPUT_ON_OFF_CONTROL_LSB     0X05  /* ON/OFF Control for D1 ... D8 output */
#define BAT_I2C_D1_CONTROL                    0x06
#define BAT_I2C_D2_CONTROL                    0x07
#define BAT_I2C_D3_CONTROL                    0x08
#define BAT_I2C_D4_CONTROL                    0x09
#define BAT_I2C_D5_CONTROL                    0x0A
#define BAT_I2C_D6_CONTROL                    0x0B
#define BAT_I2C_D7_CONTROL                    0x0C
#define BAT_I2C_D8_CONTROL                    0x0D
#define BAT_I2C_D9_CONTROL                    0x0E
#define BAT_I2C_D1_PWM                        0x16  /* PWM duty cycle control for Dn */
#define BAT_I2C_D2_PWM                        0x17  /* PWM duty cycle control for Dn */
#define BAT_I2C_D3_PWM                        0x18  /* PWM duty cycle control for Dn */
#define BAT_I2C_D4_PWM                        0x19  /* PWM duty cycle control for Dn */
#define BAT_I2C_D5_PWM                        0x1A  /* PWM duty cycle control for Dn */
#define BAT_I2C_D6_PWM                        0x1B  /* PWM duty cycle control for Dn */
#define BAT_I2C_D7_PWM                        0x1C  /* PWM duty cycle control for Dn */
#define BAT_I2C_D8_PWM                        0x1D  /* PWM duty cycle control for Dn */
#define BAT_I2C_D9_PWM                        0x1E  /* PWM duty cycle control for Dn */
#define BAT_I2C_D1_CURRENT_CONTROL            0x26  /* Dn output current control register. Default 17.5 mA */
#define BAT_I2C_D2_CURRENT_CONTROL            0x27  /* Dn output current control register. Default 17.5 mA */
#define BAT_I2C_D3_CURRENT_CONTROL            0x28  /* Dn output current control register. Default 17.5 mA */
#define BAT_I2C_D4_CURRENT_CONTROL            0x29  /* Dn output current control register. Default 17.5 mA */
#define BAT_I2C_D5_CURRENT_CONTROL            0x2A  /* Dn output current control register. Default 17.5 mA */
#define BAT_I2C_D6_CURRENT_CONTROL            0x2B  /* Dn output current control register. Default 17.5 mA */
#define BAT_I2C_D7_CURRENT_CONTROL            0x2C  /* Dn output current control register. Default 17.5 mA */
#define BAT_I2C_D8_CURRENT_CONTROL            0x2D  /* Dn output current control register. Default 17.5 mA */
#define BAT_I2C_D9_CURRENT_CONTROL            0x2E  /* Dn output current control register. Default 17.5 mA */
#define BAT_I2C_MISC                          0x36
#define BAT_I2C_STATUS_INTERRUPT              0x3A
#define BAT_I2C_INT_GPO                       0x3B
#define BAT_I2C_RESET                         0x3D  /* Writing 11111111 into this register resets the LP55231 */
#define BAT_I2C_TEMP_ADC_CONTROL              0x3E
#define BAT_I2C_TEMPERATURE_READ              0x3F  /* Bits for temperature information */
#define BAT_I2C_TEMPERATURE_WRITE             0x40  /* Bits for temperature information */
#define BAT_I2C_GAIN_CHANGE_CTRL              0x76

void BAT_I2C_init(void);

void BAT_I2C_deInit(void);

I2C_TransferReturn_TypeDef BAT_I2C_enableLED(uint8_t ledNumber);

I2C_TransferReturn_TypeDef BAT_I2C_disableLED(uint8_t ledNumber);

I2C_TransferReturn_TypeDef BAT_I2C_enableLedRange(uint8_t range);

uint8_t BAT_I2C_readTemperature(void);

#endif /* CUSTOM_BAT_I2C_H_ */
