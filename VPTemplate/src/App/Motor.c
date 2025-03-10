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


/***** PRIVATE CONSTANTS *****************************************************/


/***** PRIVATE MACROS ********************************************************/


/***** PRIVATE TYPES *********************************************************/


/***** PRIVATE PROTOTYPES ****************************************************/


/***** PRIVATE VARIABLES *****************************************************/


/***** PUBLIC FUNCTIONS ******************************************************/

void startMotor(){
	//flashing LED D3
}

void motorCycle(){
	//if SW1 was pressed
		//stop Motor
	//if SW2 was pressed
		//start Motor
	//if motor on
		//if no valid Flow Rate value has been set
			//display "oo" on the 7-Seg
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
		//display the current motor speed on the 7-Seg like:
			/*0 rpm < Motor speed <= 200 rpm ==> 0 L/h < Flow Rate <= 20 L/h
 	 	 	 200 rpm < Motor Speed <= 400 rpm ==> 20 L/h < Flow Rate <= 50 L/h
 	 	 	 400 rpm < Motor Speed <= 600 rpm ==> 50 L/h < Flow Rate <= 75 L/h
 	 	 	 600 rpm < Motor Speed ==> Flow Rate <= 80 L*/
		//if the condistions above are not reached
			//Turn on LED D1
		//else if LED D1 is on
			//Turn of LED D1

	//if the motor is not on and the flow rate ist valid, after 5sec
		//start the motor
}

void stopMotor(){
	//turn LED D3 Off
}


/***** PRIVATE FUNCTIONS *****************************************************/





