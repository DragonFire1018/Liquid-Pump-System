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


/***** INCLUDES **************************************************************/
#include "MaintenanceManager.h"

/***** PRIVATE CONSTANTS *****************************************************/


/***** PRIVATE MACROS ********************************************************/


/***** PRIVATE TYPES *********************************************************/


/***** PRIVATE PROTOTYPES ****************************************************/
static void handleSW1Event();
static void handleSW2Event();

/***** PRIVATE VARIABLES *****************************************************/
static ButtonInfo_t* buttonInfoSW1;
static ButtonInfo_t* buttonInfoSW2;
static int32_t flowRate = 0;

/***** PUBLIC FUNCTIONS ******************************************************/
void initalizeMaintenanceManager(){
	buttonInfoSW1->button = BTN_SW1;
	buttonInfoSW1->previousStatus = BUTTON_RELEASED;
	buttonInfoSW1->action = handleSW1Event;

	buttonInfoSW2->button = BTN_SW2;
	buttonInfoSW2->previousStatus = BUTTON_RELEASED;
	buttonInfoSW2->action = handleSW2Event;
}
void maintenanceCycle(){
	if(flowRate == 0){
		//display "--"
	}else{
		displayDoubleDigitNumber(flowRate);
	}
}

/***** PRIVATE FUNCTIONS *****************************************************/

static void handleSW1Event(){
	//increase the flow rate by 5 L/h
	flowRate += 5;
}
static void handleSW2Event(){
	//decrease the flow rate by 5 L/h
	flowRate -= 5;
}
