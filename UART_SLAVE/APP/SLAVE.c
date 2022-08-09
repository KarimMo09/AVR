/*
 * main.c
 *
 *  Created on: Jul 5, 2022
 *      Author: Karim
 */


#include "../LIB/STD_TYPES.h"
#include "../LIB/Bit_math.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/GIE/GIE_int.h"
#include "../HAL/LCD/LCD_int.h"
#include <util/delay.h>

#include "../MCAL/UART/SUART_int.h"

char x[100];
volatile u8 i=0;
void ISR_RX(u8 A_u8Data)
{
	x[i++]=A_u8Data;
}

int main(void)
{
	MUART_vInit();
	HLCD_vInit();
	MGIE_vEnableGlobalInterrupt();
	MUART_vRX_SetCallback(ISR_RX);
	while(1)
	{
		if(x[i-1]=='\0')
			{
				HLCD_vPrintString(x);
				x[i-1]=1;
			}

	}
}



