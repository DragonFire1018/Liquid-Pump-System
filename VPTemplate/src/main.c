/******************************************************************************
 * @file main.c
 *
 * @author Andreas Schmidt (a.v.schmidt81@googlemail.com
 * @date   08.02.2025
 *
 * @copyright Copyright (c) 2025
 *
 ******************************************************************************
 *
 * @brief Main file for the VP Template project
 *
 *
 *****************************************************************************/


/***** INCLUDES **************************************************************/
#include "stm32g4xx_hal.h"
#include "System.h"

#include "Util/Global.h"
#include "Util/printf.h"
#include "LogOutput.h"

#include "UARTModule.h"
#include "ButtonModule.h"
#include "LEDModule.h"
#include "ADCModule.h"
#include "TimerModule.h"
//#include "DisplayModule.h"
#include "Scheduler.h"
#include "StackMonitoring.h"

#include "GlobalObjects.h"
#include "AppTasks.h"


/***** PRIVATE CONSTANTS *****************************************************/


/***** PRIVATE MACROS ********************************************************/

/***** PRIVATE MACROS ********************************************************/


/***** PRIVATE TYPES *********************************************************/


/***** PRIVATE PROTOTYPES ****************************************************/
static int32_t initializePeripherals();


/***** PRIVATE VARIABLES *****************************************************/
static Scheduler gScheduler;            // Global Scheduler instance


/***** PUBLIC FUNCTIONS ******************************************************/

/**

 * @brief Analog and Digital Input Processing
 */
void runAnalogDigitalInputProccessing()
{
	//speedSensorCycle();
	//flowRatespeedSensorCycle();
}
/**
 * @brief Main Application and State Machine
 */
void runStateMachine()
{
	//sampleAppRun();
}
/**
 * @brief Health-Monitoring (Stack-Monitoring)
 */
void runHealthMonitoring()
{

}

/**
>>>>>>> c43be31da453cdc527f09d670ed3557edcfc244c
 * @brief Main function of System
 */
int main(void)
{
    // Initialize the HAL
    HAL_Init();

    SystemClock_Config();

    // Initialize Peripherals
    initializePeripherals();

    // Initialize Scheduler
    schedInitialize(&gScheduler);


    // Prepare Scheduler
    gScheduler.pGetHALTick = HAL_GetTick;
    gScheduler.pTask_10ms = taskApp10ms;
    gScheduler.pTask_50ms = taskApp50ms;
    gScheduler.pTask_250ms = taskApp250ms;

    while (1)
    {
        // Call the Scheduler
        schedCycle(&gScheduler);
    }
}



/***** PRIVATE FUNCTIONS *****************************************************/

/**
 * @brief Initializes the used peripherals like GPIO,
 * ADC, DMA and Timer Interrupts
 *
 * @return Returns ERROR_OK if no error occurred
 */
static int32_t initializePeripherals()
{
    // Initialize UART used for Debug-Outputs
    uartInitialize(115200);

    // Initialize GPIOs for Buttons
    buttonInitialize();

    // Initialize GPIOs for LED and 7-Segment output
    ledInitialize();
    displayInitialize();

    // Initialize Timer, DMA and ADC for sensor measurements
    timerInitialize();
    adcInitialize();

    // Initialize Application
    sampleAppInitialize();

    return ERROR_OK;
}
