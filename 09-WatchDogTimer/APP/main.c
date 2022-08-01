/*
 * main.c
 *
 *  Created on: Jul 5, 2022
 *      Author: Karim
 */


#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/GIE/GIE_int.h"
#include "../MCAL/WDT/WDT_int.h"
#include <util/delay.h>

int main(void)
{
	MDIO_vSetPinDir(DIO_PORTB,DIO_PIN0,DIO_OUTPUT);

	MWDT_vTrunOn(WDT_1s);

	MDIO_vSetPinVal(DIO_PORTB,DIO_PIN0,DIO_HIGH);
	_delay_ms(500);
	MDIO_vSetPinVal(DIO_PORTB,DIO_PIN0,DIO_LOW);
	MWDT_vTrunOff();
	while(1)
	{

	}
}


