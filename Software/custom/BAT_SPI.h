/*
 * BAT_SPI.h
 *
 *  Created on: 16.03.2024
 *      Author: FrosterOTG
 */

#ifndef CUSTOM_BAT_SPI_H_
#define CUSTOM_BAT_SPI_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "spidrv.h"

#define BAT_SPI_WREN    0x06 /* Write enable */
#define BAT_SPI_WRDI    0x04 /* Write disable */
#define BAT_SPI_RDSR    0x05 /* Read Status register */
#define BAT_SPI_RDCR    0x15 /* Read Configuration and Safety registers */
#define BAT_SPI_CLRSF   0x50 /* Clear Safety register */
#define BAT_SPI_RDVR    0x85 /* Read Volatile register */
#define BAT_SPI_WRVR    0x81 /* Write Volatile register */
#define BAT_SPI_WRSR    0x01 /* Write Status and Configuration registers */
#define BAT_SPI_READ    0x03 /* Read data single output */
#define BAT_SPI_CHER    0xC7 /* Chip erase */
#define BAT_SPI_BKER    0xD8 /* Block erase   (64 KBytes)*/
#define BAT_SPI_SCER    0x20 /* Sector erase  ( 4 Kbytes)*/
#define BAT_SPI_PGER    0xDB /* Page erase    (512 bytes)*/
#define BAT_SPI_PGPR    0x0A /* Page program (with buffer load, if BUFEN = 1) */
#define BAT_SPI_PGWR    0x02 /* Page write */
#define BAT_SPI_RDID    0x83 /* Read identification */
#define BAT_SPI_FRDID   0x8B /* Fast read identification */
#define BAT_SPI_DPD     0xB9 /* Deep power-down enter */
#define BAT_SPI_RDPD    0xAB /* Deep power-down release */
#define BAT_SPI_WRID    0x82 /* Write identification page */
#define BAT_SPI_JDID    0x9F /* JEDEC identification */
#define BAT_SPI_RDCR    0x15 /* Read configuration and safety register */
#define BAT_SPI_RDVR    0x85 /* Read Volatile register */
#define BAT_SPI_WRVR    0x81 /* Write Volatile register */
#define BAT_SPI_CLRSF   0x50 /* Clear safety sticky flags */
#define BAT_SPI_RDSFDP  0x5A /* Read SFDP */
#define BAT_SPI_RSTEN   0x66 /* Enable reset */
#define BAT_SPI_RESET   0x99 /* Software reset */

#define BAT_SPI_JEDEC_MANUFACTURER    0x20
#define BAT_SPI_JEDEC_SPI_FAMILY      0x00
#define BAT_SPI_JEDEC_MEMORY_DENSITY  0x15

void BAT_SPI_init(void);

void BAT_SPI_writePage(char *dataToBeStored);

bool BAT_SPI_eepromIsAvailable(void);

#endif /* CUSTOM_BAT_SPI_H_ */
