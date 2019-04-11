/**
* @file OceanLevels.c
* @author Ryan Guidry
* @date 11 Feb 2019
* @brief Source File for OceanLevels part of Homework #2
*/
#include <stdio.h>

/**
* @brief OceanLevels method that calculates ocean levels 
* over the course of a specific amount of years using a 
* constant rise per year and 
* prints the results to the console.
  @code{.c}
    double risePerYear = 1.5;														//Declare and Assign 1.5 to risePerYear
	double oceanLevel5 = risePerYear * 5;											//Declare and Assign level after 5 years
	double oceanLevel7 = risePerYear * 7;											//Declare and Assign level after 7 years
	double oceanLevel10 = risePerYear * 10;											//Declare and Assign level after 10 years
	printf("Ocean Level Increase After 5 Years: %.2f millimeters\n",oceanLevel5);	//Printing amount increased after 5 years
	printf("Ocean Level Increase After 7 Years: %.2f millimeters\n",oceanLevel7);	//Printing amount increased after 7 years
	printf("Ocean Level Increase After 10 Years: %.2f millimeters\n",oceanLevel10); //Printing amount increased after 10 years

	return 0;
  @endcode
* @return Returns an arbitrary @c int in which we use 0.
*/
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

