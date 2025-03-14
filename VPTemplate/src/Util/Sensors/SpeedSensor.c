/******************************************************************************
 * @file SpeedSensor.c
 *
 * @author DragonFire1018
 * @date   11.03.2025
 *
 * @copyright Copyright (c) 2025
 *
 ******************************************************************************
 *
 * @brief Implementation of a speed sensor using an ADC and EMA filter.
 *
 * @details This file contains the implementation of a speed sensor that reads voltage from an ADC,
 *  applies an Exponential Moving Average (EMA) filter to smooth the readings,
 *  and calculates the speed based on the filtered voltage.
 *  It includes functions for initialization, running the sensor cycle, and retrieving the current speed.
 *
 *
 *****************************************************************************/

/***** INCLUDES **************************************************************/
#include "ADCModule.h"

#include "SpeedSensor.h"
#include "../Filter/EMAFilter.h"

/***** PRIVATE CONSTANTS *****************************************************/


/***** PRIVATE MACROS ********************************************************/

#define MICROVOLTAGE_TO_REVOLUTIONS 0.0005
#define EMA_SCALING_FACTOR 10
#define EMA_SCALED_ALPHA 1 /*Alpha times scaling factor*/

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

	filterInitEMA(&gSensorEMAFilter, EMA_SCALING_FACTOR, EMA_SCALED_ALPHA, true);

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
		speedValue = (inputVoltage-MIN_OUTPUT_MICRO_VOLTAGE)*MICROVOLTAGE_TO_REVOLUTIONS;
	}
	return speedValue;
}



