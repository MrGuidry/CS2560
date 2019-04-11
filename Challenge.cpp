#include "pch.h"
#include <iostream>
#include <string>

int main()
{
	bool done = false;
	double number;
	int numberOfScores = 0;
	double total = 0.0;
	while (!done) {
		std::string input = "";
		std::cout << "Enter a test score (Enter 0 to exit): ";
		std::cin >> input;
		number = stod(input);
		if (number == 0) { 
			done = true; 
		}else { 
			numberOfScores++; 
			total += number;
		}
	}
	std::cout << "Number of Scores: " << numberOfScores << std::endl;
	std::cout << "Average: " << (total / numberOfScores) << "%" << std::endl;
}
