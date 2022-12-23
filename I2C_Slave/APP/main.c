/*
 * main.c
 *
 *  Created on: Jul 5, 2022
 *      Author: Karim
 */


#include "../LIB/STD_TYPES.h"
#include "../LIB/Bit_math.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/TWI/TWI_int.h"

#include "../MCAL/GIE/GIE_int.h"
#include "../HAL/LCD/LCD_int.h"
#include <util/delay.h>

u8 x;
int main(void)
{
	MDIO_vSetPinDir(DIO_PORTD,DIO_PIN2,DIO_OUTPUT);
	MTWI_vInit();

	MTWI_u8RecieveByte(&x,1);
	if(x=='A')
	MDIO_vSetPinVal(DIO_PORTD,DIO_PIN2,DIO_HIGH);

	while(1)
	{


	}
}


