/*
 * ADC_cfg.h
 *
 *  Created on: Jul 22, 2022
 *      Author: Karim
 */

#ifndef MCAL_ADC_CFG_H_
#define MCAL_ADC_CFG_H_


/**
 * Options:
 * ADC_PS_x, where x =
 * 		  2
 * 		  4
 * 		  8
 * 		  16
 * 		  32
 * 		  64
 * 		  128
 */
#define ADC_PRESCALER	ADC_PS_64


/**
 *  Options:
 *  	 AVCC
		 INTERNAL_REF
		 AREF
 */
#define ADC_REF_VOLT	AVCC

/**
 * ENABLE / DISABLE
 *
 */
#define ADC_INTERRUPT_ENABLE   ENABLE

#endif /* MCAL_ADC_CFG_H_ */
