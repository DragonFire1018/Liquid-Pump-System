/******************************************************************************
 * @file SegementHandler.h
 *
 * @author DragonFire1018
 * @date   12.03.2025
 *
 * @copyright Copyright (c) 2025
 *
 ******************************************************************************
 *
 * @brief Header for the segment handler to display double-digit numbers.
 *
 * @details This header file defines the public functions and
 *  types for displaying double-digit numbers on a two-digit display.
 *  It provides an interface for integrating the display logic into a larger system.
 *
 *
 *****************************************************************************/

#ifndef SRC_UTIL_SEGMENTHANDLER_H_
#define SRC_UTIL_SEGMENTHANDLER_H_


/***** INCLUDES **************************************************************/

#include "DisplayModule.h"

/***** DEFINES *************************************************************/

#define DISPLAY_NO_MOTOR_SPEED -1
#define DISPLAY_NO_FLOW_RATE   -2

/***** TYPES *****************************************************************/

typedef enum ADC_TYPE
{
   FLOW_RATE,
   SPEED
} ADC_TYPE;

/***** PROTOTYPES ************************************************************/

void displayDoubleDigitNumber(int16_t number,ADC_TYPE adcType);

#endif
