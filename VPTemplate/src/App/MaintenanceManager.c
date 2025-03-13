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

/***** PRIVATE DEFINES *****************************************************/

#define MAX_FLOW_RATE 80
#define MIN_FOW_RATE 0
#define RANGE_VALUE 5

/***** PRIVATE CONSTANTS *****************************************************/


/***** PRIVATE MACROS ********************************************************/


/***** PRIVATE TYPES *********************************************************/


/***** PRIVATE PROTOTYPES ****************************************************/
static void handleSW1Event();
static void handleSW2Event();

/***** PRIVATE VARIABLES *****************************************************/
static ButtonInfo_t buttonInfoSW1;
static ButtonInfo_t buttonInfoSW2;
static int32_t flowRate;

/***** PUBLIC FUNCTIONS ******************************************************/
void initalizeMaintenanceManager(){
	flowRate = 0;
	buttonInfoSW1.button = BTN_SW1;
	buttonInfoSW1.previousStatus = BUTTON_RELEASED;
	buttonInfoSW1.action = handleSW1Event;

	buttonInfoSW2.button = BTN_SW2;
	buttonInfoSW2.previousStatus = BUTTON_RELEASED;
	buttonInfoSW2.action = handleSW2Event;
}
void maintenanceCycle(){
	checkButtonStatus(&buttonInfoSW1,0);
	checkButtonStatus(&buttonInfoSW2,0);
	if(flowRate <= MIN_FOW_RATE){
		//display "--"
		displayDoubleDigitNumber(DISPLAY_NO_FLOW_RATE,FLOW_RATE);
	}else{
		displayDoubleDigitNumber(flowRate,FLOW_RATE);
	}
}
int32_t getFlowRate(){
	return flowRate;
}
/***** PRIVATE FUNCTIONS *****************************************************/

static void handleSW1Event(){
	//increase the flow rate by 5 L/h
	if((flowRate+RANGE_VALUE) <= MAX_FLOW_RATE){
		flowRate += RANGE_VALUE;
	}
}
static void handleSW2Event(){
	//decrease the flow rate by 5 L/h
	if((flowRate-RANGE_VALUE) >= MIN_FOW_RATE){
			flowRate -= RANGE_VALUE;
	}
}
