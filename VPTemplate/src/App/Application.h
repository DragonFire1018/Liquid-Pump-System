/******************************************************************************
 * @file Application.h
 *
 * @author Andreas Schmidt (a.v.schmidt81@googlemail.com
 * @date   08.02.2025
 *
 * @copyright Copyright (c) 2025
 *
 ******************************************************************************
 *
 * @brief Header file for main application (state machine)
 *
 *
 *****************************************************************************/
#ifndef _APPLICATION_H_
#define _APPLICATION_H_

/***** INCLUDES **************************************************************/
#include <stdint.h>
#include "Motor.h"
#include "MaintenanceManager.h"
#include "StackMonitoring.h"
#include "ButtonHandler.h"
#include "Util/Sensors/SpeedSensor.h"
#include "Util/Sensors/FlowRateSensor.h"
#include "ADCModule.h"
#include "Service/Util/LogOutput.h"
#include "DebugMode.h"


/***** CONSTANTS *************************************************************/


/***** MACROS ****************************************************************/
#define STATE_ID_BOOTUP        			1       //!< Example State for Startup
#define STATE_ID_OPERATIONAL        	2       //!< Example State for Running
#define STATE_ID_MAINTENANCE       		3       //!< Example State for Maintenance
#define STATE_ID_FAILURE        		4       //!< Example State for Failure

#define EVT_ID_SYSTEM_OK       	 	1      //!< Event ID for System OK
#define EVT_ID_SYSTEM_FAILED     	2      //!< Event ID for Sensor Failure
#define EVT_ID_ENTER_MAINTENANCE 	3		//!< Event ID for Enter Maintenance
#define EVT_ID_LEAVE_MAINTENANCE 	4		//!< Event ID for LEAVE MAINTENANCE


/***** TYPES *****************************************************************/


/***** PROTOTYPES ************************************************************/

int32_t sampleAppInitialize();

int32_t sampleAppRun();

int32_t sameplAppSendEvent(int32_t eventID);

#endif
