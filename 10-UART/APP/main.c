/*
 * main.c
 *
 *  Created on: Jul 5, 2022
 *      Author: Karim
 */


#include "../LIB/STD_TYPES.h"
#include "../LIB/Bit_math.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/UART/UART_int.h"
#include "../MCAL/GIE/GIE_int.h"
#include <util/delay.h>
char x[10]="Karim ";

void ISR_UDRE(void)
{
	/*_delay_ms(200);
	if(*x=='\0')
	{
		MUART_DisableIntterupts(UDR_EMPTY);
	}*/

}

int main(void)
{
	_delay_ms(15);
	//MUART_vUDRE_SetCallback(ISR_UDRE);

	MGIE_vEnableGlobalInterrupt();
	MUART_vInit();

	while(1)
	{
		MUART_vTransmit_Asynch(x,10,ISR_UDRE);
	}
}

