/*
 * main.c
 *
 *  Created on: Jul 5, 2022
 *      Author: Karim
 */


#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/GIE/GIE_int.h"
#include "../MCAL/TIMERS/TIMERS_int.h"
#include "../HAL/SERVO_MOTOR/Servo_int.h"

int main(void)
{
	HSERVO_vInt();
	HSERVO_vSetAngel(90);


	while(1)
	{


	}
}


