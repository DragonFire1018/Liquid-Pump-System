/******************************************************************************
 * @file DebugMode.h
 *
 * @author DragonFire1018
 * @date   13.03.2025
 *
 * @copyright Copyright (c) 2025
 *
******************************************************************************
 *
 * @brief Header file for controlling debug modes and monitoring functions.
 *
 * @details This file contains preprocessor defines to enable or disable specific features in the code.
 * These include outputting runtime warnings to the serial terminal and monitoring for stack overflows.
 *
 *
 *****************************************************************************/

#ifndef SRC_APP_DEBUGMODE_H_
#define SRC_APP_DEBUGMODE_H_

/***** DEFINES **************************************************************/

/*! 1 to enable output of runtime warnings to serial terminal */
#define DEBUG_MODE 1

/*! 1 to enable detection of stack overflow */
#define STACK_OVERFLOW_MONITORING 0


#endif /* SRC_APP_DEBUGMODE_H_ */
