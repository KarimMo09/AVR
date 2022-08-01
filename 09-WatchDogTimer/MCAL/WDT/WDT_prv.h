/*
 * WDT_prv.h
 *
 *  Created on: Jul 31, 2022
 *      Author: Karim
 */

#ifndef MCAL_WDT_WDT_PRV_H_
#define MCAL_WDT_WDT_PRV_H_

#define WDT_CLR_PSC_BITS          0xF8
#define WDT_DISABLE_ROUTINE      ((1<<WDTOE)|(1<<WDE))

#define WDTCR            (*(volatile u8*)(0x41))

#define WDP0 		     0
#define WDP1			 1
#define WDP2			 2
#define WDE			  	 3
#define WDTOE			 4



#endif /* MCAL_WDT_WDT_PRV_H_ */
