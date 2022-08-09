/*
 * UART_int.h
 *
 *  Created on: Jul 31, 2022
 *      Author: Karim
 */

#ifndef MCAL_UART_UART_INT_H_
#define MCAL_UART_UART_INT_H_

/*-----------Interrupt types----------*/
#define     RX_COPMLETE     	 0
#define 	TX_COPMLETE     	 1
#define 	UDR_EMPTY 		     2


void MUART_vInit(void);
void MUART_vTransmmitData(u8 A_u8Byte);
u16  MUART_u16RecieveData(void);
void MUART_vSendString(char * A_pu8String);
void MUART_vReceiveString(char str[], u32 A_u32Size);
void MUART_vSendNumber(s32 A_s32Number);
void MUART_vEnableIntterupts(u8 A_u8Interrupt_type);
void MUART_DisableIntterupts(u8 A_u8Interrupt_type);
void MUART_vRX_SetCallback(void (* A_fptr)(u8) );

void MUART_vUDRE_SetCallback(u8 (* A_fptr)(void) );

void MUART_vTX_SetCallback(void (* A_fptr)(void) );




#endif /* MCAL_UART_UART_INT_H_ */
