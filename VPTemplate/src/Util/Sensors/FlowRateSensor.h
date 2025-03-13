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

#define MIN_LITER_PER_HOUR			0					// Min revolutions 0 L/h
#define MAX_LITER_PER_HOUR			80					// Max revolutions 80 L/h

#define MIN_OUTPUT_MICRO_VOLTAGE 500000 				//Min output voltage 0.5
#define MAX_OUTPUT_MICRO_VOLTAGE 2500000 				//Max output voltage 2.5

int32_t flowRateSensorInitialize();

int32_t flowRateSensorCycle();

int32_t flowRateSensorGetFlowRate();

static int32_t sensorCalculateFlowRate(int32_t inputVoltage);



#endif /* SRC_UTIL_SENSORS_FLOWRATESENSOR_H_ */
