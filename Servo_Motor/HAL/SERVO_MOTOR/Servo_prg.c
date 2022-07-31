/*
 * Servo_prg.c
 *
 *  Created on: Jul 31, 2022
 *      Author: Karim
 */
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "../../MCAL/GIE/GIE_int.h"
#include "../../MCAL/TIMERS/TIMERS_int.h"
#include "Servo_int.h"
#include "Servo_prv.h"
#include "Servo_cfg.h"

void HSERVO_vInt()
{
	MDIO_vSetPinDir(DIO_PORTD,SERVO_PIN1,DIO_OUTPUT);
	MTIMERS_vInit();


}
void HSERVO_vSetAngel(u8 A_u8AngelDeg)
{
	u8 L_u8AngelVal=(A_u8AngelDeg*25)/36+125;
	MTIMERS_vSetCompareValueTIM1(CHANNEL_B,L_u8AngelVal);
	MTIMERS_vStartTimer(TIMER1);
}
