/*
 * StackMonitoring.h
 *
 *  Created on: Mar 12, 2025
 *      Author: user
 *
 * @brief Includes functions to monitor stack health (overflow and amount of free stack)
 */

#ifndef SRC_SERVICE_STACKMONITORING_H_
#define SRC_SERVICE_STACKMONITORING_H_

#include <stdint.h>

/* @brief Checks for a stack overflow */
void checkOverflow();

/* @brief Returns 1 if a stack overflow has been detected */
_Bool isStackOverflow();

/* @brief Counts size of free stack, sends amount in Bytes to a terminal */
void countFreeStack();


#endif /* SRC_SERVICE_STACKMONITORING_H_ */
