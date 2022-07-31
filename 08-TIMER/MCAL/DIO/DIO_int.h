/*
 * DIO_int.h
 *
 *  Created on: May 17, 2022
 *      Author: Karim
 */

#ifndef MCAL_DIO_DIO_INT_H_
#define MCAL_DIO_DIO_INT_H_

#include "../../LIB/STD_TYPES.h"
#include "DIO_prv.h"
#include "DIO_cfg.h"

void MDIO_vSetPinDir ( u8 A_u8PortNo, u8 A_u8PinNo , u8 A_u8Dir );
void MDIO_vSetPinVal ( u8 A_u8PortNo, u8 A_u8PinNo , u8 A_u8Val );
u8   MDIO_u8GetPinVal( u8 A_u8PortNo, u8 A_u8PinNo );
void MDIO_vSetPortDir( u8 A_u8PortNo, u8 A_u8Dir   );
void MDIO_vSetPortVal( u8 A_u8PortNo, u8 A_u8Val   );
u8   MDIO_u8GetPortVal ( u8 A_u8PortNo);
void MDIO_vTogPinVal  ( u8 A_u8PortNo, u8 A_u8PinNo );


#endif /* MCAL_DIO_DIO_INT_H_ */
