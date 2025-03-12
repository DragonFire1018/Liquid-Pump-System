/*
 * StackMonitoring.c
 *
 *  Created on: Mar 12, 2025
 *      Author: user
 */

#include "StackMonitoring.h"

extern uint32_t _top_of_stack;
static uint32_t* pTopOfStack = (uint32_t*) &_top_of_stack;

_Bool isStackOverflow() {
	if (*pTopOfStack != 0xABABABAB) {
		return 1;
	}
	else {
		return 0;
	}
}

uint32_t countFreeStack() {
	uint32_t counter = 0;
	uint32_t* pCurrent = pTopOfStack;

	pCurrent++;

	while(*pCurrent == 0xCDCDCDCD) {
		counter++;
		pCurrent++;
	}

	return counter;
}
