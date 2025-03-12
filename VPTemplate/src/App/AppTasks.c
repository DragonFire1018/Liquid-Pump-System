/******************************************************************************
 * @file AppTasks.c
 *
 * @author Andreas Schmidt (a.v.schmidt81@googlemail.com
 * @date   08.02.2025
 *
 * @copyright Copyright (c) 2025
 *
 ******************************************************************************
 *
 * @brief Implementation File for the application tasks
 *
 *
 *****************************************************************************/


/***** INCLUDES **************************************************************/
#include "Scheduler.h"
#include "AppTasks.h"
#include "Util/Sensors/SpeedSensor.h"
#include "Util/Sensors/FlowRateSensor.h"

/***** PRIVATE CONSTANTS *****************************************************/


/***** PRIVATE MACROS ********************************************************/


/***** PRIVATE TYPES *********************************************************/


/***** PRIVATE PROTOTYPES ****************************************************/


/***** PRIVATE VARIABLES *****************************************************/


/***** PUBLIC FUNCTIONS ******************************************************/

/**
 * @brief Analog and Digital Input Processing
 */
void taskApp10ms()
{
	speedSensorCycle();
	flowRateSensorCycle();
}

/**
 * @brief Main Application and State Machine
 */
void taskApp50ms()
{
	sampleAppRun();
}

/**
 * @brief Health-Monitoring (Stack-Monitoring)
 */
void taskApp250ms()
{
	isStackOverflow();
	countFreeStack();
}


/***** PRIVATE FUNCTIONS *****************************************************/




