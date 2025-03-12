/******************************************************************************
 * @file Filter.h
 *
 * @author Andreas Schmidt (a.v.schmidt81@googlemail.com
 * @date   08.02.2025
 *
 * @copyright Copyright (c) 2025
 *
 ******************************************************************************
 *
 * @brief Header file for Filter library
 *
 *
 *****************************************************************************/
#ifndef _SMAFILTER_H_
#define _SMAFILTER_H_

/***** INCLUDES **************************************************************/
#include <stdbool.h>
#include <stdint.h>

/***** CONSTANTS *************************************************************/


/***** MACROS ****************************************************************/
#define FILTER_ERR_OK                   0       //!< No error occured
#define FILTER_ERR_GENERAL              -1      //!< General error during filter processing
#define FILTER_ERR_INVALID_PTR          -2      //!< Invalid pointer (Null Pointer)
#define FILTER_ERR_INVALID_PARAM        -3      //!< Invalid parameter value

/***** TYPES *****************************************************************/

/**
 * @brief Struct which represents a SMA filter
 *
 */
typedef struct _SMAFilterData
{
    bool firstValueAvailable;                   //!< Flag to indicate whether there was already a value set as prev value
    int32_t previousValue;                      //!< Previous value of the filter output
    int32_t scalingFactor;                      //!< Used scaling factor
    int32_t sum;                      //!< sum of all values
    int32_t windowSize;                      //!< size of the window
} SMAFilterData_t;


/***** PROTOTYPES ************************************************************/


/**
 * @brief Initialize an SMA filter with the provided parameter
 *
 * @param pSMA              Poitner to the SMA filter struct
 * @param scalingFactor     Scaling factor used for internal calculations
 * @param alpha             Already scaled alpha factor (must be scaled with same scaling factor as supplied via parameter)
 * @param resetFilter       Flag to indicate whether the filter should be reset
 *
 * @return Return FILTER_ERR_OK is no error occured
 */
int32_t filterInitSMA(SMAFilterData_t* pSMA, int32_t scalingFactor, bool resetFilter,int32_t windowSize);


/**
 * @brief Resets the SMA filter structure
 *
 * @param pSMA              Pointer to the SMA filter struct
 *
 * @return Return FILTER_ERR_OK is no error occured
 */
int32_t filterResetSMA(SMAFilterData_t* pSMA);

/**
 * @brief Performs the ESA filtering on the provided sensor value
 *
 * @param pSMA              Pointer to the SMA filter struct
 * @param sensorValue       Value which should be filtered
 *
 * @return The filtered sensor value
 */
int32_t filterSMA(SMAFilterData_t* pSMA, int32_t sensorValue);

#endif
