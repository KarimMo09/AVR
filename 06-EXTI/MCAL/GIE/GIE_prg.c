/*
 * GIE_prg.c
 *
 *  Created on: Jul 19, 2022
 *      Author: Karim
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include <avr/io.h>

#include "GIE_int.h"

void MGIE_vEnableGlobalInterrupt(void)
{
	SET_BIT(SREG , 7);
}
void MGIE_vDisableGlobalInterrupt(void)
{
	CLR_BIT(SREG , 7);
}
