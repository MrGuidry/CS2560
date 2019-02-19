/*
 * Population.c
 *
 *  Created on: Feb 18, 2019
 *      Author: Ryan Guidry
 */
#include <stdio.h>
#include <stdbool.h>

int Population(){
	int startingPopulation;
	double birthrate, deathrate;
	int yearsToDisplay;

	bool valid = false;
	while(!valid){
		printf("What is the starting population?");
		fflush(stdout);
		scanf("%d", &startingPopulation);
		if(startingPopulation >= 2){
			valid = true;
		}else{
			printf("Population must be 2 or more!\n");
		}

	}
	valid = false;
	while(!valid){
		printf("What is the birth rate?");
		fflush(stdout);
		scanf("%lf", &birthrate);
		birthrate = birthrate/100;
		if(birthrate >=0){
			valid = true;
		}else{
			printf("Birth rate must be positive!\n");
		}

	}
	valid = false;
	while(!valid){
		printf("What is the death rate?");
		fflush(stdout);
		scanf("%lf", &deathrate);
		deathrate = deathrate/100;
		if(deathrate >=0){
			valid = true;
		}else{
			printf("Death rate must be positive!\n");
		}
	}
	valid = false;
	while(!valid){
		printf("How many years would you like to display");
		fflush(stdout);
		scanf("%d", &yearsToDisplay);
		if(yearsToDisplay >=1){
			valid = true;
		}else{
			printf("Years must be 1 or more!");
		}
	}

	int newPopulation = 0;

	for(int x = 1; x <= yearsToDisplay; x++){
		printf("%d year(s) after start: ",x);
		newPopulation = startingPopulation + (birthrate * startingPopulation) - (deathrate * startingPopulation);
		printf("%d\n",newPopulation);
		startingPopulation = newPopulation;
	}



	return 0;
}

