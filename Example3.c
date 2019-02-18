/*
 * Example3.c
 *
 *  Created on: Feb 18, 2019
 *      Author: Ryan Guidrysb
 */
#include <stdio.h>

int Example3( ) {

   char str[100];       //char array STRING used as buffer

   printf( "Enter a value :");
   fflush(stdout);  //ECLIPSE BUG
   gets( str );

   printf( "\nYou entered: ");
   puts( str );

   return 0;

}

