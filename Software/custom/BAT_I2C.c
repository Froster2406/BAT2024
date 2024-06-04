/*
 * BAT_I2C.c
 *
 *  Created on: 16.03.2024
 *      Author: Stefano Nicora
 */

#include "BAT_I2C.h"

/***************************************************************************//**
 * @brief
 *   Read data of one register
 *
 * @param[in] reg
 *   Register address you want to read
 *
 * @param[in] *data
 *   Array where read data is stored
 *
 * @param[out]
 *   Errorcode
 *
 ******************************************************************************/
I2C_TransferReturn_TypeDef BAT_I2C_readRegister(uint8_t reg, uint8_t *data){
  uint8_t regAddr = reg;  /* The register address */

  I2C_TransferSeq_TypeDef seq = {
     .addr = BAT_I2C_ADDR<<1,           /* The I2C device address */
     .flags = I2C_FLAG_WRITE_READ,
     .buf[0].data = &regAddr,       /* Address of register you want to write to */
     .buf[0].len = 1,               /* Address-length in bytes */
     .buf[1].data = data,          /* Value(s) that are written to register(s) */
     .buf[1].len = 1,
    };

  I2C_TransferReturn_TypeDef result = I2C_TransferInit(I2C0, &seq);

  // Send data
  while (result == i2cTransferInProgress) {
    result = I2C_Transfer(I2C0);
  }

  if (result != i2cTransferDone) {
    while(1);
  }

  return result;
}

/***************************************************************************//**
 * @brief
 *   Write data to one register
 *
 * @param[in] reg
 *   Register address you want to write to
 *
 * @param[in] cmd
 *   Array where to be written data is stored
 *
 * @param[out]
 *   Errorcode
 *
 ******************************************************************************/
I2C_TransferReturn_TypeDef BAT_I2C_writeRegister(uint8_t reg, uint8_t cmd){
  uint8_t value = cmd;    /* The value to write */
  uint8_t regAddr = reg;  /* The register address */

  I2C_TransferSeq_TypeDef seq = {
     .addr = BAT_I2C_ADDR<<1,          /* The I2C device address */
     .flags = I2C_FLAG_WRITE_WRITE,
     .buf[0].data = &regAddr,         /* Address of register you want to write to */
     .buf[0].len = 1,                 /* Address-length in bytes */
     .buf[1].data = &value,           /* Value(s) that are written to register(s) */
     .buf[1].len = 1,
    };

  I2C_TransferReturn_TypeDef result = I2C_TransferInit(I2C0, &seq);

  // Send data
  while (result == i2cTransferInProgress) {
    result = I2C_Transfer(I2C0);
  }

  if (result != i2cTransferDone) {
    while(1);
  }
  return result;
}

/***************************************************************************//**
 * @brief
 *   Set the general PWM value for all LEDs
 *
 * @param[in] value
 *   PWM value from 0 to 100
 *
 * @param[out]
 *   Errorcode
 *
 ******************************************************************************/
I2C_TransferReturn_TypeDef BAT_I2C_setPwmAll(uint8_t value){
  /* could be made more efficient with auto-addr-increment */
  BAT_I2C_writeRegister(BAT_I2C_D1_PWM, value);
  BAT_I2C_writeRegister(BAT_I2C_D2_PWM, value);
  BAT_I2C_writeRegister(BAT_I2C_D3_PWM, value);
  BAT_I2C_writeRegister(BAT_I2C_D4_PWM, value);
  BAT_I2C_writeRegister(BAT_I2C_D5_PWM, value);
  BAT_I2C_writeRegister(BAT_I2C_D6_PWM, value);
  BAT_I2C_writeRegister(BAT_I2C_D7_PWM, value);
  BAT_I2C_writeRegister(BAT_I2C_D8_PWM, value);
  return BAT_I2C_writeRegister(BAT_I2C_D9_PWM, value);
}

/* enable all LEDs up to a certain point
 * range = 3: LEDs 1,2,3 are turned ON */
/***************************************************************************//**
 * @brief
 *   Enable all LEDs up to a certain point
 *
 * @param[in] range
 *   Defines the range of LEDs that are turned on
 *   range = 3: LEDs 1,2,3 are turned ON
 *
 * @param[out]
 *   Errorcode
 *
 ******************************************************************************/
I2C_TransferReturn_TypeDef BAT_I2C_enableLedRange(uint8_t range){
  /* there are currently only 8 LEDs on the PCB */
  if (range == 0 || range >= 9){
      /* turn off all LEDs */
      return BAT_I2C_writeRegister(BAT_I2C_OUTPUT_ON_OFF_CONTROL_LSB, 0);
  }
  return BAT_I2C_writeRegister(BAT_I2C_OUTPUT_ON_OFF_CONTROL_LSB, 0xFF>>(8-range));
}

/***************************************************************************//**
 * @brief
 *   Set specific LED current
 *
 * @param[in] ledNumber
 *   LED you want to address
 *
 * @param[in] current
 *   Specific current in 100uA steps
 *   1 = 100uA
 *   2 = 200uA
 *
 * @param[out]
 *   Errorcode
 *
 ******************************************************************************/
