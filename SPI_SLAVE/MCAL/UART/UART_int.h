/*
 * UART_int.h
 *
 *  Created on: Jul 31, 2022
 *      Author: Karim
 */

#ifndef MCAL_UART_UART_INT_H_
#define MCAL_UART_UART_INT_H_

void MUART_vInit(void);
void MUART_vTransmmitData(u8 A_u8Byte);
u16  MUART_u16RecieveData(void);
void MUART_vSendString(char * A_pu8String);
void MUART_vSendNumber(s32 A_s32Number);
void MUART_vEnableIntterupts(u8 A_u8Interrupt_type);
void MUART_DisableIntterupts(u8 A_u8Interrupt_type);
void MUART_vSetCallback(u8 A_u8Interrupt_type,void (* A_fptr)(void) );




#endif /* MCAL_UART_UART_INT_H_ */
