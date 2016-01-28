/*
 *  LM35_IQMath.c
 *	Created on: Jan 27, 2016
 *  Author: Teja Chintalapati
 *	Contact: teja.chintalapati@gmail.com
 *	Description: This program will read temperature reading from LM35 Temperature Sensor
 *
 */

/******************************************************************************
 * INCLUDES
 */

#include <driverlib.h>
#include "mainApp.h"

/******************************************************************************
 * GLOBAL VARIABLES
 */

float temperatureC;																			//Temperature in Degrees Celsius

/******************************************************************************
 * MAIN
 */

void main(void)
{
	boardInitialisation();

	while(1)
	{
		temperatureC = getTemperatureLM35();
		__low_power_mode_3();																//LPM3, TimerA ISR will force exit. MCU sleeps for 8 seconds
	}
}
