/******************************************************************************
 * @file ButtonHandler.h
 *
 * @author DragonFire1018
 * @date   12.03.2025
 *
 * @copyright Copyright (c) 2025
 *
 ******************************************************************************
 *
 * @brief Header for button handling logic.
 *
 * @details This header file defines the public functions and types for handling buttons,
 * 	including checking the button status and performing actions when a button is pressed.
 * 	It provides an interface for integrating button handling into a larger system.
 *
 *
 *****************************************************************************/
#ifndef _BUTTONHANDLER_H
#define _BUTTONHANDLER_H


/***** INCLUDES **************************************************************/
#include "ButtonModule.h"
/***** CONSTANTS *************************************************************/


/***** MACROS ****************************************************************/


/***** TYPES *****************************************************************/
typedef void (*ButtonAction)(int32_t);

typedef struct{
	Button_t button;
	Button_Status_t previousStatus;
	Button_Status_t pendingStatus;
	ButtonAction action;
	int32_t debounceCounter;
} ButtonInfo_t;


/***** PROTOTYPES ************************************************************/

Button_Status_t checkButtonStatus(ButtonInfo_t* buttonInfo, int32_t actionValue);

#endif
