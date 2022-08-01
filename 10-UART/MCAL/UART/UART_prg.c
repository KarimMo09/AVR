/*
 * UART_prg.c
 *
 *  Created on: Jul 31, 2022
 *      Author: Karim
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/Bit_math.h"

#include "UART_int.h"
#include "UART_prv.h"
#include "UART_cfg.h"




void MUART_vInit(void)
{


	/* Receiver Enable/Disable*/
#if   	RX_ENABLE==ENABLE
		SET_BIT(UCSRB,RXEN);
#elif 	RX_ENABLE==DISABLE
		CLR_BIT(UCSRB,RXEN);
#endif
	 /* Transmitter Enable/Disable*/
#if 	TX_ENABLE==ENABLE
		SET_BIT(UCSRB,TXEN);
#elif 	TX_ENABLE==DISABLE
		CLR_BIT(UCSRB,TXEN);
#endif
	/* Interrupts Enable/Disable */
#if 	RX_COPMLETE_INTERRUPT_ENABLE==ENABLE
		SET_BIT(UCSRB,RXCIE);
#elif 	RX_COPMLETE_INTERRUPT_ENABLEE==DISABLE
		CLR_BIT(UCSRB,RXCIE);
#endif
#if 	TX_COPMLETE_INTERRUPT_ENABLE==ENABLE
		SET_BIT(UCSRB,TXCIE);
#elif 	TX_COPMLETE_INTERRUPT_ENABLE==DISABLE
		CLR_BIT(UCSRB,TXCIE);
#endif
#if 	UDR_EMPTY_INTERRUPT_ENABLE==ENABLE
		SET_BIT(UCSRB,UDRIE);
#elif 	UDR_EMPTY_INTERRUPT_ENABLE==DISABLE
		CLR_BIT(UCSRB,UDRIE);
#endif
		/* Write to UCSRC REG need to set URSEL bit*/
		SET_BIT(UCSRC,URSEL);
		/* UART Mode */
#if 	UART_MODE==ASYNCHRONOUS_MODE
		CLR_BIT(UCSRC,UMSEL);
#elif	UART_MODE==SYNCHRONOUS_MODE
		SET_BIT(UCSRC,UMSEL);
#endif
		/*Parity Mode */
#if 	PARITY_MODE==DISABLE
		CLR_BIT(UCSRC,UPM0);
		CLR_BIT(UCSRC,UPM1);
#elif	PARITY_MODE==EVEN_PARITY
		CLR_BIT(UCSRC,UPM0);
		SET_BIT(UCSRC,UPM1);
#elif	PARITY_MODE==ODD_PARITY
		SET_BIT(UCSRC,UPM0);
		SET_BIT(UCSRC,UPM1);
#endif
		/* Stop Bit Number */
#if 	STOP_BIT_SELECT==ONE_BIT
		CLR_BIT(UCSRC,USBS);
#elif	STOP_BIT_SELECT==TWO_BITS
		SET_BIT(UCSRC,USBS);
#endif

		/*Set Character Size      */
#if 	CHAR_SIZE==FIVE_BITS
		CLR_BIT(UCSRC,UCSZ0);
		CLR_BIT(UCSRC,UCSZ1);
		CLR_BIT(UCSRB,UCSZ2);
#elif 	CHAR_SIZE==SIX_BITS
		SET_BIT(UCSRC,UCSZ0);
		CLR_BIT(UCSRC,UCSZ1);
		CLR_BIT(UCSRB,UCSZ2);
#elif 	CHAR_SIZE==SEVEN_BITS
		CLR_BIT(UCSRC,UCSZ0);
		SET_BIT(UCSRC,UCSZ1);
		CLR_BIT(UCSRB,UCSZ2);
#elif 	CHAR_SIZE==EIGHT_BITS
		SET_BIT(UCSRC,UCSZ0);
		SET_BIT(UCSRC,UCSZ1);
		CLR_BIT(UCSRB,UCSZ2);
#else
#error "Please Select a Valid character size"
#endif

	/* Write to UBRRH REG need to CLR URSEL bit*/
	CLR_BIT(UBRRH,URSEL);

	/* Set Baud Rate  */
	UBRRH=( ( (Fosc/16)/BAUDRATE -1)>>8);
	UBRRL= ((Fosc/16)/BAUDRATE-1);

}
void MUART_vTransmmitData(u8 A_u8Byte)
{
	/* Wait for empty transmit buffer */
	while ( !( GET_BIT(UCSRA,UDRE)));
	/* Put data into buffer, sends the data */
	UDR = A_u8Byte;
}
u16  MUART_u16RecieveData(void)
{
	/* Wait for data to be received */
	while ( !(GET_BIT(UCSRA,RXC)) );
	/* Get and return received data from buffer */
	return UDR;
}
void MUART_vSendString(char * A_String)
{
	while(* A_String!='\0')
	{
		MUART_vTransmmitData(*A_String);
		A_String++;
	}
}
void MUART_vSendNumber(s32 A_s32Number)
{
	u8 L_u8DigitNum[10]={0};
		s8 L_s8Digit=0;
		if(A_s32Number<0)
		{
			A_s32Number*=-1;
			MUART_vTransmmitData('-');
		}
		else if(A_s32Number==0)
		{
			MUART_vTransmmitData('0');
		}
		while(A_s32Number)
			{
				L_u8DigitNum[L_s8Digit]=A_s32Number%10;
				A_s32Number/=10;
				L_s8Digit++;
			}
		for(L_s8Digit-=1 ; L_s8Digit>=0 ; L_s8Digit--)
		{
			MUART_vTransmmitData(L_u8DigitNum[L_s8Digit]+48);
		}
}

