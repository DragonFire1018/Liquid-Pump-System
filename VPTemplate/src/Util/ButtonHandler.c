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

#define DEBOUNCE_DELAY_COUNT 1

/***** PRIVATE TYPES *********************************************************/


/***** PRIVATE PROTOTYPES ****************************************************/


/***** PRIVATE VARIABLES *****************************************************/

/***** PUBLIC FUNCTIONS ******************************************************/

Button_Status_t checkButtonStatus(ButtonInfo_t* buttonInfo, int32_t actionValue){
	Button_Status_t currentStatus = buttonGetButtonStatus(buttonInfo->button);

	/* Check condition change */
	if (currentStatus != buttonInfo->previousStatus) {
	    /* Reset counter */
		buttonInfo->debounceCounter = 0;
		/* Return old status */
		//return buttonInfo->previousStatus;
	}
	if (buttonInfo->debounceCounter > DEBOUNCE_DELAY_COUNT) {
		if (currentStatus != buttonInfo->pendingStatus) {
			/* Update pending status */
			buttonInfo->pendingStatus = currentStatus;
			/* Only perform action if button is pressed */
			if (buttonInfo->pendingStatus == BUTTON_PRESSED) {
				/* Perform action */
			    buttonInfo->action(actionValue);
			}
		}
	}
	/* Count up */
	buttonInfo->debounceCounter++;
	/* Update previous status */
	return currentStatus;
}

/***** PRIVATE FUNCTIONS *****************************************************/
