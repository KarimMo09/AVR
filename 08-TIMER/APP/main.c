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
#include "../HAL/LCD/LCD_int.h"
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
	   MTIMERS_DisableIntterupts();
	   ONT=TimerReading[2]-TimerReading[1];
	   counter=0;
	   Reading_flag=1;
			break;
	}

}

int main(void)
{
	HLCD_vInit();

	MTIMERS_vSetCallback(ICU_ISR );
	MGIE_vEnableGlobalInterrupt();
	MDIO_vSetPinDir(DIO_PORTB,DIO_PIN3,DIO_OUTPUT);
	/*MDIO_vSetPinDir(DIO_PORTA,DIO_PIN1,DIO_OUTPUT);
	MDIO_vSetPinDir(DIO_PORTD,OC1A,DIO_OUTPUT);
	MDIO_vSetPinDir(DIO_PORTD,OC1B,DIO_OUTPUT);*/
	MTIMERS_vInit();
	MTIMERS_vEnableIntterupts();
	MTIMERS_vSetCompareValue(TIMER0,250);
	MTIMERS_vSetIcuTrigger(ICU_Raising);
	MTIMERS_vStartTimer(TIMER1);
	MTIMERS_vStartTimer(TIMER0);
	//MTIMERS_vSetInterval_TIM1_CTC_Asynch(CHANNEL_A,25,312,timer1_CTC_A_isr);
	//MTIMERS_vSetInterval_TIM1_CTC_Asynch(CHANNEL_B,50,156,timer1_CTC_B_isr);
	//MTIMERS_vStartTimer(TIMER1);

	//MTIMERS_vSetInterval_CTC_Asynch(TIMER1,2000,250,timer0_CTC_isr);

	while(1)
	{
		if(Reading_flag)
		{
			Reading_flag=0;
			//HLCD_vSendCommand(LCD_CLEAR	);
			HLCD_vSetCursorPosition(0,0);
			HLCD_vPrintNumber(ONT);
			HLCD_vSetCursorPosition(1,0);
			HLCD_vPrintNumber(PT);
			MTIMERS_vEnableIntterupts();
			//_delay_ms(250);
		}
	}
}


