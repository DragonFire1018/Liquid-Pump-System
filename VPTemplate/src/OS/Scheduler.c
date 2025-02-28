/******************************************************************************
 * @file Scheduler.c
 *
 * @author Andreas Schmidt (a.v.schmidt81@googlemail.com
 * @date   08.02.2025
 *
 * @copyright Copyright (c) 2025
 *
 ******************************************************************************
 *
 * @brief Implementation of the cooperative scheduler with a  pre-defined set
 * of cyclic "task slots"
 *
 *
 *****************************************************************************/


/***** INCLUDES **************************************************************/
#include "Scheduler.h"
#include "stm32g4xx_hal.h"


/***** PRIVATE CONSTANTS *****************************************************/


/***** PRIVATE MACROS ********************************************************/
#define HAL_TICK_VALUE_1MS      1       //!< Number of HAL Ticks used for 1ms Tasks
#define HAL_TICK_VALUE_10MS     10      //!< Number of HAL Ticks used for 10ms Tasks
#define HAL_TICK_VALUE_50MS    	50     //!< Number of HAL Ticks used for 50ms Tasks
#define HAL_TICK_VALUE_250MS    250     //!< Number of HAL Ticks used for 250ms Tasks
#define HAL_TICK_VALUE_1000MS   1000    //!< Number of HAL Ticks used for 1000ms Tasks


/***** PRIVATE TYPES *********************************************************/


/***** PRIVATE PROTOTYPES ****************************************************/


/***** PRIVATE VARIABLES *****************************************************/


/***** PUBLIC FUNCTIONS ******************************************************/



int32_t schedInitialize(Scheduler* pScheduler)
{
	if(pScheduler == 0)
		return SCHED_ERR_INVALID_PTR;

	pScheduler->halTick_1ms	   = 0;
	pScheduler->halTick_10ms   = 0;
	pScheduler->halTick_50ms   = 0;
	pScheduler->halTick_250ms  = 0;
	pScheduler->halTick_1000ms = 0;

	pScheduler->pTask_1ms    = 0;
	pScheduler->pTask_10ms   = 0;
	pScheduler->pTask_50ms   = 0;
	pScheduler->pTask_250ms  = 0;
	pScheduler->pTask_1000ms = 0;

    return SCHED_ERR_OK;
}


int32_t schedCycle(Scheduler* pScheduler)
{
	//Check for Null-Pointer to avoid crash when reading the actual HAL Tick
	if(pScheduler == 0)
		return SCHED_ERR_INVALID_PTR;

	uint32_t timeElapsed = 0;
	uint32_t actualTick = 0;

	//Get the current tick time and calculate the difference since the last call
	actualTick = HAL_GetTick();
	timeElapsed = schedGetElaspedTime(pScheduler->halTick_1ms, actualTick);
	if(timeElapsed >= HAL_TICK_VALUE_1MS)
	{
		pScheduler->halTick_1ms = actualTick;
		if(pScheduler->pTask_1ms != 0)
		{
			pScheduler->pTask_1ms();
		}
	}

	//Get the current tick time and calculate the difference since the last call
	actualTick = HAL_GetTick();
	timeElapsed = schedGetElaspedTime(pScheduler->halTick_10ms, actualTick);
	if(timeElapsed >= HAL_TICK_VALUE_1MS)
	{
		pScheduler->halTick_10ms = actualTick;
		if(pScheduler->pTask_10ms != 0)
		{
			pScheduler->pTask_10ms();
		}
	}

	//Get the current tick time and calculate the difference since the last call
	actualTick = HAL_GetTick();
	timeElapsed = schedGetElaspedTime(pScheduler->halTick_50ms, actualTick);
	if(timeElapsed >= HAL_TICK_VALUE_1MS)
	{
		pScheduler->halTick_50ms = actualTick;
		if(pScheduler->pTask_50ms != 0)
		{
			pScheduler->pTask_50ms();
		}
	}

	//Get the current tick time and calculate the difference since the last call
	actualTick = HAL_GetTick();
	timeElapsed = schedGetElaspedTime(pScheduler->halTick_250ms, actualTick);
	if(timeElapsed >= HAL_TICK_VALUE_1MS)
	{
		pScheduler->halTick_250ms = actualTick;
		if(pScheduler->pTask_250ms != 0)
		{
			pScheduler->pTask_250ms();
		}
	}

	//Get the current tick time and calculate the difference since the last call
	actualTick = HAL_GetTick();
	timeElapsed = schedGetElaspedTime(pScheduler->halTick_1000ms, actualTick);
	if(timeElapsed >= HAL_TICK_VALUE_1MS)
	{
		pScheduler->halTick_1000ms = actualTick;
		if(pScheduler->pTask_1000ms != 0)
		{
			pScheduler->pTask_1000ms();
		}
	}

    return SCHED_ERR_OK;
}

/***** PRIVATE FUNCTIONS *****************************************************/
static uint32_t schedGetElaspedTime(uint32_t savedTimestamp, uint32_t currentTime){
	uint32_t timeDiff = currentTime -savedTimestamp;
	return timeDiff;
}
