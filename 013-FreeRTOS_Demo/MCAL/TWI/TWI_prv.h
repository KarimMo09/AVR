/*
 * I2C_prv.h
 *
 *  Created on: Aug 9, 2022
 *      Author: Karim
 */

#ifndef MCAL_TWI_TWI_PRV_H_
#define MCAL_TWI_TWI_PRV_H_



#define TWCR      (*(volatile u8*)(0x56))
#define TWDR      (*(volatile u8*)(0x23))
#define TWAR      (*(volatile u8*)(0x22))
#define TWSR      (*(volatile u8*)(0x21))
#define TWBR      (*(volatile u8*)(0x20))

/*----------------TWAR BITS----------------*/
#define TWGCE  	0
#define TWA0 	1
#define TWA1	2
#define TWA2  	3
#define TWA3    4
#define TWA4    5
#define TWA5 	6
#define TWA6 	7
/*-----------------------------------------*/

/*----------------TWSR BITS----------------*/
#define TWPS0 	0
#define TWPS1	1
#define TWS3  	3
#define TWS4    4
#define TWS5 	5
#define TWS6 	6
#define TWS7 	7
/*-----------------------------------------*/

/*----------------TWCR BITS----------------*/
#define TWIE  	0
#define TWEN  	2
#define TWWC  	3
#define TWSTO   4
#define TWSTA 	5
#define TWEA    6
#define TWINT 	7
/*-----------------------------------------*/


#endif /* MCAL_TWI_TWI_PRV_H_ */
