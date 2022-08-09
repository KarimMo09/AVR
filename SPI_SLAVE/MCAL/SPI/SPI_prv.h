/*
 * SPI_prv.h
 *
 *  Created on: Aug 2, 2022
 *      Author: Karim
 */

#ifndef MCAL_SPI_SPI_PRV_H_
#define MCAL_SPI_SPI_PRV_H_

#define SPCR       *((volatile u8*)(0x2D))
#define SPSR       *((volatile u8*)(0x2E))
#define SPDR       *((volatile u8*)(0x2F))




/*-------- SPCR BITS----------*/
#define SPR0	0
#define SPR1	1
#define CPHA	2
#define CPOL	3
#define MSTR	4
#define DORD	5
#define SPE		6
#define SPIE	7
/*-----------------------------*/
/*-------- SPSR BITS----------*/
#define SPI2X	0
#define WCOL 	6
#define SPIF    7
/*-----------------------------*/

/*------------CONFIGURATION------------*/
#define    	DISABLE		  	 	1
#define    	ENABLE	    	 	2


#define MASTER	    	 	1
#define SLAVE	   	 	    2

#define MSB		    	 	1
#define LSB	    	 	    2


#define DUMMY_DATA         0x00


#define NORMAL_SPEED		1
#define DOUBLE_MASTER_SPEED 2


#define F_OSC_2             1
#define F_OSC_4             2
#define F_OSC_8             3
#define F_OSC_16            4
#define F_OSC_32            5
#define F_OSC_64            6
#define F_OSC_128           7

#define RAISING_EDGE_LEADING_FALLING_EDGE_TRAILLING			1
#define FALLING_EDGE_LEADING_RAISING_EDGE_TRAILLING			2

#define LEADING_EDGE_SETUP_TRAILLING_EDGE_SAMPLE     		1 //Read
#define LEADING_EDGE_SAMPLE_TRAILLING_EDGE_SETUP			2 //Write
/*-----------Pin Configuration-----------*/
#define SS     4
#define MOSI   5
#define MISO   6
#define SCK    7

#endif /* MCAL_SPI_SPI_H_ */
