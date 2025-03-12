/******************************************************************************
 * @file <Filename>.h
 *
 * @author <Author>
 * @date   <Date>
 *
 * @copyright Copyright (c) 2025
 *
 ******************************************************************************
 *
 * @brief <Some short descrition>
 *
 * @details <A more detailed description>
 *
 *
 *****************************************************************************/
#ifndef SRC_UTIL_SENSORS_FOWRATESENSOR_H_
#define SRC_UTIL_SENSORS_FOWRATESENSOR_H_


/***** INCLUDES **************************************************************/
#include "stm32g4xx_hal.h"
#include "System.h"

/***** CONSTANTS *************************************************************/


/***** MACROS ****************************************************************/


/***** TYPES *****************************************************************/


/***** PROTOTYPES ************************************************************/


int32_t flowRateSensorInitialize();

int32_t flowRateSensorCycle();

int32_t flowRateSensorGetFlowRate();


#endif /* SRC_UTIL_SENSORS_FOWRATESENSOR_H_ */
