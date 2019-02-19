/*
 * main.c
 *
 *  Created on: Feb 18, 2019
 *      Author: Ryan Guidry
 */
#include <stdio.h>

int GeometryCalculator();
int Population();
int TicTacToeGame();
int* ReverseArray(int array[], int arraySize);

int main(){

	GeometryCalculator();
	Population();
	TicTacToeGame();
	int numbers[] = {1,2,3,4,5};
	int size = 5;
	int *arrayPtr = ReverseArray(numbers, size);
	for(int x = 0; x < size; x++){
		printf("%d", *arrayPtr);
		arrayPtr++;
	}
	return 0;
}
