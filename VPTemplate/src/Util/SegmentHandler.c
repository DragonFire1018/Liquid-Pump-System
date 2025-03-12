/*
 * SegementHandler.c
 *
 *  Created on: 12.03.2025
 *      Author: drago
 */

#include "SegmentHandler.h"

void displayNumber(uint16_t number, Display_t segementSide)
{
    /* Reset all segments on the left */
    if (segementSide == RIGHT_DISPLAY)
    {
    	displayShowDigit(LEFT_DISPLAY,19);
    }

    /* Reset all segments on the right */
    else
    {
    	displayShowDigit(RIGHT_DISPLAY,19);
    }

    /* Configure segments for each number (0-9) */
    switch (number)
    {
        case 0:
        	displayShowDigit(segementSide,0);
        	displayShowDigit(segementSide,1);
        	displayShowDigit(segementSide,2);
        	displayShowDigit(segementSide,3);
        	displayShowDigit(segementSide,4);
        	displayShowDigit(segementSide,5);
            break;

        case 1:
        	displayShowDigit(segementSide,1);
        	displayShowDigit(segementSide,2);
            break;

        case 2:
        	displayShowDigit(segementSide,0);
        	displayShowDigit(segementSide,1);
        	displayShowDigit(segementSide,3);
        	displayShowDigit(segementSide,4);
        	displayShowDigit(segementSide,6);
            break;

        case 3:
        	displayShowDigit(segementSide,0);
        	displayShowDigit(segementSide,1);
        	displayShowDigit(segementSide,2);
        	displayShowDigit(segementSide,3);
        	displayShowDigit(segementSide,6);
            break;

        case 4:
        	displayShowDigit(segementSide,1);
            displayShowDigit(segementSide,3);
            displayShowDigit(segementSide,5);
            displayShowDigit(segementSide,6);
            break;

        case 5:
        	displayShowDigit(segementSide,0);
        	displayShowDigit(segementSide,2);
        	displayShowDigit(segementSide,3);
        	displayShowDigit(segementSide,5);
        	displayShowDigit(segementSide,6);
            break;

        case 6:
        	displayShowDigit(segementSide,0);
        	displayShowDigit(segementSide,2);
        	displayShowDigit(segementSide,3);
        	displayShowDigit(segementSide,4);
        	displayShowDigit(segementSide,5);
        	displayShowDigit(segementSide,6);
            break;

        case 7:
        	displayShowDigit(segementSide,0);
        	displayShowDigit(segementSide,1);
        	displayShowDigit(segementSide,2);
            displayShowDigit(segementSide,5);
            break;

        case 8:
        	displayShowDigit(segementSide,0);
        	displayShowDigit(segementSide,1);
        	displayShowDigit(segementSide,2);
        	displayShowDigit(segementSide,3);
        	displayShowDigit(segementSide,4);
        	displayShowDigit(segementSide,5);
        	displayShowDigit(segementSide,6);
            break;

        case 9:
        	displayShowDigit(segementSide,0);
        	displayShowDigit(segementSide,1);
        	displayShowDigit(segementSide,2);
        	displayShowDigit(segementSide,3);
        	displayShowDigit(segementSide,5);
        	displayShowDigit(segementSide,6);
            break;
    }
}


