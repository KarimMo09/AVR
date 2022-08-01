/*
 * GIE_prg.c
 *
 *  Created on: Jun 2, 2022
 *      Author: mazen
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "GIE_int.h"
#include "GIE_cfg.h"
#include "GIE_prv.h"

void MGIE_vEnableGlobalInterrupt(void)
{
	SET_BIT(SREG, Global_Interrupt);
}

void MGIE_vDisableGlobalInterrupt(void)
{
	CLR_BIT(SREG, Global_Interrupt);
}

