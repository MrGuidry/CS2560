/*
 * Example2.c
 *
 *  Created on: Feb 18, 2019
 *      Author: Ryan Guidry
 */
#include <stdio.h>

typedef int number;

int Example2(){
	number c;
	printf("Enter a value: ");
	fflush(stdout); //ECLIPSE BUG
	c = getchar();

	printf("\nYou entered: ");
	putchar(c);

	return 0;
}

