/*
 * Pointers.c
 *
 *  Created on: Feb 14, 2019
 *      Author: Ryan Guidry
 */

#include <stdio.h>

int Pointers(){
	int var = 20;
	int x = 10;
	int *ip;		/* pointer variable declaration */

	ip = NULL; // Point to address 0 for safety

	ip = &var; /* Change where you point to. Now pointing to address of var */

	x = x + *ip; // x = 10 + 20. grabbing data where pointer is pointing is called dereferencing the pointer

	ip = &x; //CHANGE WHERE ip points --> point to address of x

	//showing pointer calculation
	ip = ip + 3; // address of ip + (3 * sizeof(int)) = address of ip + 12

	printf("Address of var variable: %x\n", &var );

	/* address stored in pointer variable */
	printf("Address stored in ip variable: %x\n", ip);

	/* address the value using the pointer */
	printf("Value of *ip variable: %d\n", *ip);

	return 0;
}

