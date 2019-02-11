/*
 * OceanLevels.c
 *
 *  Created on: February 11, 2019
 *      Author: Ryan Guidry
 */
#include <stdio.h>

int OceanLevels(){

	double risePerYear = 1.5;														//Declare and Assign 1.5 to risePerYear
	double oceanLevel5 = risePerYear * 5;											//Declare and Assign level after 5 years
	double oceanLevel7 = risePerYear * 7;											//Declare and Assign level after 7 years
	double oceanLevel10 = risePerYear * 10;											//Declare and Assign level after 10 years
	printf("Ocean Level Increase After 5 Years: %.2f millimeters\n",oceanLevel5);	//Printing amount increased after 5 years
	printf("Ocean Level Increase After 7 Years: %.2f millimeters\n",oceanLevel7);	//Printing amount increased after 7 years
	printf("Ocean Level Increase After 10 Years: %.2f millimeters\n",oceanLevel10); //Printing amount increased after 10 years

	return 0;
}

