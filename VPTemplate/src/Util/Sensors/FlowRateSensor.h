/******************************************************************************
 * @file FlowRateSensor.h
 *
 * @author DragonFire1018
 * @date   11.03.2025
 *
 * @copyright Copyright (c) 2025
 *
 ******************************************************************************
 *
  * @brief Header for the flow rate sensor using an ADC and SMA filter.
 *
 * @details This header file defines the public functions for the flow rate sensor,
 *  including initialization, running the sensor cycle, and retrieving the current flow rate.
 *  It provides an interface for integrating the sensor into a larger system.
 *
 *
 *****************************************************************************/

#ifndef SRC_UTIL_SENSORS_FLOWRATESENSOR_H_
#define SRC_UTIL_SENSORS_FLOWRATESENSOR_H_

/***** INCLUDES **************************************************************/

#include "stm32g4xx_hal.h"
#include "System.h"

/***** DEFINES **************************************************************/

#define MIN_LITER_PER_HOUR			0					// Min revolutions 0 L/h
#define MAX_LITER_PER_HOUR			80					// Max revolutions 80 L/h

#define MIN_OUTPUT_MICRO_VOLTAGE 500000 				//Min output voltage 0.5
#define MAX_OUTPUT_MICRO_VOLTAGE 2500000 				//Max output voltage 2.5

/***** PROTOTYPES ************************************************************/

int32_t flowRateSensorInitialize();

int32_t flowRateSensorCycle();

int32_t flowRateSensorGetFlowRate();



#endif /* SRC_UTIL_SENSORS_FLOWRATESENSOR_H_ */
