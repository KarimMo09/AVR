/** WDT_prg.c
 *
 *  Created on: Jul 31, 2022
 *      Author: Karim
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/Bit_math.h"

#include "WDT_int.h"
#include "WDT_prv.h"
#include "WDT_cfg.h"


void MWDT_vTrunOn(u8 A_u8TimeOut)
{
	SET_BIT(WDTCR,WDE);
	WDTCR= (WDTCR & WDT_CLR_PSC_BITS) |A_u8TimeOut;


}
void MWDT_vTrunOff(void)
{
	WDTCR |= WDT_DISABLE_ROUTINE;
	WDTCR=0x00;
}

