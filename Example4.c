/*
 * Example4.c
 *
 *  Created on: Feb 18, 2019
 *      Author: Ryan Guidry
 */
#include <stdio.h>

int Example4() {

   char str[100];
   int i;

   printf( "Enter a value :");
   fflush(stdout);  //ECLIPSE BUG
   scanf("%s %d", str, &i);

   printf( "\nYou entered: %s %d ", str, i);

   return 0;

}

