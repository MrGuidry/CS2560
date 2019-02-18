/*
 * Example5.c
 *
 *  Created on: Feb 18, 2019
 *      Author: Ryan Guidry
 */
#include <stdio.h>

int Example5() {
   FILE *fp;        //pointer to a file type

   fp = fopen("textFile.txt", "w+");
   fprintf(fp, "This is testing for fprintf...\n");
   fputs("This is testing for fputs...\n", fp);
   fclose(fp);

   return 0;
}

