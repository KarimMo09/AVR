/*
 * main.c
 *
 *  Created on: Jul 5, 2022
 *      Author: Karim
 */


#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/GIE/GIE_int.h"
#include "../MCAL/ADC/ADC_int.h"
#include "../MCAL/TIMERS/TIMERS_int.h"
#include "util/delay.h"
volatile u8 Reading_flag=0;
volatile u16 PT;
volatile u16 ONT;


void timer1_CTC_B_isr(void)
{
	MDIO_vTogPinVal(DIO_PORTA,DIO_PIN1);

}
void timer1_CTC_A_isr(void)
{
	MDIO_vTogPinVal(DIO_PORTA,DIO_PIN0);

}
void ICU_ISR(void)
{
	static u8 counter=0;
	static u16 TimerReading[3];
	counter++;
	switch(counter)
	{

	case 1:TimerReading[counter-1]=MTIMERS_u16GetCapturedValue();
			break;
	case 2:TimerReading[counter-1]=MTIMERS_u16GetCapturedValue();
	   MTIMERS_vSetIcuTrigger(ICU_Falling);
	   PT=TimerReading[1]-TimerReading[0];
			break;
	case 3:TimerReading[counter-1]=MTIMERS_u16GetCapturedValue();
	   MTIMERS_vSetIcuTrigger(ICU_Raising);
	   MTIMERS_DisableIntterupts(TIMER1);
	   ONT=TimerReading[2]-TimerReading[1];
	   counter=0;
	   Reading_flag=1;
			break;
	}

}

int main(void)
{
	MTIMERS_vInit();
	MDIO_vSetPinDir(DIO_PORTD,OC1A,DIO_OUTPUT);
	MDIO_vSetPinDir(DIO_PORTD,OC1B,DIO_OUTPUT);
	MTIMERS_vSetCompareValueTIM1(CHANNEL_A,312);
	MTIMERS_vSetCompareValueTIM1(CHANNEL_B,62);
	MTIMERS_vStartTimer(TIMER1);
	while(1)
	{

	}
}


