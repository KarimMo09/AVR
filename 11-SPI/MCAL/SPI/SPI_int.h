/*
 * SPI_int.h
 *
 *  Created on: Aug 2, 2022
 *      Author: Karim
 */

#ifndef MCAL_SPI_SPI_INT_H_
#define MCAL_SPI_SPI_INT_H_

void MSPI_vInit(void);

u8 MSPI_u8TransceiveChar(u8 A_u8Data);

void MSPI_vTransmmitData(u8 A_u8Byte);

u8  MSPI_u8RecieveData(void);

void MSPI_vSendString(char * A_Send_Str);

void MSPI_vReceiveString(char A_Recieved_Str[]);


void MSPI_vEnableIntterupt();

void MSPI_DisableIntterupt();

void MSPI_vSetCallback(u8 (* A_fptr)(void ) );



#endif /* MCAL_SPI_SPI_INT_H_ */
