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

void EEPROM_vWriteByte(u8 A_u8Byte ,u16 A_u16Address )
{
	MTWI_u8SendStartCondition();

	MTWI_u8SendSlaveAddressRW(0b1010000,TWI_WRITE);

	MTWI_u8SendByte((u8) A_u16Address);
	MTWI_u8SendByte(A_u8Byte);
	MTWI_u8SendStopCondition();

}
u8 EEPROM_vReadByte(u16 A_u16Address)
{
	u8 Byte=0;
	MTWI_u8SendStartCondition();
	MTWI_u8SendSlaveAddressRW(0b1010000,TWI_WRITE);
	MTWI_u8SendByte((u8) A_u16Address);
	MTWI_u8SendStartCondition();
	MTWI_u8SendSlaveAddressRW(0b1010000,TWI_READ);
	MTWI_u8RecieveByte(&Byte,TWI_NOT_ACK);
	MTWI_u8SendStopCondition();
	return Byte;
}





int main(void)
{
	/*
	MTWI_vInit();
	MTWI_u8SendStartCondition();
	MTWI_u8SendSlaveAddressRW(0b00011010,0);
	MTWI_u8SendByte('A');
	MTWI_u8SendStopCondition();
   */
	u8 c=0;
	MDIO_vSetPinDir(DIO_PORTD,DIO_PIN0,DIO_OUTPUT);
	MTWI_vInit();
	/*MTWI_u8SendStartCondition();
	MTWI_u8SendSlaveAddressRW(0b00011010,0);
	MTWI_u8SendByte('A');
	MTWI_u8SendStopCondition();*/

	EEPROM_vWriteByte('K',5);
	_delay_ms(10);
	c=EEPROM_vReadByte(5);
	if (c=='K')
	MDIO_vSetPinVal(DIO_PORTD,DIO_PIN0,DIO_HIGH);

	while(1)
	{


	}
}


