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
#include "Util/ButtonHandler.h"


/***** PRIVATE CONSTANTS *****************************************************/


/***** PRIVATE MACROS ********************************************************/


/***** PRIVATE TYPES *********************************************************/


/***** PRIVATE PROTOTYPES ****************************************************/
// State realte functions (on-Entry, on-State and on-Exit)
static int32_t onEntryBootUp(State_t* pState, int32_t eventID);
static int32_t onStateOperational(State_t* pState, int32_t eventID);
static int32_t onExitOperational(State_t* pState, int32_t eventID);
static int32_t onStateMaintenance(State_t* pState, int32_t eventID);
static int32_t onExitMaintenance(State_t* pState, int32_t eventID);
static int32_t onEntryFailure(State_t* pState, int32_t eventID);
static int32_t onEntryOperational(State_t* pState, int32_t eventID);
static int32_t onEntryMaintenance(State_t* pState, int32_t eventID);
static void buttonB1Handler(int32_t eventID);

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
    {STATE_ID_BOOTUP, 				onEntryBootUp,  			 				0,                     0,  		false},
    {STATE_ID_OPERATIONAL, 	   onEntryOperational,             onStateOperational,     onExitOperational,  		false},
	{STATE_ID_MAINTENANCE, 	   onEntryMaintenance,             onStateMaintenance,     onExitMaintenance,  		false},
    {STATE_ID_FAILURE, 	   	   	   onEntryFailure,  							0,                     0,  		false}
};

/**
 * @brief Definition of the transistion table of the state machine. Each row
 * contains FROM_STATE_ID, TO_STATE_ID, EVENT_ID, Function Pointer Guard Function
 *
 * The last two members of a transistion row are only the initialization of dynamic
 * members used during runtime
 */
static StateTableEntry_t gStateTableEntries[] =
{
    {STATE_ID_BOOTUP,          		STATE_ID_OPERATIONAL,           EVT_ID_SYSTEM_OK,          		0,      0,      0},
    {STATE_ID_OPERATIONAL,          STATE_ID_MAINTENANCE,           EVT_ID_ENTER_MAINTENANCE,       0,      0,      0},
    {STATE_ID_MAINTENANCE,          STATE_ID_OPERATIONAL,           EVT_ID_LEAVE_MAINTENANCE,       0,      0,      0},
    {STATE_ID_BOOTUP,          		STATE_ID_FAILURE,           	EVT_ID_SYSTEM_FAILED,          	0,      0,      0},
    {STATE_ID_OPERATIONAL,          STATE_ID_FAILURE,           	EVT_ID_SYSTEM_FAILED,       	0,      0,      0}
};

/**
 * @brief Global State Table instance
 *
 */
static ButtonInfo_t buttonInfoB1;
static StateTable_t gStateTable;

static bool isSystemFailure = false;


/***** PUBLIC FUNCTIONS ******************************************************/

int32_t sampleAppInitialize()
{
    gStateTable.pStateList = gStateList;
    gStateTable.stateCount = sizeof(gStateList) / sizeof(State_t);
    int32_t result = stateTableInitialize(&gStateTable, gStateTableEntries, sizeof(gStateTableEntries) / sizeof(StateTableEntry_t), STATE_ID_BOOTUP);
    buttonInfoB1.button = BTN_B1;
    buttonInfoB1.previousStatus = BUTTON_RELEASED;
    buttonInfoB1.action = buttonB1Handler;
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
	outputLog("Enter BootUp State");
	flowRateSensorInitialize();
	speedSensorInitialize();
	if((speedSensorGetSpeed() >= MIN_REVOLUTIONS && speedSensorGetSpeed() <= MAX_LITER_PER_HOUR)
			&& (flowRateSensorGetFlowRate() >= MIN_LITER_PER_HOUR && flowRateSensorGetFlowRate() <= MAX_LITER_PER_HOUR)){
		initalizeMaintenanceManager();
		initalizeMotor();
		sameplAppSendEvent(EVT_ID_SYSTEM_OK);
	}
	else
	{
		sameplAppSendEvent(EVT_ID_SYSTEM_FAILED);
	}

    return 0;
}

static int32_t onStateOperational(State_t* pState, int32_t eventID)
{
	ledSetLED(LED0,LED_ON);
	buttonInfoB1.previousStatus = checkButtonStatus(&buttonInfoB1,EVT_ID_ENTER_MAINTENANCE);
	bool motorCycleStatus = motorCycle();
	if(!motorCycleStatus){
		sameplAppSendEvent(EVT_ID_SYSTEM_FAILED);
	}
	//if(isStackOverflow()){
	//	isSystemFailure = true;
	//	sameplAppSendEvent(EVT_ID_SYSTEM_FAILED);
	//}
    return 0;
}

static int32_t onExitOperational(State_t* pState, int32_t eventID)
{
	outputLog("Exit Operational State");
	ledSetLED(LED0,LED_OFF);
    return 0;
}
static int32_t onStateMaintenance(State_t* pState, int32_t eventID)
{
	ledToggleLED(LED0);
	buttonInfoB1.previousStatus = checkButtonStatus(&buttonInfoB1,EVT_ID_LEAVE_MAINTENANCE);
	maintenanceCycle();
    return 0;
}

static int32_t onExitMaintenance(State_t* pState, int32_t eventID)
{
	outputLog("Exit Maintenance State");
	ledSetLED(LED0,LED_OFF);
    return 0;
}

static int32_t onEntryFailure(State_t* pState, int32_t eventID)
{
	outputLog("Enter Failure State");
	stopMotor();
	if(isSystemFailure){
		ledSetLED(LED2,LED_ON);
	}else{
		ledSetLED(LED4,LED_ON);
	}
    return 0;
}
static void buttonB1Handler(int32_t eventID){
	if(eventID == EVT_ID_ENTER_MAINTENANCE){
		sameplAppSendEvent(EVT_ID_ENTER_MAINTENANCE);
	}
	if(eventID == EVT_ID_LEAVE_MAINTENANCE){
		sameplAppSendEvent(EVT_ID_LEAVE_MAINTENANCE);
	}
}
static int32_t onEntryOperational(State_t* pState, int32_t eventID){
	outputLog("Enter Operational State");
	return 0;
}
static int32_t onEntryMaintenance(State_t* pState, int32_t eventID){
	outputLog("Enter Maintenance State");
	return 0;
}

