/*
 * StackMonitoring.c
 *
 *  Created on: Mar 12, 2025
 *      Author: user
 */

#include "StackMonitoring.h"
#include "LogOutput.h"

extern uint32_t _top_of_stack;
static uint32_t* pTopOfStack = (uint32_t*) &_top_of_stack;
extern uint32_t _bottom_of_stack;
static uint32_t* pBottomOfStack = (uint32_t*) &_bottom_of_stack;
static _Bool isOverflow = 0;

void checkOverflow() {
	if (*pTopOfStack != 0xABABABAB) {
		isOverflow = 1;
	}
	else {
		isOverflow = 0;
	}
}

_Bool isStackOverflow() {
	return isOverflow;
}

void countFreeStack() {
	uint32_t counter = 0;
	uint32_t* pCurrent = pTopOfStack;

	pCurrent++;

	while(pCurrent <= pBottomOfStack) {
		if (*pCurrent == 0xCDCDCDCD) {
			counter++;
		}
		pCurrent++;
	}

	outputLogf("\n\rFree Stack: %d Bytes", counter);
}
