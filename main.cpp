#include <iostream>
#include "Die.h"
#include <string>
using namespace std;

int main() {
	//Creating the Dice 
	const int DIE_SIDES = 6;
	Die die1(DIE_SIDES);
	Die die2(DIE_SIDES);
	
	//Creating variables
	const int POINTS_LIMIT = 21;	//Max amounts of points a player can get before busting
	int computerTotal = 0;			//Running total of the computer's rolls
	int playerTotal = 0;			//Running total of the player's rolls
	int finished = 1;				//Variable used to see if the player has finished rolling
	
	cout << "Welcome to a Game of 21\n" << endl;

	//Round loop 
	while (finished == 1 && playerTotal <= POINTS_LIMIT) {	//While player still wants to roll and they havent exceeded the point limit 

		cout << "Your total is " << playerTotal << endl;	//Allowing the player to see what they have accumulated so far

		//Rolling for the computer
		die1.roll();
		die2.roll();
		computerTotal += (die1.getValue() + die2.getValue()); //Adding roll to running total

		//Checking to see if the player wants to continue rolling and making sure the user inputs a valid choice 
		bool valid = false;
		while (!valid) {
			cout << "Would you like to roll the dice to accumulate points?" << endl;
			cout << "1. Yes\n" << "2. No" << endl;
			cin >> finished;
			if (finished == 1 || finished == 2) {
				valid = true;
			} else {
				cout << "Please enter a valid option..." << endl;
			}
		}

		//If player wants to roll, rolls dice and adds to player's running total
		if (finished == 1) {
			die1.roll();
			die2.roll();
			playerTotal += (die1.getValue() + die2.getValue());
		}
		
	}//End WHILE

	//Prints each running total
	cout << "The Computer's total is " << computerTotal << endl;
	cout << "Your total is " << playerTotal << endl;

	//Checking to see who wins
	if (computerTotal <= POINTS_LIMIT && (computerTotal > playerTotal || playerTotal > POINTS_LIMIT)) {
		cout << "The Computer wins!!!" << endl;
	}else if (playerTotal <= POINTS_LIMIT && (playerTotal > computerTotal || computerTotal > POINTS_LIMIT)) {
		cout << "You Win!!!" << endl;
	}else if(computerTotal == playerTotal && computerTotal <= POINTS_LIMIT){
		cout << "You Tied!!!" << endl;
	}else {
		cout << "You both busted. Nobody wins..." << endl;
	}

}//END MAIN