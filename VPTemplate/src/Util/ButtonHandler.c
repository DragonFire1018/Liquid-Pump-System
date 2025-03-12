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

void checkButtonStatus(ButtonInfo_t* buttonInfo){
	Button_Status_t currentStatus = buttonGetButtonStatus(buttonInfo->button);

	// Check condition change from not pressed to pressed
	if (currentStatus == BUTTON_PRESSED && buttonInfo->previousStatus == BUTTON_RELEASED) {
	    // Perform action
	    buttonInfo->action();
	}

	// Update previous status
	buttonInfo->previousStatus = currentStatus;
}
/***** PRIVATE FUNCTIONS *****************************************************/
