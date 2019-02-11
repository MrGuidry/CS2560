/*
 * PatternDisplays.c
 *
 *  Created on: February 11, 2019
 *      Author: Ryan Guidry
 */
#include <stdio.h>

int PatternDisplays(){

	//Iterators for first pattern
	int count = 1;					//Declaring and Assigning a value for count
	int number = 0;					//Declaring and Assigning a value for number

	//Pattern 1
	for(int x = 0; x < 10; x++){
		while(number < count){		//While number is less than count it will print "+"
			printf("+");
			number++;				//Increases number closer to count
		}
		printf("\n");
		count++;					//Increases count to increase the capacity of each row
		number = 0;					//Resetting number to the start
	}

	//Iterators for second pattern
	number = 10;
	count = 0;

	//Pattern 2
	for(int x = 0; x < 10; x++){
		while(number > count){		//While number is greater than count it will print "+"
			printf("+");
			number--;				//Decrementing number closer to count
		}
		printf("\n");
		number = 10;				//Resetting number to the start
		count++;					//Increasing count to lower the capacity of each row
	}

	return 0;
}
