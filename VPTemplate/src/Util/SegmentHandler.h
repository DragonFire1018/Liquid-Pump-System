/*
 * SegmentHandler.h
 *
 *  Created on: 12.03.2025
 *      Author: drago
 */

#ifndef SRC_UTIL_SEGMENTHANDLER_H_
#define SRC_UTIL_SEGMENTHANDLER_H_
#include "DisplayModule.h"

#define DISPLAY_NO_MOTOR_SPEED -1
#define DISPLAY_NO_FLOW_RATE   -2

typedef enum ADC_TYPE
{
   FLOW_RATE,
   SPEED
} ADC_TYPE;

void displayDoubleDigitNumber(int16_t number,ADC_TYPE adcType);
#endif /* SRC_UTIL_SEGMENTHANDLER_H_ */
