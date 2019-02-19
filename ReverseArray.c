/*
 * ReverseArray.c
 *
 *  Created on: Feb 18, 2019
 *      Author: Ryan Guidry
 */
#include <stdio.h>


int copy[];
int* ReverseArray(int array[], int arraySize){
	//int copy[arraySize];
	int index = 0;
	for(int x = arraySize - 1; x >= 0;x--){
		copy[index] = array[x];
		index++;
	}
	printf("Reverse Array: ");
	int *pointer = copy;
	return pointer;
}

