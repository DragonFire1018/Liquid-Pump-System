/******************************************************************************
 * @file EMAFilter.c
 *
 * @author DragonFire1018
 * @date   12.03.2025
 *
 * @copyright Copyright (c) 2025
 *
 ******************************************************************************
 *
  * @brief Implementation of an Exponential Moving Average (EMA) filter.
 *
 * @details This file contains the implementation of an Exponential Moving Average (EMA) filter,
 *  which is used to smooth sensor data by giving more weight to recent values.
 *  It includes functions for initializing, resetting, and applying the EMA filter to sensor readings.
 *
 *
 *****************************************************************************/


/***** INCLUDES **************************************************************/
#include "EMAFilter.h"

/***** PRIVATE CONSTANTS *****************************************************/


/***** PRIVATE MACROS ********************************************************/


/***** PRIVATE TYPES *********************************************************/


/***** PRIVATE PROTOTYPES ****************************************************/


/***** PRIVATE VARIABLES *****************************************************/


/***** PUBLIC FUNCTIONS ******************************************************/

int32_t filterInitEMA(EMAFilterData_t* pEMA, int32_t scalingFactor, int32_t alpha, bool resetFilter){
	pEMA->alpha = alpha;
	pEMA->previousValue = 0;
	pEMA->scalingFactor = scalingFactor;
	pEMA->firstValueAvailable = false;

	return FILTER_ERR_OK;
}


int32_t filterResetEMA(EMAFilterData_t* pEMA){
	pEMA->previousValue = 0;
	pEMA->firstValueAvailable = false;

	return FILTER_ERR_OK;
}

int32_t filterEMA(EMAFilterData_t* pEMA, int32_t sensorValue){
	int32_t returnValue = 0;

	int32_t scaledSensorValue = sensorValue * pEMA->scalingFactor;
	if(!pEMA->firstValueAvailable){
		returnValue = scaledSensorValue / pEMA->scalingFactor;
		pEMA->firstValueAvailable = true;
	}else{
		returnValue = (pEMA->alpha * scaledSensorValue + (1 - pEMA->alpha) * pEMA->previousValue) / pEMA->scalingFactor;
	}

	pEMA->previousValue = returnValue;

	return returnValue;
}
