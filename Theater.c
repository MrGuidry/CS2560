/*
 * Theater.c
 *
 *  Created on: February 25, 2019
 *      Author: Ryan Guidry
 */

 /**
  * @file Theater.c
  * @author Ryan Guidry
  * @date 25 Feb 2019
  * @brief Source File for Theater method for Project #1
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

/**
 * @brief Theatre method that creates a 2-d array representing
 * a theater and allows the user to purchase seats based on the row
 * and the number of seats that they want in the row. THe program also
 * allows the user to see how many seats have been sold, how many 
 * seats are available in each row, how many seats are available in
 * the auditorium, and the total ticket sales.
   @code{.c}
	char theater[15][30] =					//Creation of the theater with '#' in every seat
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

	double ticketSales = 0.0; 				//Declaration and Assignment of the variable used o track the total sales

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
		scanf_s("%d", &choice);
			switch(choice){
			case 1://Buy tickets
				displayContents(theater);
				int row = 0;
				int valid = false;
				while(!valid){
					printf("Which row would like to purchase tickets in? (1-15)");
					fflush(stdout);
					scanf_s("%d", &row);
					if(row >= 1 && row <= 15){ //Checking to make sure the row choice is from 1 to 15
						if(getSeatsRow(theater[row-1]) != 0){ //Checking to make sure there are available seats in the row chosen
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
			case 6://QUIT
				done = true;
				break;
			default:
				printf("Error! Incorrect choice.\n");
			}
	}
   @endcode
 * @return Returns an arbitrary @c int in which we use 0.
 */
