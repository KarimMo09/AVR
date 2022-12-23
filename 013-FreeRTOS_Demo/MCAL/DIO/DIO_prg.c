/*
 * DIO_prg.c
 *
 *  Created on: May 17, 2022
 *      Author: Karim
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/Bit_math.h"

#include "DIO_int.h"
#include "DIO_prv.h"
#include "DIO_cfg.h"


void MDIO_vSetPinDir ( u8 A_u8PortNo, u8 A_u8PinNo , u8 A_u8Dir )
{
	if(A_u8Dir==DIO_OUTPUT )
	{
		switch(A_u8PortNo)
		{
		case DIO_PORTA:
			 SET_BIT(DDRA, A_u8PinNo);
		   	 break;
		case DIO_PORTB:
		  	 SET_BIT(DDRB, A_u8PinNo);
			 break;
		case DIO_PORTC:
			 SET_BIT(DDRC, A_u8PinNo);
			 break;
		case DIO_PORTD:
			 SET_BIT(DDRD, A_u8PinNo);
		     break;
		}
	}
	else if(A_u8Dir == DIO_INPUT)
	{
		switch(A_u8PortNo)
		{
		case DIO_PORTA:
			 CLR_BIT(DDRA, A_u8PinNo);
		     break;
		case DIO_PORTB:
			 CLR_BIT(DDRB, A_u8PinNo);
			 break;
		case DIO_PORTC:
			 CLR_BIT(DDRC, A_u8PinNo);
			 break;
	    case DIO_PORTD:
			 CLR_BIT(DDRD, A_u8PinNo);
		     break;
		}
	}


}
void MDIO_vSetPinVal ( u8 A_u8PortNo, u8 A_u8PinNo , u8 A_u8Val )
{
	if(A_u8Val==DIO_HIGH)
	{
		switch(A_u8PortNo)
		{
		case DIO_PORTA:
	 		 SET_BIT(PORTA, A_u8PinNo);
		   	 break;
		case DIO_PORTB:
			 SET_BIT(PORTB, A_u8PinNo);
			 break;
		case DIO_PORTC:
			 SET_BIT(PORTC, A_u8PinNo);
			 break;
		case DIO_PORTD:
			 SET_BIT(PORTD, A_u8PinNo);
			 break;
				}
		}
	else if(A_u8Val == DIO_LOW)
	{
		switch(A_u8PortNo)
		{
		case DIO_PORTA:
			CLR_BIT(PORTA, A_u8PinNo);
	    	break;
	    case DIO_PORTB:
			 CLR_BIT(PORTB, A_u8PinNo);
			 break;
		case DIO_PORTC:
			 CLR_BIT(PORTC, A_u8PinNo);
	       	 break;
		case DIO_PORTD:
			 CLR_BIT(PORTD, A_u8PinNo);
			 break;
				}
		}

}
u8   MDIO_u8GetPinVal( u8 A_u8PortNo, u8 A_u8PinNo )
{
	u8 L_u8Val=0;
	switch(A_u8PortNo)
	{
	case DIO_PORTA:
		 L_u8Val=GET_BIT(PINA, A_u8PinNo);
		 break;
	case DIO_PORTB:
		 L_u8Val=GET_BIT(PINB, A_u8PinNo);
		 break;
	case DIO_PORTC:
	   	 L_u8Val=GET_BIT(PINC, A_u8PinNo);
		 break;
	case DIO_PORTD:
		 L_u8Val=GET_BIT(PIND, A_u8PinNo);
		 break;

	}

	return L_u8Val;
}
void MDIO_vSetPortDir( u8 A_u8PortNo, u8 A_u8Dir   )
{
	switch(A_u8PortNo)
	{
	case DIO_PORTA:
		 DDRA= A_u8Dir;
		 break;
	case DIO_PORTB:
		 DDRB= A_u8Dir;
		 break;
	case DIO_PORTC:
		 DDRC=A_u8Dir;
		 break;
	case DIO_PORTD:
		 DDRD= A_u8Dir;
		 break;
	}

}
void MDIO_vSetPortVal( u8 A_u8PortNo, u8 A_u8Val   )
{
	switch(A_u8PortNo)
	{
	case DIO_PORTA:
		 PORTA= A_u8Val;
		 break;
	case DIO_PORTB:
		 PORTB= A_u8Val;
		 break;
	case DIO_PORTC:
		 PORTC=A_u8Val ;
		 break;
	case DIO_PORTD:
		 PORTD= A_u8Val;
	     break;
	}
}
u8 MDIO_u8GetPortVal ( u8 A_u8PortNo)
{
	u8 L_u8Val=0;
	switch(A_u8PortNo)
	{
	case DIO_PORTA:
 		 L_u8Val=PINA;
	 	 break;
	case DIO_PORTB:
		 L_u8Val=PINB;
		 break;
	case DIO_PORTC:
		 L_u8Val=PINC;
		 break;
	case DIO_PORTD:
		 L_u8Val=PIND;
		 break;
	}
	return L_u8Val;
}

void MDIO_vTogPinVal  ( u8 A_u8PortNo, u8 A_u8PinNo )
{
	switch(A_u8PortNo)
			{
			case DIO_PORTA:
				 TOG_BIT(PORTA, A_u8PinNo);
			   	 break;
			case DIO_PORTB:
			 	 TOG_BIT(PORTB, A_u8PinNo);
				 break;
			case DIO_PORTC:
				 TOG_BIT(PORTC, A_u8PinNo);
				 break;
			case DIO_PORTD:
				 TOG_BIT(PORTD, A_u8PinNo);
			     break;
			}
}
void MDIO_vSetLowNibble(u8 A_u8Port_name,u8 A_u8Value)
{
	A_u8Value&=CLR_HIGH_NIBBLE ;
	switch(A_u8Port_name)
	{
		case DIO_PORTA:
			DDRA&=CLR_LOW_NIBBLE ;
			DDRA|=A_u8Value;
			break;
		case DIO_PORTB:
			DDRB&=CLR_LOW_NIBBLE ;
			DDRB|=A_u8Value;
			break;
		case DIO_PORTC:
			DDRC&=CLR_LOW_NIBBLE ;
			DDRC|=A_u8Value;
			break;
		case DIO_PORTD:
			DDRD&=CLR_LOW_NIBBLE ;
			DDRD|=A_u8Value;
			break;
	}
}
void MDIO_vWriteLowNibble(u8 A_u8Port_name,u8 A_u8Value)
{
	A_u8Value&=CLR_HIGH_NIBBLE ;
	switch(A_u8Port_name)
	{
		case DIO_PORTA:
			PORTA&=CLR_LOW_NIBBLE ;
			PORTA|=A_u8Value;
			break;
		case DIO_PORTB:
			 PORTB&=CLR_LOW_NIBBLE ;
		  	 PORTB|=A_u8Value;
			 break;
		case DIO_PORTC:
			 PORTC&=CLR_LOW_NIBBLE ;
			 PORTC|=A_u8Value;
			 break;
		case DIO_PORTD:
			 PORTD&=CLR_LOW_NIBBLE ;
			 PORTD|=A_u8Value;
			 break;
	}
}
void MDIO_vSetHighNibble(u8 A_u8Port_name,u8 A_u8Value)
{
	A_u8Value<<=4;
	switch(A_u8Port_name)
	{
		case DIO_PORTA:
			 DDRA&=CLR_HIGH_NIBBLE;
			 DDRA|=A_u8Value;
			 break;
		case DIO_PORTB:
			 DDRB&=CLR_HIGH_NIBBLE;
			 DDRB|=A_u8Value;
			 break;
		case DIO_PORTC:
			 DDRC&=CLR_HIGH_NIBBLE;
			 DDRC|=A_u8Value;
			 break;
		case DIO_PORTD:
			 DDRD&=CLR_HIGH_NIBBLE;
			 DDRD|=A_u8Value;
			 break;
	}
}
void MDIO_vWriteHighNibble(u8 A_u8Port_name,u8 A_u8Value)
{
	A_u8Value<<=4;
	switch(A_u8Port_name)
	{
		case DIO_PORTA:
			 PORTA&=CLR_HIGH_NIBBLE;
			 PORTA|=A_u8Value;
			 break;
		case DIO_PORTB:
			 PORTB&=CLR_HIGH_NIBBLE;
		 	 PORTB|=A_u8Value;
			 break;
		case DIO_PORTC:
			 PORTC&=CLR_HIGH_NIBBLE;
			 PORTC|=A_u8Value;
		 	 break;
		case DIO_PORTD:
			 PORTD&=CLR_HIGH_NIBBLE;
			 PORTD|=A_u8Value;
			 break;
	}
}
