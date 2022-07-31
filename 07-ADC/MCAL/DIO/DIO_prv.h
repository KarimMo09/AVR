/*
 * DIO_prv.h
 *
 *  Created on: Jul 23, 2022
 *      Author: Karim
 */

#ifndef MCAL_DIO_DIO_PRV_H_
#define MCAL_DIO_DIO_PRV_H_

#include "../../LIB/STD_TYPES.h"


#define  DDRA		(*((volatile u8 *)0x3A))
#define  PORTA	    (*((volatile u8 *)0x3B))
#define  PINA		(*((volatile u8 *)0x39))

#define  DDRB		(*((volatile u8 *)0x37))
#define  PORTB	    (*((volatile u8 *)0x38))
#define  PINB		(*((volatile u8 *)0x36))

#define  DDRC		(*((volatile u8 *)0x34))
#define  PORTC	    (*((volatile u8 *)0x35))
#define  PINC		(*((volatile u8 *)0x33))

#define  DDRD		(*((volatile u8 *)0x31))
#define  PORTD	    (*((volatile u8 *)0x32))
#define  PIND		(*((volatile u8 *)0x30))




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
#define PORT_OUTPUT  0xff

#define DIO_LOW          0
#define DIO_HIGH         1
#define PORT_LOW     0x00
#define PORT_HIGH    0xff


#endif /* MCAL_DIO_DIO_PRV_H_ */
