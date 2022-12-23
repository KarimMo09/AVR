/*
 * main.c
 *
 *  Created on: Jul 5, 2022
 *      Author: Karim
 */


#include "LIB/STD_TYPES.h"
#include "LIB/Bit_math.h"
#include "MCAL/DIO/DIO_int.h"
#include "MCAL/GIE/GIE_int.h"

#include "FreeRTOS.h"
#include "task.h"

void Task_Led1(void* pvParams)
{

	while(1)
	{
		MDIO_vTogPinVal(DIO_PORTA,0);

		vTaskDelay(500);

	}
}
void Task_Led2(void* pvParams)
{

	while(1)
	{
		MDIO_vTogPinVal(DIO_PORTA,1);
		vTaskDelay(1000);
	}
}
void Task_Led3(void* pvParams)
{

	while(1)
	{
		MDIO_vTogPinVal(DIO_PORTA,2);
		vTaskDelay(1500);
	}
}


int main(void)
{
	MDIO_vSetPinDir(DIO_PORTA, DIO_PIN0,DIO_OUTPUT);
	MDIO_vSetPinDir(DIO_PORTA, DIO_PIN1,DIO_OUTPUT);
	MDIO_vSetPinDir(DIO_PORTA, DIO_PIN2,DIO_OUTPUT);
	xTaskCreate(Task_Led1, NULL,100,NULL,1, NULL);
	xTaskCreate(Task_Led2, NULL,100,NULL,2, NULL);
	xTaskCreate(Task_Led3, NULL,100,NULL,3, NULL);


	vTaskStartScheduler();

}


