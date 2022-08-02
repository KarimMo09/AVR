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

static void (*GS_fpUART_RXC_Callback)(void);
static void (*GS_fpUART_TXC_Callback)(void);
static void (*GS_fpUART_UDRE_Callback)(void);


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

		/*Write to UCRSC so URSEL should be 1
		 * and assign whole register in one operation */
		/* UART Mode */
#if 	UART_MODE==ASYNCHRONOUS_MODE
		UCSRC|=( (1<<URSEL) & (~(1<<UMSEL)) );
#elif	UART_MODE==SYNCHRONOUS_MODE
		SET_BIT(UCSRC,UMSEL);
#endif
		/*Parity Mode */
#if 	PARITY_MODE==DISABLE
		UCSRC|=( (1<<URSEL) & (~(1<<UPM0)) & (~(1<<UPM1)) );
#elif	PARITY_MODE==EVEN_PARITY
		UCSRC|=((1<<URSEL) & (~(1<<UPM0)) | (1<<UPM1));
#elif	PARITY_MODE==ODD_PARITY
		UCSRC|=((1<<URSEL) | (1<<UPM0) | (1<<UPM1));
#endif
		/* Stop Bit Number */
#if 	STOP_BIT_SELECT==ONE_BIT
		UCSRC|=(1<<URSEL) & (~(1<<USBS));
#elif	STOP_BIT_SELECT==TWO_BITS
		UCSRC|=( (1<<URSEL) | (1<<USBS) );
#endif

		/*Set Character Size      */
#if 	CHAR_SIZE==FIVE_BITS
		UCSRC|=( (1<<URSEL) & (~(1<<UCSZ0)) & (~(1<<UCSZ1)) );
		CLR_BIT(UCSRB,UCSZ2);
#elif 	CHAR_SIZE==SIX_BITS
		UCSRC|=( (1<<URSEL) | (1<<UCSZ0) & (~(1<<UCSZ1)) );
		CLR_BIT(UCSRB,UCSZ2);
#elif 	CHAR_SIZE==SEVEN_BITS
		UCSRC|=( (1<<URSEL) & (~(1<<UCSZ0)) | (1<<UCSZ1) );

		CLR_BIT(UCSRB,UCSZ2);
#elif 	CHAR_SIZE==EIGHT_BITS
		UCSRC|=( (1<<URSEL) | (1<<UCSZ0) | (1<<UCSZ1) );
		CLR_BIT(UCSRB,UCSZ2);
#else
#error "Please Select a Valid character size"
#endif
	/* Set Baud Rate  */
	/*Write to UBRRH so URSEL should be 0
	* and assign whole register in one operation */
	UBRRH=( ( (Fosc/16)/BAUDRATE -1)>>8) & (~(1<<URSEL) );
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













void MUART_vEnableIntterupts(u8 A_u8Interrupt_type)
{
	switch(A_u8Interrupt_type)
		{
		    case RX_COPMLETE:SET_BIT(UCSRB,RXCIE);
						 break;
			case TX_COPMLETE:SET_BIT(UCSRB,TXCIE);
						 break;
			case UDR_EMPTY:SET_BIT(UCSRB,UDRIE);
						 break;
		}

}
void MUART_DisableIntterupts(u8 A_u8Interrupt_type)
{

	switch(A_u8Interrupt_type)
			{
			    case RX_COPMLETE:CLR_BIT(UCSRB,RXCIE);
							 break;
				case TX_COPMLETE:CLR_BIT(UCSRB,TXCIE);
							 break;
				case UDR_EMPTY:CLR_BIT(UCSRB,UDRIE);
							 break;
			}
}
void MUART_vSetCallback(u8 A_u8Interrupt_type,void (* A_fptr)(void) )
{

	switch(A_u8Interrupt_type)
	{
	    case RX_COPMLETE:GS_fpUART_RXC_Callback=A_fptr;
	    				 break;
	    case TX_COPMLETE:GS_fpUART_TXC_Callback=A_fptr;
	    				 break;
	    case UDR_EMPTY  :GS_fpUART_UDRE_Callback=A_fptr;
	    			     break;
	}
}
/*---------------ISR Receiver Complete---------------*/
void __vector_13(void) __attribute__((signal));
void __vector_13(void)
{
	if (GS_fpUART_RXC_Callback != NULL)
		{
			GS_fpUART_RXC_Callback();
		}
}
/*---------------ISR Transmitter Complete---------------*/
void __vector_15(void) __attribute__((signal));
void __vector_15(void)
{
	if (GS_fpUART_TXC_Callback != NULL)
		{
		    GS_fpUART_TXC_Callback();
		}
}
/*---------------ISR UDR Empty--------------*/
void __vector_14(void) __attribute__((signal));
void __vector_14(void)
{
	if (GS_fpUART_UDRE_Callback != NULL)
		{
		    GS_fpUART_UDRE_Callback();
		}
}
