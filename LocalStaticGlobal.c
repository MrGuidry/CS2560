/*
 * LocalStaticGlobal.c
 *
 *  Created on: Feb 14, 2019
 *      Author: Ryan Guidry
 */

#include <stdio.h>

// Global variables
int A;
int B;

int fun(){
	static int count = 0; // Static Variable
	count++;
	return count;
}

int Add(){
	return A + B;
}

int LocalStaticGlobal(){
	int answer; // Local variable
	A = 5;
	B = 7;
	answer = Add();
	printf("%d\n",answer);
	printf("%d ",fun());
	printf("%d ",fun());
	return 0;
}
