/******************************************************************************
 * @file MaintenanceManager.h
 *
 * @author DragonFie1018
 * @date   12.03.2025
 *
 * @copyright Copyright (c) 2025
 *
 ******************************************************************************
 *
 * @brief Header for the maintenance manager to control flow rate.
 *
 * @details This header file defines the public functions of the maintenance manager,
 *  which are used for initialization, running the maintenance cycle, and returning the current flow rate.
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
