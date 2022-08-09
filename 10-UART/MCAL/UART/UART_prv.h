/*
 * UART_prv.h
 *
 *  Created on: Jul 31, 2022
 *      Author: Karim
 */

#ifndef MCAL_UART_UART_PRV_H_
#define MCAL_UART_UART_PRV_H_

#define UDR       *((volatile u8*)(0x2C))
#define UCSRA     *((volatile u8*)(0x2B))
#define UCSRB     *((volatile u8*)(0x2A))
#define UCSRC     *((volatile u8*)(0x40))
#define UBRRL     *((volatile u8*)(0x29))
#define UBRRH     *((volatile u8*)(0x40))



/*-------- UCSRA BITS----------*/
#define MPCM	0
#define U2X 	1
#define PE 		2
#define DOR		3
#define FE 		4
#define UDRE	5
#define TXC 	6
#define RXC		7
/*-----------------------------*/
/*-------- UCSRB BITS----------*/
#define TXB8	0
#define RXB8 	1
#define UCSZ2 	2
#define TXEN 	3
#define RXEN    4
#define UDRIE	5
#define TXCIE 	6
#define RXCIE   7
/*-----------------------------*/
/*-------- UCSRB BITS----------*/
#define UCPOL	0
#define UCSZ0	1
#define UCSZ1 	2
#define USBS 	3
#define UPM0 	4
#define UPM1    5
#define UMSEL	6
#define URSEL	7
/*-----------------------------*/

/*------------CONFIGURATION------------*/
#define    	DISABLE		  	 	 0
#define    	ENABLE	    	 	 1

#define     ASYNCHRONOUS_MODE	 0
#define     SYNCHRONOUS_MODE	 1



#define     EVEN_PARITY      	 1
#define     ODD_PARITY	 		 2

#define     ONE_BIT				 0
#define     TWO_BITS			 1
#define     FIVE_BITS			 2
#define     SIX_BITS			 3
#define     SEVEN_BITS			 4
#define     EIGHT_BITS			 5

#endif /* MCAL_UART_UART_PRV_H_ */
