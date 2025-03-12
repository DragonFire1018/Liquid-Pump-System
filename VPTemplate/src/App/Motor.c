/******************************************************************************
 * @file <Filename>.h
 *
 * @author <Author>
 * @date   <Date>
 *
 * @copyright Copyright (c) 2025
 *
 ******************************************************************************
 *
 * @brief <Some short descrition>
 *
 * @details <A more detailed description>
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
static bool status;
static bool statusLED1;
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
	buttonInfoSW1.action = startMotor;

	buttonInfoSW2.button = BTN_SW2;
	buttonInfoSW2.previousStatus = BUTTON_RELEASED;
	buttonInfoSW2.action = stopMotor;
}
void startMotor(){
	if(flowRateSensorGetFlowRate()  > 0 && getFlowRate() > 0){
		status = true;
		ledToggleLED(LED3);
	}
}

void motorCycle(){
	checkButtonStatus(&buttonInfoSW1,0);
	checkButtonStatus(&buttonInfoSW2,0);
	int flowRate = flowRateSensorGetFlowRate();
	int motorSpeed = speedSensorGetSpeed();
	if(motorSpeed  == 0)
	{
		status = false;
		//display "oo"on the 7-Seg
		displayDoubleDigitNumber(DISPLAY_NO_MOTOR_SPEED);
	}
	else
	{
		displayDoubleDigitNumber(motorSpeed);
		if(getFlowRate() == flowRateSensorGetFlowRate()){
			ledSetLED(LED3,LED_ON);
		}

		if(motorSpeed > SPEED_THRESHOLD_700 ){
			counter1++;
			if(counter1==TIME_THRESHOLD_5SEC){
				ledSetLED(LED1,LED_ON);
				counter1 = 0;
			}
		}else if(motorSpeed > SPEED_THRESHOLD_900 ){
			counter2++;
			if(counter2==TIME_THRESHOLD_3SEC){
				ledToggleLED(LED1);
				counter2 = 0;
			}
		}else if(motorSpeed < SPEED_THRESHOLD_800){
			counter3++;
			if(counter3==TIME_THRESHOLD_3SEC){
				ledSetLED(LED1,LED_ON);
				counter3 = 0;
			}
		}else if(motorSpeed < SPEED_THRESHOLD_650){
			counter4++;
			if(counter4==TIME_THRESHOLD_3SEC){
				ledSetLED(LED1,LED_OFF);
				counter4 = 0;
			}
		}else{
			counter1 = 0;
			counter2 = 0;
			counter3 = 0;
			counter4 = 0;
			ledSetLED(LED1,LED_OFF);
		}

		if (((0 < motorSpeed && motorSpeed <= MOTOR_SPEED_RANGE_200) && (0 < flowRate && flowRate < FLOW_RATE_RANGE_20))
				|| ((MOTOR_SPEED_RANGE_200 < motorSpeed && motorSpeed <= MOTOR_SPEED_RANGE_400) && (FLOW_RATE_RANGE_20 < flowRate && flowRate <= FLOW_RATE_RANGE_50))
				|| ((MOTOR_SPEED_RANGE_400 < motorSpeed && motorSpeed <= MOTOR_SPEED_RANGE_600) && (FLOW_RATE_RANGE_50 < flowRate &&  flowRate <= FLOW_RATE_RANGE_75))
				|| (MOTOR_SPEED_RANGE_600 < motorSpeed && flowRate <= FLOW_RATE_RANGE_80))
		{
			ledSetLED(LED1,LED_ON);
			statusLED1 = true;
		}else if(statusLED1){
			ledSetLED(LED1,LED_OFF);
			statusLED1 = false;
		}
	}
	if(status == false){
		counter5++;
		if(counter5==TIME_THRESHOLD_5SEC){
			startMotor();
			counter5 = 0;
		}
	}else{
		counter5 = 0;
	}
}

void stopMotor(){
	status = false;
	ledSetLED(LED3,LED_OFF);
}


/***** PRIVATE FUNCTIONS *****************************************************/





