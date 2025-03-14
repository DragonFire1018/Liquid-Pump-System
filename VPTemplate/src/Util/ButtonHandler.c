/******************************************************************************
 * @file ButtenHandler.c
 *
 * @author DragonFire1018
 * @date   12.03.2025
 *
 * @copyright Copyright (c) 2025
 *
 ******************************************************************************
 *
 * @brief Implementation of button handling logic.
 *
 * @details This file contains the implementation of the button handling logic,
 *  which checks the status of buttons and performs actions when a button is pressed.
 *  It includes a function to check the button status and trigger actions accordingly.
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
