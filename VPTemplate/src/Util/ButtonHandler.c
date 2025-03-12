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
#include "ButtonHandler.h"

/***** PRIVATE CONSTANTS *****************************************************/


/***** PRIVATE MACROS ********************************************************/


/***** PRIVATE TYPES *********************************************************/


/***** PRIVATE PROTOTYPES ****************************************************/


/***** PRIVATE VARIABLES *****************************************************/

/***** PUBLIC FUNCTIONS ******************************************************/

Button_Status_t checkButtonStatus(ButtonInfo_t* buttonInfo, int32_t actionValue){
	Button_Status_t currentStatus = buttonGetButtonStatus(buttonInfo->button);

	// Check condition change from not pressed to pressed
	if (currentStatus == BUTTON_PRESSED && buttonInfo->previousStatus == BUTTON_RELEASED){
	    // Perform action
	    buttonInfo->action(actionValue);
	}

	// Update previous status
	return currentStatus;
}
/***** PRIVATE FUNCTIONS *****************************************************/
