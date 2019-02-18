/*
 * AccessUnions.c
 *
 *  Created on: Feb 18, 2019
 *      Author: baseb
 */
#include <stdio.h>
#include <string.h>

union Data {
   int i;
   float f;
   char str[20];
};

int AccessUnion( ) {
   union Data data;
   data.i = 10;
   data.f = 220.5;  //writes over i
   strcpy( data.str, "C Programming");  //writes over f
   printf( "data.i : %d\n", data.i);    //print out garbage will read 4 bytes interpret as whole number
   printf( "data.f : %f\n", data.f);    //print out garbage will read 4 bytes intrepret as
   printf( "data.str : %s\n", data.str); //print out "C Programming"

   return 0;
}

int AccessUnion2( ) {
   union Data data;
   data.i = 10;
   printf( "data.i : %d\n", data.i);
   data.f = 220.5;
   printf( "data.f : %f\n", data.f);
   strcpy( data.str, "C Programming");
   printf( "data.str : %s\n", data.str);

   return 0;
}

