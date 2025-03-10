/*
 * FowRateSensor.h
 *
 *  Created on: 10.03.2025
 *      Author: drago
 */

#ifndef SRC_UTIL_SENSORS_FOWRATESENSOR_H_
#define SRC_UTIL_SENSORS_FOWRATESENSOR_H_


int32_t flowRateSensorInitialize();

int32_t flowRatespeedSensorCycle();

int32_t flowRatespeedSensorGetSpeed();

static int32_t sensorCalculateFlowRate(int32_t inputVoltage);


#endif /* SRC_UTIL_SENSORS_FOWRATESENSOR_H_ */