void Theater(){
	char theater[15][30] =					//Creation of the theater with '#' in every seat
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

	double ticketSales = 0.0; 				//Declaration and Assignment of the variable used o track the total sales

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
		scanf_s("%d", &choice);
			switch(choice){
			case 1://Buy tickets
				displayContents(theater);
				int row = 0;
				int valid = false;
				while(!valid){
					printf("Which row would like to purchase tickets in? (1-15)");
					fflush(stdout);
					scanf_s("%d", &row);
					if(row >= 1 && row <= 15){ //Checking to make sure the row choice is from 1 to 15
						if(getSeatsRow(theater[row-1]) != 0){ //Checking to make sure there are available seats in the row chosen
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
			case 6://QUIT
				done = true;
				break;
			default:
				printf("Error! Incorrect choice.\n");
			}
	}
}

/**
 * @brief BuyTickets method that is used to allow the user to choose how many tickets they want to buy
 * as well as what seat they want to buy. This method updated the contents on valid choices
 * and tallies up the total cost. Returns: total cost of tickets.
   @code{.c}
	int numberOfTickets;
	bool valid = false;
	double totalPrice = 0.0;
	while(!valid){
		printf("How many tickets would you like to buy?");
		fflush(stdout);
		scanf_s("%d", &numberOfTickets);
		if(numberOfTickets >= 0 && numberOfTickets <= getSeatsRow(row)){ //Checks to make sure the amount of tickets to buy is not negative as well as less than the amount of seats left in that row
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
			scanf_s("%d", &choice);
			if(choice >= 1){
				if(row[choice-1] == '*'){//If the seat they chose is taken, then it will tell them. If not taken, then seat is updated and total price is updated.
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
	printf("Total Price: $%.2f\n", totalPrice); //Displays total Cost of the culmination of tickets
	return totalPrice; //Returning the total price of all the tickets to be used outside this method
	@endcode
 *  @return Returns a @c double that is the total price of the tickets that were purchased.
 */
double buyTickets(char row[], double price){
	int numberOfTickets;
	bool valid = false;
	double totalPrice = 0.0;
	while(!valid){
		printf("How many tickets would you like to buy?");
		fflush(stdout);
		scanf_s("%d", &numberOfTickets);
		if(numberOfTickets >= 0 && numberOfTickets <= getSeatsRow(row)){ //Checks to make sure the amount of tickets to buy is not negative as well as less than the amount of seats left in that row
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
			scanf_s("%d", &choice);
			if(choice >= 1){
				if(row[choice-1] == '*'){//If the seat they chose is taken, then it will tell them. If not taken, then seat is updated and total price is updated.
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
	printf("Total Price: $%.2f\n", totalPrice); //Displays total Cost of the culmination of tickets
	return totalPrice; //Returning the total price of all the tickets to be used outside this method
}

/**
 * @brief GetSeatsSold method goes through the theater and increments a variable whenever
 * a seat is comes across has been sold.
   @code{.c}
	int sold = 0;
	for(int r = 0; r < ROWS; r++){
		for(int c = 0; c < COLUMNS; c++){
			if(theater[r][c] == '*')
				sold++;
		}
	}
	return sold;
   @endcode
 * @return Returns an @c int that represents the number of seats sold
 */
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

/* GetSeatsRow
 * This method goes through a certain row specified in the parameter
 * and increments a variable whenever it comes across a seat that is available.
 * Returns: Total number of available seats in that row.
 */
/**
 * @brief The GetSeatsRow method goes through a certain row specified in the parameter
 * and increments a variable whenever it comes across a seat that is available.
	@code{.c}
	int available = 0;
	for(int c = 0; c < COLUMNS; c++){
		if(row[c] == '#')
			available++;
	}

	return available;
	@endcode
 * @return Returns an @c int that represents the total number of available seats in that row
 */
int getSeatsRow(char row[]){
	int available = 0;
	for(int c = 0; c < COLUMNS; c++){
		if(row[c] == '#')
			available++;
	}

	return available;
}

/* GetSeatsAuditorium
 * This method goes through the entire theater and increments a
 * variable whenever it comes across a seat that is available.
 * Returns: Total number of available seats in the theater.
 */
/**
 * @brief The GetSeatsAuditorium method goes through the entire theater and increments a
 * variable whenever it comes across a seat that is available.
   @code{.c}
   int available = 0;
	for(int r = 0; r < ROWS; r++){
		for(int c = 0; c < COLUMNS; c++){
			if(theater[r][c] == '#')
				available++;
		}
	}
	return available;
   @endcode
 * @return Returns an @c int that represents the total number of available seats in the theater.
 */
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

/* MakePrices
 * This method takes in an array that will be used in the method and the size of the array.
 * In this method, the user specifies what prices they want each row to be for every seat in that row.
 */
/**
 * @brief The MakePrices method takes in an array that will be used in the method and the size of the array.
 * In this method, the user specifies what prices they want each row to be for every seat in that row.
   @code{.c}
   int index = 0;
	for(int x = 1; x <= size; x++){
		bool valid = false;
		while(!valid){
			printf("Enter the price for Row %d:", x);
			fflush(stdout);
			scanf_s("%lf", (array+index));
			if(array[index] >= 0){//Check to make sure the value specified is greater than or equal to 0
				valid = true;
			}else{
				printf("Please enter a positive Price!!!\n");
			}
		}
		index++;
	}
   @endcode
 * @return Nothing to Return
 */
void makePrices(double array[], int size){
	int index = 0;
	for(int x = 1; x <= size; x++){
		bool valid = false;
		while(!valid){
			printf("Enter the price for Row %d:", x);
			fflush(stdout);
			scanf_s("%lf", (array+index));
			if(array[index] >= 0){//Check to make sure the value specified is greater than or equal to 0
				valid = true;
			}else{
				printf("Please enter a positive Price!!!\n");
			}
		}
		index++;
	}
}

/* Display Contents
 *
 * This method displays the entire theater in such a way secified by the program prompt
 *
 */
/**
 * @brief The displayContents method displays the entire theater in such a way specified by the program prompt
   @code{.c}
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
   @endcode
 * @return Nothing to Return
 */
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

