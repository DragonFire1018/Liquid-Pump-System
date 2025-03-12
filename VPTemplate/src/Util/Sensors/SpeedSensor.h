/*
 * SpeedSensor.h
 *
 *  Created on: 05.03.2025
 *      Author: drago
 */

#ifndef SRC_UTIL_SENSORS_SPEEDSENSOR_H_
#define SRC_UTIL_SENSORS_SPEEDSENSOR_H_

/***** INCLUDES **************************************************************/
#include "stm32g4xx_hal.h"
#include "System.h"

#define MIN_REVOLUTIONS			0			// Min revolutions 0rpm
#define MAX_REVOLUTIONS			1000		// Max revolutions 1000rpm

int32_t speedSensorInitialize();

int32_t speedSensorCycle();

int32_t speedSensorGetSpeed();

static int32_t sensorCalculateSpeed(int32_t inputVoltage);


#endif /* SRC_UTIL_SENSORS_SPEEDSENSOR_H_ */
