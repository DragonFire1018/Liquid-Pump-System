/******************************************************************************
 * SpeedSensor.c
 *
 *  Created on: 05.03.2025
 *      Author: drago
 ******************************************************************************
 *
 * @brief Sensor Module for SpeedSensor
 *
 *
 *****************************************************************************/


/***** INCLUDES **************************************************************/
#include "ADCModule.h"

#include "SpeedSensor.h"
#include "../Filter/EMAFilter.h"

/***** PRIVATE CONSTANTS *****************************************************/


/***** PRIVATE MACROS ********************************************************/
#define MIN_REVOLUTIONS			0			// Min revolutions 0rpm
#define MAX_REVOLUTIONS			1000		// Max revolutions 1000rpm

#define MIN_OUTPUT_MICRO_VOLTAGE 500000 				//Min output voltage 0.5
#define MAX_OUTPUT_MICRO_VOLTAGE 2500000				//Max output voltage 2.5

#define MICROVOLTAGE_TO_REVOLUTIONS 0.0005
/***** PRIVATE TYPES *********************************************************/


/***** PRIVATE PROTOTYPES ****************************************************/
static int32_t sensorCalculateSpeed(int32_t inputVoltage);


/***** PRIVATE VARIABLES *****************************************************/
static EMAFilterData_t gSensorEMAFilter;

static int32_t gSensorVoltage;
static int32_t gSensorVoltageFiltered;
static int32_t gSensorSpeed;


/***** PUBLIC FUNCTIONS ******************************************************/

int32_t speedSensorInitialize()
{
	gSensorVoltage  		= 0;
	gSensorVoltageFiltered  = 0;
	gSensorSpeed 		    = 0;

	/*Todo*/
	filterInitEMA(&gSensorEMAFilter, 100, 70, true);

	return 0;
}

int32_t speedSensorCycle()
{
	gSensorVoltage 				= adcReadChannel(ADC_INPUT0);
	gSensorVoltageFiltered		= filterEMA(&gSensorEMAFilter, gSensorVoltage);

	gSensorSpeed = sensorCalculateSpeed(gSensorVoltageFiltered);

	return 0;
}

int32_t speedSensorGetSpeed()
{
	return gSensorSpeed;
}


/***** PRIVATE FUNCTIONS *****************************************************/

static int32_t sensorCalculateSpeed(int32_t inputVoltage)
{
	int32_t speedValue;

	if(inputVoltage < MAX_OUTPUT_MICRO_VOLTAGE && inputVoltage > MIN_OUTPUT_MICRO_VOLTAGE){
		speedValue = inputVoltage*MICROVOLTAGE_TO_REVOLUTIONS;
	}
	return speedValue;
}



