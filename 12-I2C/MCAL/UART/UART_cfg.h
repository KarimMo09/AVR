/*
 * UART_cfg.h
 *
 *  Created on: Jul 31, 2022
 *      Author: Karim
 */

#ifndef MCAL_UART_UART_CFG_H_
#define MCAL_UART_UART_CFG_H_

#define Fosc        8000000UL


#define BAUDRATE    9600UL

/* Options
 * ENABLE
 * DISABLE
 */
#define RX_COPMLETE_INTERRUPT_ENABLE      ENABLE
#define TX_COPMLETE_INTERRUPT_ENABLE      DISABLE
#define UDR_EMPTY_INTERRUPT_ENABLE        ENABLE
#define RX_ENABLE 					      ENABLE
#define TX_ENABLE 					      ENABLE

/*Options
 * ASYNCHRONOUS_MODE
 * SYNCHRONOUS_MODE
 */
#define UART_MODE		 ASYNCHRONOUS_MODE
/*Options
 * DISABLE
 * EVEN_PARITY
 * ODD_PARITY
 */
#define PARITY_MODE	   	 DISABLE
/*Options
 * ONE_BIT
 * TWO_BITS
 */
#define STOP_BIT_SELECT  ONE_BIT

/*Options
 * FIVE_BITS
 * SIX_BITS
 * SEVEN_BITS
 * EIGHT_BITS
 */
#define CHAR_SIZE        EIGHT_BITS





#endif /* MCAL_UART_UART_CFG_H_ */
