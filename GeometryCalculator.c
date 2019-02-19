/*
 * GeometryCalculator.c
 *
 *  Created on: Feb 18, 2019
 *      Author: Ryan Guidry
 */
#include <stdio.h>
#include <stdbool.h>

void areaCircle();
void areaRectangle();
void areaTriangle();

int GeometryCalculator(){

	int choice;
	bool done = false;
	while(!done){
		printf("1. Calculate the Area of a Circle\n");
		printf("2. Calculate the Area of a Rectangle\n");
		printf("3. Calculate the Area of a Triangle\n");
		printf("4. Quit\n");
		printf("Enter your choice (1-4)\n");
		fflush(stdout);
		scanf("%d", &choice);
			switch(choice){
			case 1:
				areaCircle();
				break;
			case 2:
				areaRectangle();
				break;
			case 3:
				areaTriangle();
				break;
			case 4:
				done = true;
				break;
			default:
				printf("Error! Incorrect choice.\n");
			}
	}

	return 0;
}

void areaCircle(){
 double pi = 3.14159;
 int radius;
 bool positive = false;
 while(!positive){
	printf("Enter the radius of the circle (no negatives): ");
	fflush(stdout);
	scanf("%d", &radius);
	if(radius >= 0){
		positive = true;
	}else{
		printf("Please enter a positive number!\n");
	}
 }
 double area = pi * (radius * radius);
 printf("Area: %.2f\n", area);
}

void areaRectangle(){
	int length, width;
	bool positive = false;
	 while(!positive){
		printf("Enter the length of the rectangle (no negatives): ");
		fflush(stdout);
		scanf("%d", &length);
		printf("Enter the width of the rectangle (no negatives): ");
		fflush(stdout);
		scanf("%d", &width);
		if(length >= 0 && width >= 0){
			positive = true;
		}else{
			printf("Please enter positive numbers!\n");
		}
	 }
	 int area = length * width;
	 printf("Area: %d\n", area);
}

void areaTriangle(){
	int base, height;
	bool positive = false;
		 while(!positive){
			printf("Enter the base length of the triangle (no negatives): ");
			fflush(stdout);
			scanf("%d", &base);
			printf("Enter the height of the triangle (no negatives): ");
			fflush(stdout);
			scanf("%d", &height);
			if(base >= 0 && height >= 0){
				positive = true;
			}else{
				printf("Please enter positive numbers!\n");
			}
		 }
	double area = base * height * .5;
	printf("Area: %.2f\n", area);
}

