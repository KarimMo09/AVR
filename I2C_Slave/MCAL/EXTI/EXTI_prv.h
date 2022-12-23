/*
 * EXTI_prv.h
 *
 *  Created on: Jul 23, 2022
 *      Author: Karim
 */

#ifndef MCAL_EXTI_EXTI_PRV_H_
#define MCAL_EXTI_EXTI_PRV_H_
#include "../../LIB/STD_TYPES.h"

#define		SREG		*((volatile u8 *)0x5F)
#define		GICR		*((volatile u8 *)0x5B) //Just contains bits enable External interrupt
#define		MCUCR		*((volatile u8 *)0x55) //
#define		MCUCSR		*((volatile u8 *)0x54)// MCU STATUES AND CONTROL REG
#define		GIFR		*((volatile u8 *)0x5B) //Flags of external interrupt


#define		INT0	6
#define		INT1	7
#define		INT2	5
#define		IVCE	0
#define		IVSEL	1

#define		INTF0	6
#define		INTF1	7
#define		INTF2	5

/** Interrupt sense control **/
#define		ISC00	0 // For INT0
#define		ISC01	1 // For INT0
#define		ISC10	2 // For INT1
#define		ISC11	3 // For INT1
#define     ISC2    6 // For INT2


#define		SM0		4
#define		SM1		5
#define		SE		6
#define		SM2		7

#endif /* MCAL_EXTI_EXTI_PRV_H_ */
