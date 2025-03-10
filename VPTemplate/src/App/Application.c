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
 * @brief Implementation file for main application (state machine)
 *
 *
 *****************************************************************************/


/***** INCLUDES **************************************************************/
#include <string.h>

#include "Application.h"
#include "Util/Global.h"
#include "Util/printf.h"

#include "UARTModule.h"
#include "ButtonModule.h"
#include "LEDModule.h"

#include "Util/StateTable/StateTable.h"


/***** PRIVATE CONSTANTS *****************************************************/


/***** PRIVATE MACROS ********************************************************/


/***** PRIVATE TYPES *********************************************************/


/***** PRIVATE PROTOTYPES ****************************************************/
// State realte functions (on-Entry, on-State and on-Exit)
static int32_t onEntryStartup(State_t* pState, int32_t eventID);
static int32_t onStateRunning(State_t* pState, int32_t eventID);
static int32_t onStateMaintenance(State_t* pState, int32_t eventID);
static int32_t onExitMaintenance(State_t* pState, int32_t eventID);
static int32_t onEntryFailure(State_t* pState, int32_t eventID);

/***** PRIVATE VARIABLES *****************************************************/

/**
 * @brief List of State for the State Machine
 *
 * This list only constructs the state objects for each possible state
 * in the state machine. There are no transistions or events defined
 *
 */
static State_t gStateList[] =
{
    {STATE_ID_BOOTUP, 		onEntryBootUp,  			 				0,                     0,  		false},
    {STATE_ID_OPERATIONAL, 				0,             onStateOperational,     onExitOperational,  		false},
	{STATE_ID_MAINTENANCE, 				0,             onStateMaintenance,     onExitMaintenance,  		false},
    {STATE_ID_FAILURE, 	   onEntryFailure,  							0,                     0,  		false}
};

/**
 * @brief Definition of the transistion table of the state machine. Each row
 * contains FROM_STATE_ID, TO_STATE_ID, EVENT_ID, Function Pointer Guard Function
 *
 * The last two members of a transistion row are only the initialization of dynamic
 * members used durin runtim
 */
static StateTableEntry_t gStateTableEntries[] =
{
    {STATE_ID_BOOTUP,          		STATE_ID_OPERATIONAL,           EVT_ID_SYSTEM_OK,          		0,      0,      0},
    {STATE_ID_OPERATIONAL,          STATE_ID_MAINTENANCE,           EVT_ID_ENTER_MAINTENANCE,       0,      0,      0},
    {STATE_ID_MAINTENANCE,          STATE_ID_OPERATIONAL,           EVT_ID_LEAVE_MAINTENANCE,       0,      0,      0},
    {STATE_ID_BOOTUP,          		STATE_ID_FAILURE,           	EVT_ID_SENSOR_FAILED,          	0,      0,      0},
    {STATE_ID_OPERATIONAL,          STATE_ID_FAILURE,           	EVT_ID_SENSOR_FAILED,       	0,      0,      0}
};

/**
 * @brief Global State Table instance
 *
 */
static StateTable_t gStateTable;


/***** PUBLIC FUNCTIONS ******************************************************/

int32_t sampleAppInitialize()
{
    gStateTable.pStateList = gStateList;
    gStateTable.stateCount = sizeof(gStateList) / sizeof(State_t);
    int32_t result = stateTableInitialize(&gStateTable, gStateTableEntries, sizeof(gStateTableEntries) / sizeof(StateTableEntry_t), STATE_ID_BOOTUP);

    return result;
}

int32_t sampleAppRun()
{
    int32_t result = stateTableRunCyclic(&gStateTable);
    return result;
}

int32_t sameplAppSendEvent(int32_t eventID)
{
    int32_t result = stateTableSendEvent(&gStateTable, eventID);
    return result;
}


/***** PRIVATE FUNCTIONS *****************************************************/

static int32_t onEntryBootUp(State_t* pState, int32_t eventID)
{
	// Perform Sensor and System checks
	//if successfull trigger EVT_ID_SYSTEM_OK
	sameplAppSendEvent(EVT_ID_SYSTEM_OK);
    //else trigger EVT_ID_SENSOR_FAILED
    sameplAppSendEvent(EVT_ID_SENSOR_FAILED);

    return 0;
}

static int32_t onStateOperational(State_t* pState, int32_t eventID)
{
	//turn LED D0 on


	//if B1 was pressed enter Maintenance State
	sameplAppSendEvent(EVT_ID_ENTER_MAINTENANCE);

	//if the Sensors has an Error
	sameplAppSendEvent(EVT_ID_SENSOR_FAILED);
    return 0;
}

static int32_t onExitOperational(State_t* pState, int32_t eventID)
{
	//Do thinks while exit Operational

	//turn LED D0 off
    return 0;
}
static int32_t onStateMaintenance(State_t* pState, int32_t eventID)
{
	//Flashing LED D0

	//if B1 was pressed leave Maintenance State
	sameplAppSendEvent(EVT_ID_LEAVE_MAINTENANCE);
    return 0;
}

static int32_t onExitMaintenance(State_t* pState, int32_t eventID)
{
	//Do thinks while exit Maintenance


	//Stop Flashing LED D0
    return 0;
}

static int32_t onEntryFailure(State_t* pState, int32_t eventID)
{
	//Perform Failure logic

	//Turn of the motor

	//if System Failure turn LED D2 on
	//else
	//turn LED D4 on
    return 0;
}
