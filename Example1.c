/*
 * Example1.c
 *
 *  Created on: Feb 18, 2019
 *      Author: Ryan Guidry
 */
#include <stdio.h>

void swap(int *x, int *y){
	int z = *x;
	*x = *y;
	*y = z;
}

int Example1(){

	int a = 45, b = 35;
	printf ("Before Swap\n");
	printf("a = %d b = %d\n",a,b);

	swap(&a, &b);

	printf ("After Swap with pass by reference\n");
	printf("a = %d b = %d\n",a,b);

	return 0;
}
