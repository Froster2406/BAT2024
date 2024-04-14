/*
 * BAT_PDM.h
 *
 *  Created on: 16.03.2024
 *      Author: FrosterOTG
 */

#ifndef BAT_PDM_H_
#define BAT_PDM_H_

#include <stdint.h>
#include <string.h>
#include "BAT_DEFINES.h"
#include "em_pdm.h"
#include "em_cmu.h"

#include "sl_mic.h"

void BAT_PDM_init(void);

void BAT_PDM_deInit(void);

void BAT_PDM_readMicrophone(void);

typedef enum
{
    A_Weighting,
    C_Weighting,
    z_Weighting
} weighting;

#endif /* BAT_PDM_H_ */
