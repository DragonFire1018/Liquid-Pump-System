/******************************************************************************
 * @file Motor.c
 *
 * @author DragonFire1018
 * @date   12.03.2025
 *
 * @copyright Copyright (c) 2025
 *
 ******************************************************************************
 *
  * @brief Implementation of motor control logic with speed and flow rate monitoring.
 *
 * @details This file contains the implementation of the motor control logic,
 *  which includes starting and stopping the motor based on flow rate conditions,
 *  monitoring motor speed, and handling warnings for speed thresholds.
 *  It also manages LED indicators for status and warnings.
 *
 *
 *****************************************************************************/


/***** INCLUDES **************************************************************/
#include "Motor.h"

/***** PRIVATE DEFINES *****************************************************/
#define SPEED_THRESHOLD_700 700
#define SPEED_THRESHOLD_900 900
#define SPEED_THRESHOLD_800 800
#define SPEED_THRESHOLD_650 650

#define MOTOR_SPEED_RANGE_200 200
#define MOTOR_SPEED_RANGE_400 400
#define MOTOR_SPEED_RANGE_600 600

#define FLOW_RATE_RANGE_20 20
#define FLOW_RATE_RANGE_50 50
#define FLOW_RATE_RANGE_75 75
#define FLOW_RATE_RANGE_80 80

#define TIME_THRESHOLD_5SEC 100
#define TIME_THRESHOLD_3SEC 60

/***** PRIVATE CONSTANTS *****************************************************/


/***** PRIVATE MACROS ********************************************************/


/***** PRIVATE TYPES *********************************************************/


/***** PRIVATE PROTOTYPES ****************************************************/


/***** PRIVATE VARIABLES *****************************************************/
static bool motorStatus = false;
static bool statusLED1;
static bool toggleLED1;
static bool toggleLED3;
static ButtonInfo_t buttonInfoSW1;
static ButtonInfo_t buttonInfoSW2;
static uint32_t counter1;
static uint32_t counter2;
static uint32_t counter3;
static uint32_t counter4;
static uint32_t counter5;

/***** PUBLIC FUNCTIONS ******************************************************/
void initalizeMotor(){
	buttonInfoSW1.button = BTN_SW1;
	buttonInfoSW1.previousStatus = BUTTON_RELEASED;
	buttonInfoSW1.pendingStatus = BUTTON_RELEASED;
	buttonInfoSW1.debounceCounter = 0;
	buttonInfoSW1.action = startMotor;

	buttonInfoSW2.button = BTN_SW2;
	buttonInfoSW2.previousStatus = BUTTON_RELEASED;
	buttonInfoSW2.pendingStatus = BUTTON_RELEASED;
	buttonInfoSW2.debounceCounter = 0;
	buttonInfoSW2.action = stopMotor;
	toggleLED1 = false;
	toggleLED3 = false;
}
void startMotor(){
	if(flowRateSensorGetFlowRate()  > 0 && getFlowRate() > 0){
		motorStatus = true;
		toggleLED3 = true;
	}
}

bool motorCycle(){
	buttonInfoSW1.previousStatus = checkButtonStatus(&buttonInfoSW1,0);
	buttonInfoSW2.previousStatus = checkButtonStatus(&buttonInfoSW2,0);
	int sensorflowRate = flowRateSensorGetFlowRate();
	int flowRate = getFlowRate();
	int motorSpeed = speedSensorGetSpeed();
	if(motorSpeed  == 0)
	{
		motorStatus = false;
		//display "oo"on the 7-Seg
		displayDoubleDigitNumber(DISPLAY_NO_MOTOR_SPEED,SPEED);
	}
	else
	{
		displayDoubleDigitNumber(motorSpeed,SPEED);
  		if((-5 <= (sensorflowRate - flowRate)) && ((sensorflowRate - flowRate) <= 5) && motorStatus == true){
			ledSetLED(LED3,LED_ON);
			toggleLED3 = false;
		}else if (motorStatus){
			toggleLED3 = true;
		}
  		if(motorSpeed >= 1000){
  			return false;
  		}
  		if(motorSpeed > SPEED_THRESHOLD_900 ){
  					counter2++;
  					if(counter2>=TIME_THRESHOLD_3SEC){
#if DEBUG_MODE == 1
	outputLog("\n\rWarning: Very high motor speed.\n");
#endif
  						toggleLED1 = true;
  						counter2 = 0;
  					}
  					counter1 = 0;
  					counter3 = 0;
  					counter4 = 0;
  		}else if(motorSpeed > SPEED_THRESHOLD_700 ){
  					counter1++;
  					if(counter1>=TIME_THRESHOLD_5SEC){
  						ledSetLED(LED1,LED_ON);
  						counter1 = 0;
#if DEBUG_MODE == 1
	outputLog("\n\rWarning: High motor speed.\n");
#endif
  					}
  					counter2 = 0;
  					counter4 = 0;
  		}
  		if(motorSpeed < SPEED_THRESHOLD_650){
  					counter4++;
  					if(counter4>=TIME_THRESHOLD_3SEC){
  						ledSetLED(LED1,LED_OFF);
  						counter4 = 0;
  					}
  					counter1 = 0;
  					counter2 = 0;
  					counter3 = 0;
  		}else if(motorSpeed < SPEED_THRESHOLD_800){
  					counter3++;
  					if(counter3>=TIME_THRESHOLD_3SEC){
#if DEBUG_MODE == 1
	outputLog("\n\rWarning: High motor speed.\n");
#endif
  						toggleLED1 = false;
  						ledSetLED(LED1,LED_ON);
  						counter3 = 0;
  					}
  					counter2 = 0;
  					counter4 = 0;
  		}

		if (((0 < motorSpeed && motorSpeed <= MOTOR_SPEED_RANGE_200) && (0 < sensorflowRate && sensorflowRate <= FLOW_RATE_RANGE_20))
				|| ((MOTOR_SPEED_RANGE_200 < motorSpeed && motorSpeed <= MOTOR_SPEED_RANGE_400) && (FLOW_RATE_RANGE_20 < sensorflowRate && sensorflowRate <= FLOW_RATE_RANGE_50))
				|| ((MOTOR_SPEED_RANGE_400 < motorSpeed && motorSpeed <= MOTOR_SPEED_RANGE_600) && (FLOW_RATE_RANGE_50 < sensorflowRate &&  sensorflowRate <= FLOW_RATE_RANGE_75))
				|| (MOTOR_SPEED_RANGE_600 < motorSpeed && sensorflowRate <= FLOW_RATE_RANGE_80))
		{
			ledSetLED(LED1,LED_OFF);
			statusLED1 = false;
		}else if(!statusLED1){
#if DEBUG_MODE == 1
	outputLog("\n\rMotor speed and flow rate mismatch.\n");
#endif
			ledSetLED(LED1,LED_ON);
			statusLED1 = true;
		}
	}
	if(motorStatus == false){
		counter5++;
		if(counter5==TIME_THRESHOLD_5SEC){
			startMotor();
			counter5 = 0;
		}
	}else{
		counter5 = 0;
	}
	if(toggleLED1){
		ledToggleLED(LED1);
	}
	if(toggleLED3){
		ledToggleLED(LED3);
	}
	return true;
}

void stopMotor(){
	motorStatus = false;
	toggleLED3 = false;
	ledSetLED(LED3,LED_OFF);
}


/***** PRIVATE FUNCTIONS *****************************************************/





