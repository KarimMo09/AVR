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
#include "../HAL/LCD/LCD_int.h"
#include <util/delay.h>

volatile u16 adc_value=0;
volatile u8 adc_flag=0;

/* 1-
void adc_isr(void)
{
    adc_value=MADC_u16GetADCData()*500.0/1024;
    MADC_vStartConversion(0);

}

int main(void)
{

	MADC_vInit();
	HLCD_vInit();
	MGIE_vEnableGlobalInterrupt();
	MADC_vSetCallback(adc_isr);
	MADC_vStartConversion(CHANNEL0);



	while(1)
	{
		//adc_val=MADC_u16AnalogRead(0)*5.0/1024;
		HLCD_vSendCommand(LCD_CLEAR);
		HLCD_vPrintNumber(adc_value);
		_delay_ms(250);
	}
}
2-
void adc_isr(void)
{
    adc_value=MADC_u16GetADCData()*500/1024.0;
    adc_flag=1;

}

int main(void)
{

	MADC_vInit();
	HLCD_vInit();
	MGIE_vEnableGlobalInterrupt();
	MADC_vSetCallback(adc_isr);
	MADC_vStartConversion(CHANNEL0);

	while(1)
	{
		if(adc_flag==1)
		{
			adc_flag=0;
			HLCD_vSendCommand(LCD_CLEAR);
			HLCD_vPrintNumber(adc_value);
			MADC_vStartConversion(CHANNEL0);
			_delay_ms(250);
		}

	}
}




3*/
void adc_isr(void)
{
    adc_value=MADC_u16GetADCData()*500.0/1024;
}

int main(void)
{

	MADC_vInit();
	HLCD_vInit();
	MGIE_vEnableGlobalInterrupt();
	MADC_vSetCallback(adc_isr);
	MADC_vStartConversion(CHANNEL0);

	while(1)
	{
		if(MADC_xGetFlagStatus()==ADC_COMPLETE )
		{
			MADC_vRstFlag();
			HLCD_vSendCommand(LCD_CLEAR);
			HLCD_vPrintNumber(adc_value);
			MADC_vStartConversion(CHANNEL0);
			_delay_ms(250);
		}

	}
}


