/*
 * mmain.c
 *
 *  Created on: May 17, 2022
 *      Author: Karim
 */

#include "../LIB/STD_TYPES.h"
#include "../MCAL/EXTI/EXTI_int.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/GIE/GIE_int.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int main ()
{
	MDIO_vSetPinDir (DIO_PORTD, DIO_PIN2 , DIO_INPUT);
	MDIO_vSetPinDir(DIO_PORTA, DIO_PIN0 , DIO_OUTPUT);
	MGIE_vEnableGlobalInterrupt();

	MEXTI_vInit();

	while(1)
	{

	}
}


ISR(INT0_vect)
{
   MDIO_vTogPinVal (DIO_PORTA, DIO_PIN0);
   _delay_ms(1000);
}
