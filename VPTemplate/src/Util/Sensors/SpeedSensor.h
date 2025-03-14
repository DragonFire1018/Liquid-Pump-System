/******************************************************************************
 * @file SpeedSensor.h
 *
 * @author DragonFire1018
 * @date   11.03.2025
 *
 * @copyright Copyright (c) 2025
 *
 ******************************************************************************
 *
 * @brief Header for the speed sensor using an ADC and EMA filter.
 *
 * @details This header file defines the public functions for the speed sensor,
 *  including initialization, running the sensor cycle, and retrieving the current speed.
 *  It provides an interface for integrating the sensor into a larger system.
 *
 *
 *****************************************************************************/

#ifndef SRC_UTIL_SENSORS_SPEEDSENSOR_H_
#define SRC_UTIL_SENSORS_SPEEDSENSOR_H_

/***** INCLUDES **************************************************************/
#include "stm32g4xx_hal.h"
#include "System.h"

/***** DEFINES ************************************************************/
#define MIN_REVOLUTIONS			0			// Min revolutions 0rpm
#define MAX_REVOLUTIONS			1000		// Max revolutions 1000rpm

#define MIN_OUTPUT_MICRO_VOLTAGE 500000 				//Min output voltage 0.5
#define MAX_OUTPUT_MICRO_VOLTAGE 2500000				//Max output voltage 2.5

/***** PROTOTYPES ************************************************************/

int32_t speedSensorInitialize();

int32_t speedSensorCycle();

int32_t speedSensorGetSpeed();


#endif /* SRC_UTIL_SENSORS_SPEEDSENSOR_H_ */
