/******************************************************************************
 * @file FlowRateSensor.c
 *
 * @author DragonFire1018
 * @date   11.03.2025
 *
 * @copyright Copyright (c) 2025
 *
 ******************************************************************************
 *
 * @brief Implementation of a flow rate sensor using an ADC and SMA filter.
 *
 * @details This file contains the implementation of a flow rate sensor that reads voltage from an ADC,
 *  applies a Simple Moving Average (SMA) filter to smooth the readings,
 *  and calculates the flow rate based on the filtered voltage.#
 *  It includes functions for initialization, running the sensor cycle, and retrieving the current flow rate.
 *
 *
 *****************************************************************************/

/***** INCLUDES **************************************************************/
#include "ADCModule.h"
#include "FlowRateSensor.h"
#include "../Filter/SMAFilter.h"

/***** PRIVATE CONSTANTS *****************************************************/


/***** PRIVATE MACROS ********************************************************/

#define MICROVOLTAGE_TO_LITER_PER_HOUR 0.00004
#define SMA_SCALING_FACTOR 100

/***** PRIVATE TYPES *********************************************************/


/***** PRIVATE PROTOTYPES ****************************************************/
static int32_t sensorCalculateFlowRate(int32_t inputVoltage);


/***** PRIVATE VARIABLES *****************************************************/
static SMAFilterData_t gSensorSMAFilter;

static int32_t gSensorVoltage;
static int32_t gSensorVoltageFiltered;
static int32_t gSensorFlowRate;


/***** PUBLIC FUNCTIONS ******************************************************/

int32_t flowRateSensorInitialize()
{
	gSensorVoltage  			= 0;
	gSensorVoltageFiltered  	= 0;
	gSensorFlowRate 		    = 0;

	filterInitSMA(&gSensorSMAFilter, SMA_SCALING_FACTOR, true);

	return 0;
}

int32_t flowRateSensorCycle()
{
	gSensorVoltage 				= adcReadChannel(ADC_INPUT1);
	gSensorVoltageFiltered		= filterSMA(&gSensorSMAFilter, gSensorVoltage);

	gSensorFlowRate = sensorCalculateFlowRate(gSensorVoltageFiltered);

	return 0;
}

int32_t flowRateSensorGetFlowRate()
{
	return gSensorFlowRate;
}


/***** PRIVATE FUNCTIONS *****************************************************/

static int32_t sensorCalculateFlowRate(int32_t inputVoltage)
{
	int32_t speedValue;

	if(inputVoltage < MAX_OUTPUT_MICRO_VOLTAGE && inputVoltage > MIN_OUTPUT_MICRO_VOLTAGE){
		speedValue = (inputVoltage-MIN_OUTPUT_MICRO_VOLTAGE)*MICROVOLTAGE_TO_LITER_PER_HOUR;
	}
	return speedValue;
}


