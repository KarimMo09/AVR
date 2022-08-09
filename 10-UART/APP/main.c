/*
 * main.c
 *
 *  Created on: Jul 5, 2022
 *      Author: Karim
 */


#include "../LIB/STD_TYPES.h"
#include "../LIB/Bit_math.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/UART/UART_int.h"
#include "../MCAL/GIE/GIE_int.h"
#include "../HAL/LCD/LCD_int.h"
#include <util/delay.h>
char *x="This string was sent via UART";

void ISR_RX(u8 A_u8Data)
{

}

u8 ISR_UDRE(void)
{
	if(*x=='\0')
	{
		MUART_DisableIntterupts(UDR_EMPTY);
	}
	return *x++;
}

int main(void)
{
	_delay_ms(15);
	//HLCD_vInit();
	MUART_vUDRE_SetCallback(ISR_UDRE);
	MUART_vInit();
	MGIE_vEnableGlobalInterrupt();
	while(1)
	{

	}
}

