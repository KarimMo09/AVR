/*
 * main.c
 *
 *  Created on: Jul 5, 2022
 *      Author: Karim
 */


#include "../LIB/STD_TYPES.h"
#include "../LIB/Bit_math.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/SPI/SPI_int.h"
#include "../MCAL/SPI/SPI_prv.h"
#include "../MCAL/GIE/GIE_int.h"
#include "../HAL/LCD/LCD_int.h"
#include <util/delay.h>


char x[100];

volatile u8 i=0;
void ISR(u8 data)
{
		x[i]=data;
		i++;
}

int main(void)
{
	HLCD_vInit();
	MSPI_vInit();
	MGIE_vEnableGlobalInterrupt();
	MSPI_vSetCallback(ISR);


	while(1)
	{
		if(x[i]=='\0')
		{
			HLCD_vPrintString(x);
			x[i]='\r';
		}


	}
}


