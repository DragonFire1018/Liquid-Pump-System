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
	ButtonAction action;
} ButtonInfo_t;


/***** PROTOTYPES ************************************************************/

void checkButtonStatus(ButtonInfo_t* buttonInfo, int32_t actionValue);

#endif
