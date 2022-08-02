/*
 * EXTI_cfg.h
 *
 *  Created on: Jul 19, 2022
 *      Author: Karim
 */

#ifndef MCAL_EXTI_EXTI_CFG_H_
#define MCAL_EXTI_EXTI_CFG_H_


#define ENABLE					1
#define DISABLE					2

#define EXTI_RAISING			1
#define EXTI_FALLING			2
#define EXTI_LOWLEVEL			3
#define EXTI_ONCHANGE			4

#define EXTI_LINE0				ENABLE
#define EXTI_LINE1				DISABLE
#define EXTI_LINE2				DISABLE
#define EXTI_LIN0_SENSE_CTRL	EXTI_RAISING
#define EXTI_LIN1_SENSE_CTRL	EXTI_FALLING
#define EXTI_LIN2_SENSE_CTRL	EXTI_FALLING
#endif /* MCAL_EXTI_EXTI_CFG_H_ */
