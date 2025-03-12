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
#ifndef _FILENAME_H
#define _FILENAME_H


/***** INCLUDES **************************************************************/
#include "ButtonHandler.h"
#include "Util/Sensors/FlowRateSensor.h"
#include "Util/SegmentHandler.h"
#include "SegmentHandler.h"

/***** CONSTANTS *************************************************************/


/***** MACROS ****************************************************************/


/***** TYPES *****************************************************************/


/***** PROTOTYPES ************************************************************/
void initalizeMaintenanceManager();
void maintenanceCycle();
int32_t getFlowRate();

#endif
