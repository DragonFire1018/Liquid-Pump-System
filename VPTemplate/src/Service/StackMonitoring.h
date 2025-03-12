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

/*! @brief Checks for stack overflow, returns 1 if this is the case */
_Bool isStackOverflow();

/*! @brief Counts size of free stack, returns amount in Bytes */
uint32_t countFreeStack();


#endif /* SRC_SERVICE_STACKMONITORING_H_ */
