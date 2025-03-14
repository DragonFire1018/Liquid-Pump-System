/******************************************************************************
 * @file Motor.h
 *
 * @author DragonFire1018
 * @date   10.03.2025
 *
 * @copyright Copyright (c) 2025
 *
 ******************************************************************************
 *
 * @brief Interface for motor control logic with speed and flow rate monitoring.
 *
 * @details This header file defines the public functions for motor control,
 *  including initialization, starting and stopping the motor, and running the motor cycle.
 *  It provides an interface for managing motor status and handling warnings based on speed thresholds.
 *
 *
 *****************************************************************************/
#ifndef _MOTOR_H
#define _MOTOR_H


/***** INCLUDES **************************************************************/
#include "Util/ButtonHandler.h"
#include <stdbool.h>
#include "Util/Sensors/SpeedSensor.h"
#include "Util/Sensors/FlowRateSensor.h"
#include "LEDModule.h"
#include "SegmentHandler.h"
#include "MaintenanceManager.h"
#include "Service/Util/LogOutput.h"
#include "DebugMode.h"

/***** CONSTANTS *************************************************************/


/***** MACROS ****************************************************************/


/***** TYPES *****************************************************************/


/***** PROTOTYPES ************************************************************/
void initalizeMotor();

void startMotor();

bool motorCycle();

void stopMotor();

#endif
