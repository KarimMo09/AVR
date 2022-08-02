/*
 * DIO_int.h
 *
 *  Created on: May 17, 2022
 *      Author: Karim
 */

#ifndef MCAL_DIO_DIO_INT_H_
#define MCAL_DIO_DIO_INT_H_

#include "../../LIB/STD_TYPES.h"

#define DIO_PORTA    0
#define DIO_PORTB    1
#define DIO_PORTC    2
#define DIO_PORTD    3

#define DIO_PIN0     0
#define DIO_PIN1     1
#define DIO_PIN2     2
#define DIO_PIN3     3
#define DIO_PIN4     4
#define DIO_PIN5     5
#define DIO_PIN6     6
#define DIO_PIN7     7


#define DIO_INPUT    0
#define DIO_OUTPUT   1
#define PORT_INPUT   0x00
#define PORT_OUTPUT  0xFF

#define DIO_LOW          0
#define DIO_HIGH         1
#define PORT_LOW         0x00
#define PORT_HIGH        0xFF
#define CLR_LOW_NIBBLE   0xF0
#define CLR_HIGH_NIBBLE  0x0F


void MDIO_vSetPinDir      ( u8 A_u8PortNo, u8 A_u8PinNo , u8 A_u8Dir );
void MDIO_vSetPinVal      ( u8 A_u8PortNo, u8 A_u8PinNo , u8 A_u8Val );
u8   MDIO_u8GetPinVal     ( u8 A_u8PortNo, u8 A_u8PinNo );
void MDIO_vSetPortDir     ( u8 A_u8PortNo, u8 A_u8Dir   );
void MDIO_vSetPortVal     ( u8 A_u8PortNo, u8 A_u8Val   );
u8   MDIO_u8GetPortVal 	  ( u8 A_u8PortNo);
void MDIO_vTogPinVal      ( u8 A_u8PortNo, u8 A_u8PinNo );
void MDIO_vSetLowNibble   (u8 A_u8Port_name,u8 A_u8Value);
void MDIO_vWriteLowNibble (u8 A_u8Port_name,u8 A_u8Value);
void MDIO_vSetHighNibble  (u8 A_u8Port_name,u8 A_u8Value);
void MDIO_vWriteHighNibble(u8 A_u8Port_name,u8 A_u8Value);


#endif /* MCAL_DIO_DIO_INT_H_ */
