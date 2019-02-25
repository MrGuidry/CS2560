/*
 * Theater.c
 *
 *  Created on: Feb 25, 2019
 *      Author: baseb
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define ROWS 15
#define COLUMNS 30

void displayContents(char theater[ROWS][COLUMNS]);
void makePrices(double array[], int size);
int getSeatsAuditorium(char theater[ROWS][COLUMNS]);
int getSeatsRow(char row[]);
int getSeatsSold(char theater[ROWS][COLUMNS]);
double buyTickets(char row[], double price);


void Theater(){
	char theater[15][30] =
		{
			"##############################",
			"##############################",
			"##############################",
			"##############################",
			"##############################",
			"##############################",
			"##############################",
			"##############################",
			"##############################",
			"##############################",
			"##############################",
			"##############################",
			"##############################",
			"##############################",
			"##############################"
		};

	//Making the Prices per Row
	double rowPrices[15];
	int size = sizeof(rowPrices)/sizeof(rowPrices[0]);
	makePrices(rowPrices, size);

	double ticketSales = 0.0;
	//Main Menu
	int choice;
	bool done = false;
		while(!done){

			printf("1. Buy Tickets.\n");
			printf("2. How many seats have been sold? \n");
			printf("3. How many seats are available in each row? \n");
			printf("4. How many seats are available in the auditorium? \n");
			printf("5. View Ticket Sales\n");
			printf("6. Quit\n");
			printf("Enter your choice (1-6)\n");
			fflush(stdout);
			scanf("%d", &choice);
				switch(choice){
				case 1://Buy tickets.
					displayContents(theater);
					int row = 0;
					int valid = false;
					while(!valid){
						printf("Which row would like to purchase tickets in? (1-15)");
						fflush(stdout);
						scanf("%d", &row);
						if(row >= 1 && row <= 15){
							if(getSeatsRow(theater[row-1]) != 0){
								ticketSales += buyTickets(theater[row-1], rowPrices[row-1]);
								valid = true;
							}else{
								printf("All seats in that row are sold out!!!\n");
							}

						}else{
							printf("Invalid Row Number!!!\n");
						}

					}
					displayContents(theater);
					break;
				case 2://How many seats have been sold?
					printf("Seats Sold: %d\n", getSeatsSold(theater));
					break;
				case 3://How many seats are available in each row?
					for(int r = 0; r < ROWS;r++){
						printf("Seats Available in Row %d: %d\n", (r+1), getSeatsRow(theater[r]));
					}
					break;
				case 4://How many seats available in the auditorium
					printf("Seats Available: %d\n", getSeatsAuditorium(theater));
					break;
				case 5://View Ticket Sales
					printf("Ticket Sales: $%.2f\n", ticketSales);
					break;
				case 6:
					done = true;
					break;
				default:
					printf("Error! Incorrect choice.\n");
				}
		}

}

double buyTickets(char row[], double price){
	int numberOfTickets;
	bool valid = false;
	double totalPrice = 0.0;
	while(!valid){
		printf("How many tickets would you like to buy?");
		fflush(stdout);
		scanf("%d", &numberOfTickets);
		if(numberOfTickets >= 0 && numberOfTickets <= getSeatsRow(row)){
			valid = true;
		}else{
			printf("Not enough seats in the row!!!\n");
		}
	}
	for(int x = numberOfTickets; x > 0; x--){
		int taken = false;
		while(!taken){
			printf("%d ticket(s) left to buy.\n", x);
			int choice = 0;
			printf("Which seat would you like to purchase? (1-30)\n");
			fflush(stdout);
			scanf("%d", &choice);
			if(choice >= 1){
				if(row[choice-1] == '*'){
					printf("This seat is already taken!!!\n");
				}else{
					row[choice-1] = '*';
					totalPrice += price;
					taken = true;
				}
			}else{
				printf("Invalid seat number!!!\n");
			}
		}
	}
	printf("Total Price: $%.2f\n", totalPrice);
	return totalPrice;
}

int getSeatsSold(char theater[ROWS][COLUMNS]){
	int sold = 0;
	for(int r = 0; r < ROWS; r++){
		for(int c = 0; c < COLUMNS; c++){
			if(theater[r][c] == '*')
				sold++;
		}
	}
	return sold;
}

int getSeatsRow(char row[]){
	int available = 0;
	for(int c = 0; c < COLUMNS; c++){
		if(row[c] == '#')
			available++;
	}

	return available;
}

int getSeatsAuditorium(char theater[ROWS][COLUMNS]){
	int available = 0;
	for(int r = 0; r < ROWS; r++){
		for(int c = 0; c < COLUMNS; c++){
			if(theater[r][c] == '#')
				available++;
		}
	}
	return available;
}

void makePrices(double array[], int size){
	int index = 0;
	for(int x = 1; x <= size; x++){
		bool valid = false;
		while(!valid){
			printf("Enter the price for Row %d:", x);
			fflush(stdout);
			scanf("%lf", (array+index));
			if(array[index] >= 0){
				valid = true;
			}else{
				printf("Please enter a positive Price!!!\n");
			}
		}
		index++;
	}
}

void displayContents(char theater[ROWS][COLUMNS]){
	printf("                      Seats\n");
	printf("          123456789012345678901234567890\n");
	for(int r = 0; r < ROWS; r++){
		if(r < 9){
			printf("Row %d     ", (r+1));
		}else{
			printf("Row %d    ", (r+1));
		}

		for(int c = 0; c < COLUMNS; c++){
			printf("%c", theater[r][c]);
		}
		printf("\n");
	}
}

