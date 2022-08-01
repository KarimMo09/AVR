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
#include "../MCAL/UART/UART_int.h"
#include <util/delay.h>
#define WDTCR            *((volatile u8*)(0x41))
int main(void)
{
	MUART_vInit();
	MDIO_vSetPinDir(DIO_PORTB,DIO_PIN0,DIO_OUTPUT);
	if(GET_BIT(WDTCR,7))
	{
		MDIO_vTogPinVal(DIO_PORTB,DIO_PIN0);

	}
	MUART_vSendString("KARIM");
	while(1)
	{

	}
}


