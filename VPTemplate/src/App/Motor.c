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

/***** PRIVATE CONSTANTS *****************************************************/


/***** PRIVATE MACROS ********************************************************/


/***** PRIVATE TYPES *********************************************************/


/***** PRIVATE PROTOTYPES ****************************************************/


/***** PRIVATE VARIABLES *****************************************************/
static bool status;
static ButtonInfo_t* buttonInfoSW1;
static ButtonInfo_t* buttonInfoSW2;

/***** PUBLIC FUNCTIONS ******************************************************/
void initalizeMotor(){
	buttonInfoSW1->button = BTN_SW1;
	buttonInfoSW1->previousStatus = BUTTON_RELEASED;
	buttonInfoSW1->action = startMotor;

	buttonInfoSW2->button = BTN_SW1;
	buttonInfoSW2->previousStatus = BUTTON_RELEASED;
	buttonInfoSW2->action = stopMotor;
}
void startMotor(){
	status = true;
	ledToggleLED(LED3);
}

void motorCycle(){
	checkButtonStatus(buttonInfoSW1);
	checkButtonStatus(buttonInfoSW2);
	if(status == true)
	{
		int flowRate = flowRateSensorGetFlowRate();
		int motorSpeed = speedSensorGetSpeed();
		if(flowRate  == 0)
		{
			//display "oo"on the 7-Seg
		}
		else
		{
			//else if the Flow Rate is reached
				//stop Flashing LED D3 just turn it on
			//else If the motor speed is > 700 rpm for at least 5 seconds
				//the Warning LED should be turned on
			//else If the motor speed is > 900 rpm for at least 3 seconds
				//the Warning LED should flash
			//else If the motor speed is < 800 rpm for at least 3 seconds
				//the Warning LED should be switched from flashing to on
			//else If the motor speed is < 650 rpm for at least 3 seconds
				//the Warning LED should be turned off

			if (motorSpeed <= 200) {
			    int flowRate = (motorSpeed * 20) / 200; // Skaliert auf 0-20 L/h
			    displayDoubleDigitNumber(flowRate);
			} else if (motorSpeed <= 400) {
			    int flowRate = 20 + ((motorSpeed - 200) * 30) / 200; // Skaliert auf 20-50 L/h
			    displayDoubleDigitNumber(flowRate);
			} else if (motorSpeed <= 600) {
			    int flowRate = 50 + ((motorSpeed - 400) * 25) / 200; // Skaliert auf 50-75 L/h
			    displayDoubleDigitNumber(flowRate);
			} else {
			    int flowRate = 75 + ((motorSpeed - 600) * 5) / (motorSpeed - 600); // Skaliert auf 75-80 L/h
			    displayDoubleDigitNumber(flowRate);
			}
			//if the condistions above are not reached
						//Turn on LED D1
					//else if LED D1 is on
						//Turn of LED D1
		}
	}
	//if(status == false && /* the flow rate ist valid, for 5sec */){
		//startMotor();
	//}
}

void stopMotor(){
	status = false;
	//turn LED D3 Off
}


/***** PRIVATE FUNCTIONS *****************************************************/





