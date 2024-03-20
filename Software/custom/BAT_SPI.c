/*
 * BAT_SPI.c
 *
 *  Created on: 16.03.2024
 *      Author: FrosterOTG
 */

#include "BAT_SPI.h"

static SPIDRV_HandleData_t handleData;
static SPIDRV_Handle_t handle = &handleData;

void BAT_SPI_init(void){
  SPIDRV_Init_t initData = SPIDRV_MASTER_DEFAULT;
  initData.clockMode = spidrvClockMode0; /* SPI mode 0: CLKPOL=0, CLKPHA=0 */
  initData.port = USART0;
  initData.portClk = gpioPortC;
  initData.pinRx =  0x0;
  initData.pinTx =  0x1;
  initData.pinCs =  0x2;
  initData.pinClk = 0x3;

  /* Initialize an SPI driver instance. */
  if (SPIDRV_Init(handle, &initData) != ECODE_EMDRV_SPIDRV_OK){
      printf("Could not initialize SPI driver");
  }
}

void BAT_SPI_deInit(void){
  SPIDRV_DeInit(handle);
}

/* check if eeprom is ready to communicate */
bool BAT_SPI_eepromIsAvailable(void){
  /* read JEDEC code for specific EEPROM */
  uint8_t dataOut[1] = { BAT_SPI_JDID };
  uint8_t dataIn[4] = { 0 };
  SPIDRV_MTransferB(handle, dataOut, dataIn, 4);
  if (dataIn[1] == BAT_SPI_JEDEC_MANUFACTURER && dataIn[2] == BAT_SPI_JEDEC_SPI_FAMILY && dataIn[3] == BAT_SPI_JEDEC_MEMORY_DENSITY){
      printf("EEPROM detected");
      return true;
  } else {
      return false;
  }
}

/* write a page (512 bytes) of data  */
void BAT_SPI_writePage(void){

}

/* read a page (512 bytes) of data into RAM */
void BAT_SPI_readPage(void){

}
