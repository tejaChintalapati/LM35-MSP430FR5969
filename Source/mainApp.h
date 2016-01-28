/*
 * mainApp.h
 *
 * Created on: Jan 27, 2016
 * Author: Teja Chintalapati
 * Contact: teja.chintalapati@gmail.com
 *
 */

#ifndef SOURCE_MAINAPP_H_
#define SOURCE_MAINAPP_H_

/******************************************************************************
 * INCLUDES
 */

#include <driverlib.h>
#include "ADCInitialisation.h"
#include "clockInitialisation.h"
#include "pinInitialisation.h"
#include "portInitialisation.h"
#include "timerInitialisation.h"
#include "LM35_Temperature.h"

#define GLOBAL_IQ    														   7			//Please read C:\ti\msp430\MSPWare_2_40_00_37\iqmathlib\MSP430-IQmathLib-UsersGuide to choose appropriate IQValue
#include "IQmathLib.h"

/******************************************************************************
 * DEFINITIONS
 */

//Used in LM35_Temperature.c
#define VRef																   330			//3.3Volts Reference
#define ADC																	   4095			//12 Bit ADC

//Used in clockInitiaisation.c
#define LF_CRYSTAL_FREQUENCY_IN_HZ     										   32768
#define HF_CRYSTAL_FREQUENCY_IN_HZ											   0            // FR5969 Launchpad does not have 16MHz crystal

//Used in portInitialisation.c
#define allPins																	GPIO_PIN0 + GPIO_PIN1 + GPIO_PIN2 + GPIO_PIN3 + GPIO_PIN4 + GPIO_PIN5 + GPIO_PIN6 + GPIO_PIN7

/******************************************************************************
 * GLOBAL VARIABLES
 */

extern uint16_t ADCValue;																	//Variable to store RAW ADC Value

/******************************************************************************
 * FUNCTION DECLARATION
 */

void boardInitialisation(void);

#endif /* SOURCE_MAINAPP_H_ */
