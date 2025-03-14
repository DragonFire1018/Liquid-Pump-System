/******************************************************************************
 * @file SMAFilter.c
 *
 * @author DragonFire1018
 * @date   12.03.2025
 *
 * @copyright Copyright (c) 2025
 *
 ******************************************************************************
 *
  * @brief Implementation of a Simple Moving Average (SMA) filter.
 *
 * @details This file contains the implementation of a Simple Moving Average (SMA) filter,
 *  which is used to smooth sensor data by averaging a fixed number of recent values.
 *  It includes functions for initializing, resetting, and applying the SMA filter to sensor readings.
 *
 *
 *****************************************************************************/


/***** INCLUDES **************************************************************/
#include "SMAFilter.h"


/***** PRIVATE CONSTANTS *****************************************************/


/***** PRIVATE MACROS ********************************************************/


/***** PRIVATE TYPES *********************************************************/


/***** PRIVATE PROTOTYPES ****************************************************/


/***** PRIVATE VARIABLES *****************************************************/


/***** PUBLIC FUNCTIONS ******************************************************/

int32_t filterInitSMA(SMAFilterData_t* pSMA, int32_t scalingFactor, bool resetFilter){
	pSMA->inputsAvailable = 0;
	pSMA->scalingFactor = scalingFactor;
	pSMA->sum = 0;
	pSMA->windowPosition = 0;
	return FILTER_ERR_OK;
}

int32_t filterResetSMA(SMAFilterData_t* pSMA){
	pSMA->inputsAvailable = 0;
	pSMA->sum = 0;
	pSMA->windowPosition = 0;
	return FILTER_ERR_OK;
}

int32_t filterSMA(SMAFilterData_t* pSMA, int32_t sensorValue){
	int32_t returnValue = 0;
	int32_t scaledSensorValue = sensorValue * pSMA->scalingFactor;

	if (FILTER_WINDOW_SIZE == 1){
		return sensorValue;
	}

	if (pSMA->inputsAvailable < FILTER_WINDOW_SIZE-1) {
		pSMA->window[pSMA->windowPosition] = scaledSensorValue;
		pSMA->sum += scaledSensorValue;
		pSMA->windowPosition++;
		pSMA->inputsAvailable++;
		return sensorValue;
	}

	if (pSMA->windowPosition >= FILTER_WINDOW_SIZE) {
		pSMA->windowPosition = 0;
	}
	pSMA->sum -= pSMA->window[pSMA->windowPosition];
	pSMA->window[pSMA->windowPosition] = scaledSensorValue;
	pSMA->sum += scaledSensorValue;
	pSMA->windowPosition++;

	returnValue = pSMA->sum / FILTER_WINDOW_SIZE / pSMA->scalingFactor;

	return returnValue;
}

