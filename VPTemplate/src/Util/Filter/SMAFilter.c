/*
 * SMAFilter.c
 *
 *  Created on: 10.03.2025
 *      Author: drago
 */
#include "SMAFilter.h"

int32_t filterInitSMA(SMAFilterData_t* pSMA, int32_t scalingFactor, bool resetFilter,int32_t windowSize){
		pSMA->firstValueAvailable = false;
	    pSMA->previousValue = 0;
	    pSMA->scalingFactor = scalingFactor;
	    pSMA->sum = 0;
	    pSMA->windowSize = windowSize;
	    return FILTER_ERR_OK;
}

int32_t filterResetSMA(SMAFilterData_t* pSMA){
	pSMA->firstValueAvailable = false;
	pSMA->previousValue = 0;
	pSMA->sum = 0;
	return FILTER_ERR_OK;
}

int32_t filterSMA(SMAFilterData_t* pSMA, int32_t sensorValue){
	if (!pSMA->firstValueAvailable) {
	        pSMA->sum = sensorValue;
	        pSMA->firstValueAvailable = true;
	        return sensorValue;
	    }

	    if (pSMA->windowSize > 1) {
	        pSMA->sum -= pSMA->previousValue;
	        pSMA->sum += sensorValue;
	        if (pSMA->sum > (pSMA->windowSize * pSMA->scalingFactor)) {
	            pSMA->sum = pSMA->windowSize * pSMA->scalingFactor;
	        }
	    }

	    int32_t output = (pSMA->sum * pSMA->scalingFactor) / (pSMA->windowSize * pSMA->scalingFactor);
	    pSMA->previousValue = sensorValue;

	    return output;
}

