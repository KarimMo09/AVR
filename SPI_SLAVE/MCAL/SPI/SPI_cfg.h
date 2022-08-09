/*
 * SPI_cfg.h
 *
 *  Created on: Aug 2, 2022
 *      Author: Karim
 */

#ifndef MCAL_SPI_SPI_CFG_H_
#define MCAL_SPI_SPI_CFG_H_
/* Options
 * MASTER
 * SLAVE
 */
#define SPI_MODE 	SLAVE
/* Options
 * ENABLE
 * DISABLE
 */
#define SPI_INTRRUPT_ENABLE	    ENABLE


/* Options
 * MSB
 * LSB
 */
#define DATA_ORDER              MSB

/*Options
 * RAISING_EDGE_LEADING_FALLING_EDGE_TRAILLING
 * FALLING_EDGE_LEADING_RAISING_EDGE_TRAILLING
 */
#define CLOCK_POLARITY	   	RAISING_EDGE_LEADING_FALLING_EDGE_TRAILLING
/*Options
 *LEADING_EDGE_SETUP_TRAILLING_EDGE_SAMPLE
 *LEADING_EDGE_SAMPLE_TRAILLING_EDGE_SETUP
 */
#define CLOCK_PHASE	   	 	LEADING_EDGE_SETUP_TRAILLING_EDGE_SAMPLE
/*Options
 * DOUBLE_MASTER_SPEED
 * NORMAL_SPEED
 */
#define SPI_SPEED    NORMAL_SPEED
/*
 * Options
 ----Normal Speed Options-------
 * F_OSC_4
 * F_OSC_16
 * F_OSC_64
 * F_OSC_128
 ----Double master Speed---
 * F_OSC_2
 * F_OSC_8
 * F_OSC_32
 * F_OSC_64
 */
#define SCK_FREQUENCY      F_OSC_16






#endif /* MCAL_SPI_SPI_CFG_H_ */
