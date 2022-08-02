/*
 * ADC_int.h
 *
 *  Created on: Jul 22, 2022
 *      Author: Karim
 */


#ifndef MCAL_ADC_INT_H_
#define MCAL_ADC_INT_H_
#include "../DIO/DIO_INT.h"

#define CHANNEL0      0
#define CHANNEL1      1
#define CHANNEL2      2
#define CHANNEL3      3
#define CHANNEL4      4
#define CHANNEL5      5
#define CHANNEL6      6
#define CHANNEL7      7

typedef enum
{
	ADC_COMPLETE,
	ADC_NOTCOMPLETE
}Flagstatus_t;
void 		 MADC_vInit(void);
u16  		 MADC_u16AnalogRead(u8 A_u8ChannelNo);
/*Interrupt based APIS */
void 		 MADC_vStartConversion(u8 A_u8ChannelNo);
u16 	  	 MADC_u16GetADCData(void);
void 		 MADC_vSetCallback(void (*A_fptr)(void));

Flagstatus_t MADC_xGetFlagStatus(void);
void 		 MADC_vRstFlag(void);
#endif /* MCAL_ADC_CFG_H_ */
