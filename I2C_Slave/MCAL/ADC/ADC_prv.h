  /*
 * ADC_prv.h
 *
 *  Created on: Jul 22, 2022
 *      Author: Karim
 */


#ifndef MCAL_ADC_PRV_H_
#define MCAL_ADC_PRV_H_

#include "../../LIB/STD_TYPES.h"



#define		ADCL		(*(volatile u8 *)0x24)
#define		ADCH		(*(volatile u8 *)0x25)
#define     ADC         (*(volatile u16*)0x24)
#define		ADCSRA		(*(volatile u8 *)0x26)
#define		ADMUX		(*(volatile u8 *)0x27)
#define 	SFIOR       (*(volatile u8 *)0x50)

#define		ADC_CLR_PRESC_BITS    0xF8
#define	    ADC_CLR_CH_SEL_BITS   0xE0
#define     NUM_OF_CHANNEL        0x07

#define ENABLE		1
#define DISABLE		0


#define AVCC			1
#define INTERNAL_REF	2
#define AREF			3

#define ADC_PS_2		0b001
#define ADC_PS_4		0b010
#define ADC_PS_8		0b011
#define ADC_PS_16		0b100
#define ADC_PS_32		0b101
#define ADC_PS_64		0b110
#define ADC_PS_128		0b111

/*     ADMUX BITS    */
#define		MUX0	0
#define		MUX1	1
#define		MUX2	2
#define		MUX3	3
#define		MUX4	4
#define		ADLAR   5
#define		REFS0   6
#define		REFS1	7
/********************/

/*   ADCSRA BITS    */
#define		ADPS0   0
#define		ADPS1   1
#define		ADPS2   2
#define		ADIE    3
#define     ADIF    4
#define		ADATE   5
#define		ADSC	6
#define		ADEN    7
/********************/

/*    SFIOR BITS    */
#define		ADTS0   5
#define		ADTS1   6
#define		ADTS2   7
/**********************/


#endif /* MCAL_ADC_CFG_H_ */
