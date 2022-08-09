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
char *x="This string was sent via SPI";

u8 ISR(void)
{
	if(*x=='\0')
	{
		MSPI_DisableIntterupt();
	}
    return *x++;

}


int main(void)
{
	MSPI_vInit();
	MGIE_vEnableGlobalInterrupt();
	MSPI_vSetCallback(ISR);
	_delay_ms(20);// Time to LCD in Slave be Initialized
	SPDR=' ';//Start SPI protocol



	while(1)
	{

	}
}


