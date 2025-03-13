/*
 * FlowRateSensor.c
 *
 *  Created on: 10.03.2025
 *      Author: drago
 */

/***** INCLUDES **************************************************************/
#include "ADCModule.h"
#include "FlowRateSensor.h"
#include "../Filter/SMAFilter.h"

/***** PRIVATE CONSTANTS *****************************************************/


/***** PRIVATE MACROS ********************************************************/

#define MICROVOLTAGE_TO_LITER_PER_HOUR 0.00004
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

	/*Todo*/
	filterInitSMA(&gSensorSMAFilter, 100, true, 10);

	return 0;
}

int32_t flowRateSensorCycle()
{
	gSensorVoltage 				= adcReadChannel(ADC_INPUT1);
	gSensorVoltageFiltered		= gSensorVoltage; //filterSMA(&gSensorSMAFilter, gSensorVoltage);

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


