/*
 * BAT_LOGGING.c
 *
 *  Created on: 16.03.2024
 *      Author: Stefano Nicora
 */

#include "BAT_LOGGING.h"

/***************************************************************************//**
 * @brief
 *   Generate a full string that will be stored in memory
 *
 * @param[out] outputStr
 *   Data-array that holds the complete string
 *   Has to able to hold 16 items
 *
 * @param[in] timestamp
 *   Data-array that holds the timestamp as a string
 *
 * @param[in] dBSPL
 *   Data-array that holds the dBSPL value as a string
 *
 ******************************************************************************/
void BAT_LOGGING_generateLogString(char* outputStr, char* timestamp, char *dBSPL){
  outputStr[0] = timestamp[0];
  outputStr[1] = timestamp[1];
  outputStr[2] = timestamp[2];
  outputStr[3] = timestamp[3];
  outputStr[4] = timestamp[4];
  outputStr[5] = timestamp[5];
  outputStr[6] = timestamp[6];
  outputStr[7] = timestamp[7];
  outputStr[8] = '_';
  outputStr[9] = dBSPL[0];
  outputStr[10] = dBSPL[1];
  outputStr[11] = dBSPL[2];
  outputStr[12] = dBSPL[3];
  outputStr[13] = dBSPL[4];
  outputStr[14] = dBSPL[5];
  outputStr[15] = '\0';
}
