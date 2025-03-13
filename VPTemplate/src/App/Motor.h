/******************************************************************************
 * @file Motor.h
 *
 * @author drago
 * @date   10.03.2025
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

/***** CONSTANTS *************************************************************/


/***** MACROS ****************************************************************/


/***** TYPES *****************************************************************/


/***** PROTOTYPES ************************************************************/
void initalizeMotor();
void startMotor();
bool motorCycle();
void stopMotor();

#endif
