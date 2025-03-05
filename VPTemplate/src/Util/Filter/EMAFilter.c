/*
 * Filter.c
 *
 *  Created on: 05.03.2025
 *      Author: drago
 */
#include "EMAFilter.h"

int32_t filterInitEMA(EMAFilterData_t* pEMA, int32_t scalingFactor, int32_t alpha, bool resetFilter){
	pEMA->alpha = alpha;
	pEMA->previousValue = 0;
	pEMA->scalingFactor = scalingFactor;
	pEMA->firstValueAvailable = false;

	return 1;
}


int32_t filterResetEMA(EMAFilterData_t* pEMA){
	pEMA->previousValue = 0;
	pEMA->firstValueAvailable = false;

	return 1;
}

int32_t filterEMA(EMAFilterData_t* pEMA, int32_t sensorValue){
	int32_t returnValue;

	int32_t scaledSensorValue = sensorValue * pEMA->scalingFactor;
	if(!pEMA->firstValueAvailable){
		returnValue = scaledSensorValue;
		pEMA->firstValueAvailable = true;
	}else{
		returnValue = (pEMA->alpha * scaledSensorValue + (1 - pEMA->alpha) * pEMA->previousValue) / scaledSensorValue;
	}

	pEMA->previousValue = returnValue;

	return returnValue;
}
