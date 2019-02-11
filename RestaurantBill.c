/*
 * RestaurantBill.c
 *
 *  Created on: February 11, 2019
 *      Author: Ryan Guidry
 */
#include <stdio.h>

int RestaurantBill(){
	double mealCost = 88.67; 				//Declare and Assign mealCost to be $88.67
	double tax = mealCost * (0.0675); 		//Declare and Assign tax to be 6.75% of the meal cost
	double tip = (mealCost + tax) * (.2); 	//Declare and Assign tip to be 20% of the sum of the meal cost and tax
	double total = mealCost + tax + tip;	//Declare and Assign total to be the sum of the meal cost, tax, and tip
	printf("Meal Cost: $%.2f\n",mealCost);	//Printing the Meal Cost
	printf("Tax Amount: $%.2f\n",tax);		//Printing the Tax Amount
	printf("Tip Amount: $%.2f\n",tip);		//Printing the Tip Amount
	printf("Total Bill: $%.2f\n",total);	//Printing the Total Bill

	return 0;
}
