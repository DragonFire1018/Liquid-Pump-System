/*
 * SegementHandler.c
 *
 *  Created on: 12.03.2025
 *      Author: drago
 */

#include "SegmentHandler.h"
static Display_t currentSide = LEFT_DISPLAY;

void displayDoubleDigitNumber(int16_t number,ADC_TYPE adcType){
	uint16_t firstPart;
	uint16_t secondPart;
	if(number == DISPLAY_NO_MOTOR_SPEED)
	{
		firstPart = DIGIT_LOWER_O;
		secondPart = DIGIT_LOWER_O;
	}else if(number == DISPLAY_NO_FLOW_RATE){
			firstPart = DIGIT_DASH;
			secondPart = DIGIT_DASH;
	}else{
		if (number >= 100 || adcType == SPEED) {
			number = number / 10;
		}
		firstPart = number / 10;
		secondPart = number % 10;
	}


	if(currentSide == LEFT_DISPLAY){
		displayShowDigit(RIGHT_DISPLAY,secondPart);
		currentSide = RIGHT_DISPLAY;
	}else{
		displayShowDigit(LEFT_DISPLAY,firstPart);
		currentSide = LEFT_DISPLAY;
	}
}

