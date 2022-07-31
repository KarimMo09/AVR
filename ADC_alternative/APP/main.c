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

/*4 - alternative method using callback()*/
/*void adc_isr(void)
{
    adc_value=adc_value*500.0/1024;
}
int main(void)
{

	MADC_vInit();
	HLCD_vInit();
	MGIE_vEnableGlobalInterrupt();
	MADC_vStartADCConversion_Asynch(CHANNEL0, &adc_value,adc_isr);

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
}*/

/*5- alternative method using callback(adc data)*/
void adc_isr(u16 A_u16ADC_Data)
{
    adc_value=A_u16ADC_Data*500.0/1024;

}
int main(void)
{

	MADC_vInit();
	HLCD_vInit();
	MGIE_vEnableGlobalInterrupt();
	MADC_vStartADCConversion_Asynch(CHANNEL0, &adc_value,adc_isr);


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

