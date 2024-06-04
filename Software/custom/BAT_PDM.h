/*
 * BAT_PDM.h
 *
 *  Created on: 16.03.2024
 *      Author: Stefano Nicora
 */

#ifndef BAT_PDM_H_
#define BAT_PDM_H_

#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include "BAT_DEFINES.h"
#include "em_pdm.h"
#include "em_cmu.h"
#include "sl_udelay.h"

void BAT_PDM_init(void);

void BAT_PDM_deInit(void);

void BAT_PDM_readMicrophone(int32_t *buffer, uint16_t samples);

void BAT_PDM_convertPCMTodBSPL(int32_t *buffer, uint16_t samples, float *dBSPL);

void BAT_PDM_applyAWeightingFilter(int32_t *x, int32_t *y, uint16_t k);

void BAT_PDM_applyCWeightingFilter(int32_t *x, int32_t *y, uint16_t k);

void BAT_PDM_convertSPLToString(double dBSPL, char* str);

#endif /* BAT_PDM_H_ */