I2C_TransferReturn_TypeDef BAT_I2C_setLedCurrent(uint8_t ledNumber, uint8_t current){
  /* alternative to use register defines: BAT_I2C_Dn_CURRENT_CONTROL */
  return BAT_I2C_writeRegister(ledNumber + 25, current);
}

/* set current in 100uA steps
 * current: 1 = 100uA
 * current: 2 = 200uA */
/***************************************************************************//**
 * @brief
 *   Set specific current of all LEDs
 *
 * @param[in] current
 *   Specific current in 100uA steps
 *   1 = 100uA
 *   2 = 200uA
 *
 * @param[out]
 *   Errorcode
 *
 ******************************************************************************/
I2C_TransferReturn_TypeDef BAT_I2C_setLedCurrentAll(uint8_t current){
  /* could be made more efficient with auto-addr-increment */
  BAT_I2C_writeRegister(BAT_I2C_D1_CURRENT_CONTROL, current);
  BAT_I2C_writeRegister(BAT_I2C_D2_CURRENT_CONTROL, current);
  BAT_I2C_writeRegister(BAT_I2C_D3_CURRENT_CONTROL, current);
  BAT_I2C_writeRegister(BAT_I2C_D4_CURRENT_CONTROL, current);
  BAT_I2C_writeRegister(BAT_I2C_D5_CURRENT_CONTROL, current);
  BAT_I2C_writeRegister(BAT_I2C_D6_CURRENT_CONTROL, current);
  BAT_I2C_writeRegister(BAT_I2C_D7_CURRENT_CONTROL, current);
  BAT_I2C_writeRegister(BAT_I2C_D8_CURRENT_CONTROL, current);
  return BAT_I2C_writeRegister(BAT_I2C_D9_CURRENT_CONTROL, current);
}

/***************************************************************************//**
 * @brief
 *   Turn on specific LED
 *
 * @param[in] ledNumber
 *   LED you want to address
 *
 * @param[out]
 *   Errorcode
 *
 ******************************************************************************/
I2C_TransferReturn_TypeDef BAT_I2C_enableLED(uint8_t ledNumber){
  return BAT_I2C_writeRegister(BAT_I2C_OUTPUT_ON_OFF_CONTROL_LSB, 1<<(ledNumber-1));
}

/***************************************************************************//**
 * @brief
 *   Turn off specific LED
 *
 * @param[in] ledNumber
 *   LED you want to address
 *
 * @param[out]
 *   Errorcode
 *
 ******************************************************************************/
I2C_TransferReturn_TypeDef BAT_I2C_disableLED(uint8_t ledNumber){
  uint8_t data[1];
  BAT_I2C_readRegister(BAT_I2C_OUTPUT_ON_OFF_CONTROL_LSB, data);
  data[0] = data[0] ^ (1<<(ledNumber-1));
  return BAT_I2C_writeRegister(BAT_I2C_OUTPUT_ON_OFF_CONTROL_LSB, *data);
}

/***************************************************************************//**
 * @brief
 *   Perform short visual LED selftest
 *
 ******************************************************************************/
void BAT_I2C_selftest(void){
  BAT_I2C_enableLedRange(0);
  BAT_I2C_enableLedRange(8);
  BAT_I2C_enableLedRange(0);
}

/***************************************************************************//**
 * @brief
 *   Read temperature of IC
 *
 * @param[out]
 *   Temperature in °C
 *
 ******************************************************************************/
uint8_t BAT_I2C_readTemperature(void){
  uint8_t temp = 0;
  BAT_I2C_readRegister(BAT_I2C_TEMPERATURE_READ, &temp);
  return temp;
}

/***************************************************************************//**
 * @brief
 *   Initialize I2C0 peripheral as well as LED-Driver-IC
 *
 ******************************************************************************/
void BAT_I2C_init(void){
  /* initialize I2C HAL */
  I2C_Init_TypeDef i2cInit = I2C_INIT_DEFAULT;
  I2C_Init(I2C0, &i2cInit);

  /* Set I2C bus frequency */
  I2C_BusFreqSet(I2C0, 0, 100000, i2cClockHLRStandard);

  /* Enable I2C */
  I2C_Enable(I2C0, true);

  /* enable and toggle on GPIO pin to set pin high on IC */
  CMU_ClockEnable(cmuClock_GPIO, true);
  GPIO_PinModeSet(BAT_I2C_ENABLE_PORT, BAT_I2C_ENABLE_PIN, gpioModePushPull, 1);
  GPIO_PinOutSet(BAT_I2C_ENABLE_PORT, BAT_I2C_ENABLE_PIN);

  /* enable chip on register level */
  BAT_I2C_writeRegister(BAT_I2C_ENABLE, 1<<6);

  sl_udelay_wait(500);

  /* set charge pump into bypass mode (1x) & enable internal clock */
  BAT_I2C_writeRegister(BAT_I2C_MISC, 1<<3 | 0b11);

  /* set led current to 100uA */
  BAT_I2C_setLedCurrentAll(1);

  /* set led pwm signal to 100% (0xFF) to achieve max. performance */
  BAT_I2C_setPwmAll(0xFF);

  /* run quick selftest */
  BAT_I2C_selftest();
}

/***************************************************************************//**
 * @brief
 *   Deinitialize I2C0 peripheral
 *
 ******************************************************************************/
void BAT_I2C_deInit(void){
  I2C_Enable(I2C0, false);
}
