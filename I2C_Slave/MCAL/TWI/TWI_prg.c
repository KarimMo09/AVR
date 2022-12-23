/*
 * I2C_prg.h
 *
 *  Created on: Aug 9, 2022
 *      Author: Karim
 */
#include "../../LIB/Bit_math.h"
#include "../../LIB/STD_TYPES.h"
#include "TWI_int.h"
#include "TWI_prv.h"
#include "TWI_cfg.h"

void MTWI_vInit(void)
{
	/*---------Enable TWI---------------------*/
	SET_BIT(TWCR,TWEN);
	/*---------Enable Acknowledge Bit---------*/
	SET_BIT(TWCR,TWEA);
	/*---------Disable Interrupt-------------*/
	CLR_BIT(TWCR,TWIE);
	/*---------Set Prescaler-----------------*/
	CLR_BIT(TWSR,TWPS0);
	CLR_BIT(TWSR,TWPS1);

	/*---------Set Scl=100KHZ---------------------*/
	TWBR=32;
	/*--------Set SLA ---------------------*/
	TWAR=0b00110100;
}

u8 MTWI_u8SendStartCondition(void)
{
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);

	while (!(TWCR & (1<<TWINT)));
	/* Check status code */
	return (TWSR & 0xF8) ;

}

u8 MTWI_u8SendRepeatStartCondition(void)
{
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);

	while (!(TWCR & (1<<TWINT)));
	/* Check status code */
	return (TWSR & 0xF8) ;
}

u8 MTWI_u8SendSlaveAddressRW(u8 A_u8Sla,u8 A_u8RW)
{
	TWDR = ( A_u8Sla << 1 ) | (A_u8RW) ;

	TWCR = (1<<TWINT) | (1<<TWEN);

	while(GET_BIT(TWCR,TWINT)==0); //wait to finish
	/* Check status code */
	return (TWSR & 0xF8) ;
}

u8 MTWI_u8SendByte(u8 A_u8Byte)
{
	TWDR = A_u8Byte ;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while(GET_BIT(TWCR,TWINT)==0); //wait to finish
	/* Check status code */
	return (TWSR & 0xF8) ;

}

u8 MTWI_u8RecieveByte(u8 *A_pu8Byte,u8 A_u8Ack)
{
	switch(A_u8Ack)
	{
	case TWI_ACK:TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
						break;
	case TWI_NOT_ACK:TWCR = (1<<TWINT) | (1<<TWEN);
		                CLR_BIT(TWCR,TWEA);
						break;
	}
	while (!(TWCR & (1<<TWINT)));
	while ((TWSR & 0XF8) != 0x60); // own SLA+W has been received and ACK has been returned
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while(GET_BIT(TWCR,TWINT)==0);
	while ((TWSR & 0XF8) != 0x80);

	*A_pu8Byte=TWDR;
	return (TWSR & 0xF8) ;
}

u8 MTWI_u8SendStopCondition(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
	return (TWSR & 0xF8) ;
}

u8 MTWI_u8GetStatus(void)
{
	return (TWSR & 0xF8) ;
}

void MTWI_vSetBitRate(u32 A_u32BitRate)
{
	TWBR=(F_CPU/(8*A_u32BitRate))-2;

}

void MTWI_vSetSlaveAddress(u8 A_u8OwenSla)
{

}
