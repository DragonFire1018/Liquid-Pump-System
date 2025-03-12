/*
 * FlowRateSensor.h
 *
 *  Created on: Mar 12, 2025
 *      Author: user
 */

#ifndef SRC_UTIL_SENSORS_FLOWRATESENSOR_H_
#define SRC_UTIL_SENSORS_FLOWRATESENSOR_H_

#include "stm32g4xx_hal.h"
#include "System.h"

int32_t flowRateSensorInitialize();

int32_t flowRateSensorCycle();

int32_t flowRateSensorGetFlowRate();

static int32_t sensorCalculateFlowRate(int32_t inputVoltage);



#endif /* SRC_UTIL_SENSORS_FLOWRATESENSOR_H_ */
