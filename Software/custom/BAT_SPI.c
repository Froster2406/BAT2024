/*
 * BAT_SPI.c
 *
 *  Created on: 16.03.2024
 *      Author: FrosterOTG
 */

#include "BAT_SPI.h"

static SPIDRV_HandleData_t handleData;
static SPIDRV_Handle_t handle = &handleData;
static uint8_t pageWriteCounter = 0; /* keeps track how many pages of data have already been written */
static uint8_t pageReadCounter = 0; /* keeps track how many pages of data have already been written */
static char data[516] = {0};

void TransferComplete(SPIDRV_Handle_t handle, Ecode_t transferStatus, int itemsTransferred)
{
  if (transferStatus == ECODE_EMDRV_SPIDRV_OK) {
   // Success !
  }
}

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
  //SPIDRV_MTransferB(handle, dataOut, dataIn, 4);
  SPIDRV_MTransfer(handle, dataOut, dataIn, 4, TransferComplete);
  if (dataIn[1] == BAT_SPI_JEDEC_MANUFACTURER && dataIn[2] == BAT_SPI_JEDEC_SPI_FAMILY && dataIn[3] == BAT_SPI_JEDEC_MEMORY_DENSITY){
      return true;
  } else {
      return false;
  }
}

/* write a page (512 bytes) of data  */
void BAT_SPI_writePage(char *dataToBeStored){
  /* concatinate dataToBeStored with command to write a page as well as starting address */
  memset(data, 0, 516);
  data[0] = BAT_SPI_PGWR;
  uint32_t registerAddress = pageWriteCounter * 512;
  data[1] = (registerAddress >> 16) & 0xFF;
  data[2] = (registerAddress >> 8)  & 0xFF;
  data[3] =  registerAddress        & 0xFF;
  memcpy(data + 4, dataToBeStored, 512);
  SPIDRV_MTransmit(handle, data, 512 + 1 + 3, TransferComplete); /* + 1 to accommodate the command byte, + 3 to accommodate 24 bit address */
  pageWriteCounter++;
}


/* read a page (512 bytes) of data into RAM */
void BAT_SPI_readPage(char *dataToBeRetrieved){
  memset(data, 0, 516);
  data[0] = BAT_SPI_PGWR;
  uint32_t registerAddress = pageReadCounter * 512;
  data[1] = (registerAddress >> 16) & 0xFF;
  data[2] = (registerAddress >> 8)  & 0xFF;
  data[3] =  registerAddress        & 0xFF;
  uint8_t cmd[1] = {BAT_SPI_READ};
  SPIDRV_MTransfer(handle, data, dataToBeRetrieved, 512 + 1 + 3, TransferComplete); /* + 1 to accommodate the command byte, + 3 to accommodate 24 bit address */
  pageReadCounter++;
}
