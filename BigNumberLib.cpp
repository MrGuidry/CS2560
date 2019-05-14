/**
* @file BigNumber.cpp
* @author Ryan Guidry
* @date 13 May 2019
* @brief Source file for the BigNumber Class
*/
#include "stdafx.h"
#include "BigNumberLib.h"

/**
* @param num String that represents the Big Number to be created
* @brief Constructor for BigNumber that takes in a string
* and inserts its characters into the vector<char>
  @code{.cpp}
	 _number.insert(_number.begin(), num.begin(), num.end());
  @endcode
*/
BigNumber::BigNumber(std::string num)
{
	_number.insert(_number.begin(), num.begin(), num.end());
}

/**
* @param second A BigNumber to be added
* @brief Function that adds a second BigNumber to another BigNumber
  @code{.cpp}
	//Initial creation of two BigNumbers to be used in the function
	//Making sure the larger number is "on top"
	BigNumber a("");
	BigNumber b("");
	if (*this > second) {
		a = *this;
		b = second;
	}
	else {
		a = second;
		b = *this;
	}

	//Dealing with Negative number(s)
	if (a.isNegative() || b.isNegative()) {						//Checking if either numbers are negative
		if (a.isNegative() && b.isNegative()) {					//Checking if both are negative since we know one is
			//We know both are negative
			return a.flipSign().add(b.flipSign()).flipSign();
		}
		else if (a.isNegative() && b.isPositive()) {			//Checking if the first one is negative since we know only one is
			//We know the first number is negative
			return a.flipSign().subtract(b).flipSign();
		}
		else {
			//We know the second number is negative
			return b.flipSign().subtract(a).flipSign();
		}
	}

	//Creation of variables to be used in the function
	std::string answer;
	int carryOver = 0;
	int differenceInSize = (a._number.size() - b._number.size());

	//Append zeros onto the smaller number so they have the same number of digits
	for (int i = 0; i < differenceInSize; i++) {
		b._number.insert(b._number.begin(), '0');
	}

	//Main algorithm
	for (int i = (a._number.size() - 1); i >= 0; i--) {							//Starting from the end of the numbers and ending at the beginning
		int sum = (a._number[i] - '0') + (b._number[i] - '0') + carryOver;      //Calculating the sum of the current digit which needs to be converted from char to int, and adding any carryOver from the previous calculation
		carryOver = 0;															//Resetting the carry over
		if (sum <= 9 || i == 0) {												//If the addition was less than 10 and it isnt the front digits
			answer.insert(0, std::to_string(sum));								//Inserting sum into our answer string
		}
		else {
			//We know the number is either bigger that 10 or i isnt 0
			answer.insert(0, std::to_string(sum % 10));							//Inserting the excess sum over ten
			carryOver = 1;														//Updating carryOver to represent a sum greater than 9
		}
	}

	return BigNumber(answer);
  @endcode
* @return Returns a BigNumber with parameter equal to the sum
*/
BigNumber BigNumber::add(BigNumber second)
{
	//Initial creation of two BigNumbers to be used in the function 
	//Making sure the larger number is "on top"
	BigNumber a("");
	BigNumber b("");
	if (*this > second) {
		a = *this;
		b = second;
	}
	else {
		a = second;
		b = *this;
	}

	//Dealing with Negative number(s)
	if (a.isNegative() || b.isNegative()) {						//Checking if either numbers are negative
		if (a.isNegative() && b.isNegative()) {					//Checking if both are negative since we know one is
			//We know both are negative
			return a.flipSign().add(b.flipSign()).flipSign();
		}
		else if (a.isNegative() && b.isPositive()) {			//Checking if the first one is negative since we know only one is
			//We know the first number is negative
			return a.flipSign().subtract(b).flipSign();
		}
		else {
			//We know the second number is negative
			return b.flipSign().subtract(a).flipSign();
		}
	}

	//Creation of variables to be used in the function
	std::string answer;
	int carryOver = 0;
	int differenceInSize = (a._number.size() - b._number.size());

	//Append zeros onto the smaller number so they have the same number of digits
	for (int i = 0; i < differenceInSize; i++) {
		b._number.insert(b._number.begin(), '0');
	}

	//Main algorithm
	for (int i = (a._number.size() - 1); i >= 0; i--) {							//Starting from the end of the numbers and ending at the beginning
		int sum = (a._number[i] - '0') + (b._number[i] - '0') + carryOver;      //Calculating the sum of the current digit which needs to be converted from char to int, and adding any carryOver from the previous calculation
		carryOver = 0;															//Resetting the carry over
		if (sum <= 9 || i == 0) {												//If the addition was less than 10 and it isnt the front digits
			answer.insert(0, std::to_string(sum));								//Inserting sum into our answer string
		}
		else {
			//We know the number is either bigger that 10 or i isnt 0
			answer.insert(0, std::to_string(sum % 10));							//Inserting the excess sum over ten
			carryOver = 1;														//Updating carryOver to represent a sum greater than 9
		}
	}

	return BigNumber(answer);
}

/**
* @param second A BigNumber to be subtracted with another BigNumber
* @brief A function that subtracts a second BigNumber by another BigNumber
  @code{.cpp}
	//Creating two BigNumbers to be used in the function
	BigNumber a = *this;
	BigNumber b = second;

	//Handling negative numbers
	if (a.isNegative() || b.isNegative()) {
		if (a.isNegative() && b.isNegative()) {
			//Both numbers are negative
			return a.add(b.flipSign());
		}
		else if (a.isNegative() && b.isPositive()) {
			//The first number is negative
			return a.flipSign().add(b).flipSign();
		}
		else {
			//The second number is negative
			return b.flipSign().add(a); //Check
		}
	}

	//Both numbers are positive

	//Main Algorithm: Based off of Mark Guerra's code on GitHub
	std::string answer;
	int n = 0;
	int p = 0;
	bool borrowOne = false;
	bool shouldHaveTen = false;
	if (a < b) {
		//The answer will be negative
		BigNumber r = b.subtract(a).flipSign();
		for (int i = 1; i < r._number.size(); i++) {
			if (r._number[i] != '0') break;
			r._number.erase(r._number.begin() + 1);
		}
		return r;
	}

	//a is greater than or equal to b

	if (a._number.size() - b._number.size() > 1) { // Appending zeros to the beginning of the second number so the difference in digits is at most 1
		int iterator = a._number.size() - b._number.size() - 1;
		for (int i = 0; i < iterator; i++) {
			b._number.insert(b._number.begin(), '0');
		}
	}

	//Main Algorithm
	int i = a._number.size() - 1;										//Starting from the end of the numbers
	for (int x = b._number.size() - 1; x >= 0; x--) {
		if (((a._number[i] - '0') < (b._number[x] - '0')) && i > 0) {	//If the subtraction would lead to a negative number, we need to borrow
			//Needs to borrow from previous digit
			n = char((a._number[i] - '0') + 10);
			borrowOne = true;
			if (x > 0 || a._number[i - 1] != '0') {
				//Borrow available
				p = char((a._number[i - 1] - '0') - 1);
				if(p == -1){
					//Need to borrow further down
					p = 9;
					shouldHaveTen = true;
				}
				borrowOne = false;
			}
			if (shouldHaveTen) {
				//Going down to find where they borrow from
				int index = i - 1;
				for (int c = i - 1; (a._number[c] - '0') == 0; c--) {
					a._number[c] = char(p + '0');
					index--;
				}
				int t = (a._number[index] - '0') - 1; //Represents a place we can borrow and decrements it
				a._number[index] = char(t + '0'); //Setting appropriate char equivalent in the vector
			}
			a._number[i - 1] = char(p + '0');
			shouldHaveTen = false;
		}
		if ((a._number[i] - '0') == (b._number[x] - '0')) {		//If the subtraction equals zero, insert a zero into the answer
			answer.insert(0, "0");
		}
		else {
			if (n <= 0) {	// No problem with the subtraction
				answer.insert(0,1, char((a._number[i] - b._number[x] + '0')));
			}
			else {
				//A borrow happened and n was updated with the proper value to calculate the subtraction
				answer.insert(0, 1, char((n - (b._number[x] - '0')) + '0'));
			}
		}
		i--;   //Decrement pointer for first number position
		n = 0; //reset place holder;
	}

	//If there needed to be a borrowing
	if (borrowOne) {
		std::string num = "";
		for (int k = a._number.size() - b._number.size() - 1; k >= 0; k--) {
			if (a._number[k] == '0') {
				num += "0";
				continue;
			}
			else {
				num.insert(num.begin(), a._number[k]);
				int t = atoi(num.c_str());
				t--;

				for (int y = 0; y < num.length(); y++) {
					a._number[y] = num[y];
				}
				break;
			}
		}
	}

	//Editing the answer based on the position of the iteration
	while (i >= 0) {
		if (i == 0) {
			if ((a._number[i] - '0') != 0) {
				answer.insert(0,1,char(a._number[i]));
			}
		}
		else {
			answer.insert(0, 1, char(a._number[i] - '0'));
		}
		i--;
	}

	//In the event that the answer is all zeroes, this sets answer to one zero by iterating until it hits the null pointer
	if (answer.find_first_not_of('0') == std::string::npos) {
		answer = "0";
	}
	else {
		if (answer[0] == '0') {
			int index = answer.find_first_not_of('0');
			answer = answer.substr(index, answer.length() - 1);
		}
	}

	return BigNumber(answer);
  @endcode
  @return A BigNumber that holds the answer to the subtraction
*/
BigNumber BigNumber::subtract(BigNumber second)
{
	//Creating two BigNumbers to be used in the function
	BigNumber a = *this;
	BigNumber b = second;

	//Handling negative numbers
	if (a.isNegative() || b.isNegative()) {
		if (a.isNegative() && b.isNegative()) {
			//Both numbers are negative
			return a.add(b.flipSign());
		}
		else if (a.isNegative() && b.isPositive()) {
			//The first number is negative
			return a.flipSign().add(b).flipSign();
		}
		else {
			//The second number is negative
			return b.flipSign().add(a); //Check
		}
	}

	//Both numbers are positive

	//Main Algorithm: Based off of Mark Guerra's code on GitHub
	std::string answer;
	int n = 0;
	int p = 0;
	bool borrowOne = false;
	bool shouldHaveTen = false;
	if (a < b) {
		//The answer will be negative
		BigNumber r = b.subtract(a).flipSign();
		for (int i = 1; i < r._number.size(); i++) {
			if (r._number[i] != '0') break;
			r._number.erase(r._number.begin() + 1);
		}
		return r;
	}

	//a is greater than or equal to b

	if (a._number.size() - b._number.size() > 1) { // Appending zeros to the beginning of the second number so the difference in digits is at most 1
		int iterator = a._number.size() - b._number.size() - 1;
		for (int i = 0; i < iterator; i++) {
			b._number.insert(b._number.begin(), '0');
		}
	}

	//Main Algorithm
	int i = a._number.size() - 1;										//Starting from the end of the numbers
	for (int x = b._number.size() - 1; x >= 0; x--) {
		if (((a._number[i] - '0') < (b._number[x] - '0')) && i > 0) {	//If the subtraction would lead to a negative number, we need to borrow
			//Needs to borrow from previous digit
			n = char((a._number[i] - '0') + 10);
			borrowOne = true;
			if (x > 0 || a._number[i - 1] != '0') {
				//Borrow available
				p = char((a._number[i - 1] - '0') - 1);
				if (p == -1) {
					//Need to borrow further down
					p = 9;
					shouldHaveTen = true;
				}
				borrowOne = false;
			}
			if (shouldHaveTen) {
				//Going down to find where they borrow from 
				int index = i - 1;
				for (int c = i - 1; (a._number[c] - '0') == 0; c--) {
					a._number[c] = char(p + '0');
					index--;
				}
				int t = (a._number[index] - '0') - 1; //Represents a place we can borrow and decrements it
				a._number[index] = char(t + '0'); //Setting appropriate char equivalent in the vector
			}
			a._number[i - 1] = char(p + '0');
			shouldHaveTen = false;
		}
		if ((a._number[i] - '0') == (b._number[x] - '0')) {		//If the subtraction equals zero, insert a zero into the answer
			answer.insert(0, "0");
		}
		else {
			if (n <= 0) {	// No problem with the subtraction
				answer.insert(0, 1, char((a._number[i] - b._number[x] + '0')));
			}
			else {
				//A borrow happened and n was updated with the proper value to calculate the subtraction
				answer.insert(0, 1, char((n - (b._number[x] - '0')) + '0'));
			}
		}
		i--;   //Decrement pointer for first number position
		n = 0; //reset place holder;
	}

	//If there needed to be a borrowing 
	if (borrowOne) {
		std::string num = "";
		for (int k = a._number.size() - b._number.size() - 1; k >= 0; k--) {
			if (a._number[k] == '0') {
				num += "0";
				continue;
			}
			else {
				num.insert(num.begin(), a._number[k]);
				int t = atoi(num.c_str());
				t--;

				for (int y = 0; y < num.length(); y++) {
					a._number[y] = num[y];
				}
				break;
			}
		}
	}

	//Editing the answer based on the position of the iteration
	while (i >= 0) {
		if (i == 0) {
			if ((a._number[i] - '0') != 0) {
				answer.insert(0, 1, char(a._number[i]));
			}
		}
		else {
			answer.insert(0, 1, char(a._number[i] - '0'));
		}
		i--;
	}

	//In the event that the answer is all zeroes, this sets answer to one zero by iterating until it hits the null pointer
	if (answer.find_first_not_of('0') == std::string::npos) {
		answer = "0";
	}
	else {
		if (answer[0] == '0') {
			int index = answer.find_first_not_of('0');
			answer = answer.substr(index, answer.length() - 1);
		}
	}

	return BigNumber(answer);
}

/**
* @param second A BigNumber to be divided with another BigNumber
* @brief A function that divides a second BigNumber by another BigNumber
  @code{.cpp}
	//Checks to make sure the second number isnt zero which makes the result undetermined
	BigNumber zero("0");
	if (second == zero) {
		return BigNumber("Result is undetermined");
	}
	//Creating two BigNumbers to be used in the function
	BigNumber a = *this;
	BigNumber b = second;

	//Checking to see if any of the numbers are negative
	bool sign = false;
	if (a.isNegative() && b.isNegative()) {			//Looking to see if both numbers are negative
		//Both Numbers are Negative
		a.flipSign();
		b.flipSign();
	}
	else if (a.isNegative() && b.isPositive()) {
		//The first Number is Negative
		a.flipSign();
		sign = true;								//Updated sign to have a negative in the answer
	}
	else if (a.isPositive() && b.isNegative()) {
		//The second number is Negative
		b.flipSign();
		sign = true;								//Updated sign to have a negative in the answer
	}

	//Main Algorithm: While the first number is greater than or equal to the second number, subtract the second number by the first number and increment quotient by one
	int quotient = 0;
	while (a > b || a == b) {
		a = a.subtract(b);
		quotient++;
	}
	//Making sure we don't get a negative zero as the answer
	if (quotient == 0) {
		sign = false;
	}
	//Converting the int into a string and adding '-' if needed
	std::string answer = std::to_string(quotient);
	if (sign) {
		answer.insert(answer.begin(), '-');
	}
	return BigNumber(answer);
  @endcode
  @return A BigNumber that holds the answer to the division
*/
BigNumber BigNumber::divide(BigNumber second)
{
	//Checks to make sure the second number isnt zero which makes the result undetermined
	BigNumber zero("0");
	if (second == zero) {
		return BigNumber("Result is undetermined");
	}
	//Creating two BigNumbers to be used in the function
	BigNumber a = *this;
	BigNumber b = second;

	//Checking to see if any of the numbers are negative
	bool sign = false;
	if (a.isNegative() && b.isNegative()) {			//Looking to see if both numbers are negative
		//Both Numbers are Negative
		a.flipSign();
		b.flipSign();
	}
	else if (a.isNegative() && b.isPositive()) {
		//The first Number is Negative
		a.flipSign();
		sign = true;								//Updated sign to have a negative in the answer
	}
	else if (a.isPositive() && b.isNegative()) {
		//The second number is Negative
		b.flipSign();
		sign = true;								//Updated sign to have a negative in the answer
	}

	//Main Algorithm: While the first number is greater than or equal to the second number, subtract the second number by the first number and increment quotient by one
	int quotient = 0;
	while (a > b || a == b) {
		a = a.subtract(b);
		quotient++;
	}
	//Making sure we don't get a negative zero as the answer
	if (quotient == 0) {
		sign = false;
	}
	//Converting the int into a string and adding '-' if needed
	std::string answer = std::to_string(quotient);
	if (sign) {
		answer.insert(answer.begin(), '-');
	}
	return BigNumber(answer);
}

/**
* @param second A BigNumber to be multiplied with another BigNumber
* @brief A function that multiplies a second BigNumber by another BigNumber
  @code{.cpp}
	//Creating two BigNumbers that will be used in the function
	//Make sure the larger number is "on top"
	BigNumber a("");
	BigNumber b("");
	if (*this > second) {
		a = *this;
		b = second;
	}
	else {
		a = second;
		b = *this;
	}

	//Handling Negative numbers
	if (a.isNegative() || b.isNegative()) {								//If either are negative, enter inside the if statement
		if (a.isNegative() && b.isNegative()) {
			//Both numbers are negative
			return a.flipSign().multiply(b.flipSign());
		}
		else if (a.isNegative() && b.isPositive()) {
			//The first number is negative
			BigNumber result = a.flipSign().multiply(b).flipSign();
			//Avoiding a -0 answer
			if (result == BigNumber("-0")) {
				return BigNumber("0");
			}
			return result;
		}
		else {
			//The second number is negative
			BigNumber result = b.flipSign().multiply(a).flipSign();
			//Avoiding a -0 answer
			if (result == BigNumber("-0")) {
				return BigNumber("0");
			}
			return result;
		}
	}

	//Handling Multiplying by a zero
	BigNumber zero("0");
	if (a == zero || b == zero) {
		return zero;
	}

	//Main Algorithm: Based off of Mark Guerra's algorithm
	//Creation of variables to be used
	BigNumber answer("0");
	int carryOver = 0;																//Variable used to keep track of any carry over
	int zeroIncrement = 0;															//Variable used to keep track of zeros need to add
	//Fixing the size of the second number to match in digits
	for (int i = 0; i < a._number.size() - b._number.size(); i++) {
		b._number.insert(b._number.begin(), '0');
	}
	//Main Loop: Iterates from end to start of each
	for (int i = (b._number.size() - 1); i >= 0; i--) {
		std::string rr;
		for (int j = (a._number.size() - 1); j >= 0; j--) {
			int value = ((b._number[i] - '0') * (a._number[j] - '0')) + carryOver;  //Multiplication of the two digits plus any carry over
			carryOver = 0;														    //Reset carryOver
			if (value > 9 && j != 0) {												//If value is greater than 9 and its at the start of the numbers
				carryOver = value / 10;												//Updating carryOver to have the excess
				rr.insert(0, std::to_string(value % 10));							//Inserting the value into the current string
			}
			else {
				rr.insert(0, std::to_string(value));								//Inserting the value into the current string
			}
		}
		//If the digit isnt the furthest right, then appending zeros
		if (zeroIncrement > 0) {
			for (int y = 0; y < zeroIncrement; y++) {
				rr.append("0");
			}
		}
		zeroIncrement++;
		BigNumber result(rr);
		answer = answer.add(result);												//Adding the result of the digit's multiplication to the total
	}
	//Checking to see if the resulting calculations had any zeros in the front
	int index = 0;
	while (answer._number[index] == '0' && index < answer._number.size()) {
		index++;
	}
	if (index == answer._number.size()) {
		answer = zero;
	}
	else {
		answer._number.erase(answer._number.begin(), answer._number.begin() + index);
	}

	return answer;
  @endcode
  @return A BigNumber that holds the answer to the multiplication
*/
BigNumber BigNumber::multiply(BigNumber second)
{
	//Creating two BigNumbers that will be used in the function
	//Make sure the larger number is "on top"
	BigNumber a("");
	BigNumber b("");
	if (*this > second) {
		a = *this;
		b = second;
	}
	else {
		a = second;
		b = *this;
	}

	//Handling Negative numbers
	if (a.isNegative() || b.isNegative()) {								//If either are negative, enter inside the if statement
		if (a.isNegative() && b.isNegative()) {
			//Both numbers are negative
			return a.flipSign().multiply(b.flipSign());
		}
		else if (a.isNegative() && b.isPositive()) {
			//The first number is negative
			BigNumber result = a.flipSign().multiply(b).flipSign();
			//Avoiding a -0 answer
			if (result == BigNumber("-0")) {
				return BigNumber("0");
			}
			return result;
		}
		else {
			//The second number is negative
			BigNumber result = b.flipSign().multiply(a).flipSign();
			//Avoiding a -0 answer
			if (result == BigNumber("-0")) {
				return BigNumber("0");
			}
			return result;
		}
	}

	//Handling Multiplying by a zero
	BigNumber zero("0");
	if (a == zero || b == zero) {
		return zero;
	}

	//Main Algorithm: Based off of Mark Guerra's algorithm
	//Creation of variables to be used
	BigNumber answer("0");
	int carryOver = 0;																//Variable used to keep track of any carry over
	int zeroIncrement = 0;															//Variable used to keep track of zeros need to add
	//Fixing the size of the second number to match in digits
	for (int i = 0; i < a._number.size() - b._number.size(); i++) {
		b._number.insert(b._number.begin(), '0');
	}
	//Main Loop: Iterates from end to start of each
	for (int i = (b._number.size() - 1); i >= 0; i--) {
		std::string rr;
		for (int j = (a._number.size() - 1); j >= 0; j--) {
			int value = ((b._number[i] - '0') * (a._number[j] - '0')) + carryOver;  //Multiplication of the two digits plus any carry over
			carryOver = 0;														    //Reset carryOver
			if (value > 9 && j != 0) {												//If value is greater than 9 and its at the start of the numbers
				carryOver = value / 10;												//Updating carryOver to have the excess
				rr.insert(0, std::to_string(value % 10));							//Inserting the value into the current string 
			}
			else {
				rr.insert(0, std::to_string(value));								//Inserting the value into the current string
			}
		}
		//If the digit isnt the furthest right, then appending zeros 
		if (zeroIncrement > 0) {
			for (int y = 0; y < zeroIncrement; y++) {
				rr.append("0");
			}
		}
		zeroIncrement++;
		BigNumber result(rr);
		answer = answer.add(result);												//Adding the result of the digit's multiplication to the total 
	}
	//Checking to see if the resulting calculations had any zeros in the front
	int index = 0;
	while (answer._number[index] == '0' && index < answer._number.size()) {
		index++;
	}
	if (index == answer._number.size()) {
		answer = zero;
	}
	else {
		answer._number.erase(answer._number.begin(), answer._number.begin() + index);
	}

	return answer;
}

/**
* @param second A BigNumber to be modded with another BigNumber
* @brief A function that mods a second BigNumber with another BigNumber
  @code{.cpp}
	//Creating BigNumbers to be used in the function
	BigNumber a = *this;
	BigNumber b = second;

	//Checking to see that the second BigNumber isn't zero which makes the result undetermined
	BigNumber zero("0");
	if (b == zero) {
		return BigNumber("Result is Undetermined");
	}
	//Main algorithm : a mod b = a - (a/b) * b
	BigNumber quotient = a.divide(b);
	BigNumber multiplication = quotient.multiply(b);
	BigNumber remainder = a.subtract(multiplication);

	//Modifies answer to avoid returning a negative zero
	BigNumber negZero("-0");
	if (remainder == negZero) {
		return zero;
	}
	return remainder;
  @endcode
  @return A BigNumber that holds the answer to the mod
*/
BigNumber BigNumber::mod(BigNumber second)
{
	//Creating BigNumbers to be used in the function
	BigNumber a = *this;
	BigNumber b = second;

	//Checking to see that the second BigNumber isn't zero which makes the result undetermined
	BigNumber zero("0");
	if (b == zero) {
		return BigNumber("Result is Undetermined");
	}
	//Main algorithm : a mod b = a - (a/b) * b
	BigNumber quotient = a.divide(b);
	BigNumber multiplication = quotient.multiply(b);
	BigNumber remainder = a.subtract(multiplication);

	//Modifies answer to avoid returning a negative zero
	BigNumber negZero("-0");
	if (remainder == negZero) {
		return zero;
	}
	return remainder;
}

/**
* @brief A function that flips the sign of the BigNumber
  @code{.cpp}
	if (_number[0] == '-') {
		_number.erase(_number.begin());
	}
	else {
		_number.insert(_number.begin(), '-');
	}
	return *this;
  @endcode
  @return The inverse of the BigNumber
*/
BigNumber BigNumber::flipSign()
{
	if (_number[0] == '-') {
		_number.erase(_number.begin());
	}
	else {
		_number.insert(_number.begin(), '-');
	}
	return *this;
}

/**
* @param second BigNumber
* @brief A boolean function that checks if the BigNumber's _number that called the function equals second's _number
  @code{.cpp}
	return _number == second._number;
  @endcode
  @return True or False
*/
bool BigNumber::equals(BigNumber second)
{
	return _number == second._number;
}

/**
* @brief A boolean function that checks if the BigNumber is positive
  @code{.cpp}
	return !isNegative();
  @endcode
  @return True or False
*/
bool BigNumber::isPositive()
{
	return !isNegative();
}

/**
* @brief A boolean function that checks if the BigNumber is negative
  @code{.cpp}
	return (_number[0] == '-');
  @endcode
  @return True or False
*/
bool BigNumber::isNegative()
{
	return (_number[0] == '-');
}

/**
* @param a BigNumber
* @param b BigNumber
* @brief An Override for the + operator that adds two BigNumbers
  @code{.cpp}
	return a.add(b);
  @endcode
  @return A BigNumber that holds a + b
*/
BigNumber operator+(BigNumber a, BigNumber b)
{
	return a.add(b);
}

/**
* @param a BigNumber
* @param b BigNumber
* @brief An Override for the - operator that subtracts two BigNumbers
  @code{.cpp}
	return a.subtract(b);
  @endcode
  @return A BigNumber that holds a - b
*/
BigNumber operator-(BigNumber a, BigNumber b)
{
	return a.subtract(b);
}

/**
* @param a BigNumber
* @param b BigNumber
* @brief An Override for the / operator that divides two BigNumbers
  @code{.cpp}
	return a.divide(b);
  @endcode
  @return A BigNumber that holds a / b
*/
BigNumber operator/(BigNumber a, BigNumber b)
{
	return a.divide(b);
}

/**
* @param a BigNumber
* @param b BigNumber
* @brief An Override for the * operator that multiplies two BigNumbers
  @code{.cpp}
	return a.multiply(b);
  @endcode
  @return A BigNumber that holds a * b
*/
BigNumber operator*(BigNumber a, BigNumber b)
{
	return a.multiply(b);
}

/**
* @param a BigNumber
* @param b BigNumber
* @brief An Override for the % operator that mods two BigNumbers
  @code{.cpp}
	return a.mod(b);
  @endcode
  @return A BigNumber that holds a % b
*/
BigNumber operator%(BigNumber a, BigNumber b)
{
	return a.mod(b);
}

/**
* @param a BigNumber
* @param b BigNumber
* @brief A boolean operator overload that returns true if
* the a equals b
  @code{.cpp}
	return a.equals(b);
  @endcode
  @return True or False
*/
bool operator==(BigNumber a, BigNumber b)
{
	return a.equals(b);
}

/**
* @param a BigNumber
* @param b BigNumber
* @brief A boolean operator overload that returns true if
* a is greater than b
  @code{.cpp}
	//Checking to see if either numbers are negative
	if (a.isNegative() || b.isNegative()) {
		if (a.isNegative() && b.isNegative()) {
			//Both are negative
			a.flipSign();									//Flipping the sign of a
			b.flipSign();									//Flipping the sign of b
			return a < b;									//Since both were originally negative, the smaller value is technically larger
		}
		else {
			//One is negative, so positive number is larger
			return a.isPositive();		//if a is positive then returning true, false if negative
		}
	}
	//We know both numbers are positive

	//Equal?
	if (a == b) {
		return false;
	}
	//First is Bigger than Second based on number of digits?
	if (a._number.size() > b._number.size()) {
		return true;
	}
	//Second is Bigger than First based on number of digits?
	if (b._number.size() > a._number.size()) {
		return false;
	}
	//We know both numbers are the same size and they arent equal
	for (int i = 0; i < a._number.size(); i++) {		//Starting from the beginning of each number and comparing their values
		if (a._number[i] > b._number[i]) {
			return true;
		}
		else {
			if (a._number[i] < b._number[i]) {
				return false;
			}
		}
	}
  @endcode
  @return True or False
*/
bool operator>(BigNumber a, BigNumber b)
{
	//Checking to see if either numbers are negative
	if (a.isNegative() || b.isNegative()) {
		if (a.isNegative() && b.isNegative()) {
			//Both are negative
			a.flipSign();									//Flipping the sign of a
			b.flipSign();									//Flipping the sign of b
			return a < b;									//Since both were originally negative, the smaller value is technically larger 
		}
		else {
			//One is negative, so positive number is larger 
			return a.isPositive();		//if a is positive then returning true, false if negative
		}
	}
	//We know both numbers are positive

	//Equal?
	if (a == b) {
		return false;
	}
	//First is Bigger than Second based on number of digits?
	if (a._number.size() > b._number.size()) {
		return true;
	}
	//Second is Bigger than First based on number of digits?
	if (b._number.size() > a._number.size()) {
		return false;
	}
	//We know both numbers are the same size and they arent equal
	for (int i = 0; i < a._number.size(); i++) {		//Starting from the beginning of each number and comparing their values
		if (a._number[i] > b._number[i]) {
			return true;
		}
		else {
			if (a._number[i] < b._number[i]) {
				return false;
			}
		}
	}
}

/**
* @param a BigNumber
* @param b BigNumber
* @brief A boolean operator overload that returns true if
* a does not equal b and it's not greater than b
  @code{.cpp}
	return !(a == b) && !(a > b); //Not equal and not greater than
  @endcode
  @return True or False
*/
bool operator<(BigNumber a, BigNumber b)
{
	return !(a == b) && !(a > b); //Not equal and not greater than
}

/**
* @param a BigNumber
* @param b BigNumber
* @brief A boolean operator overload that returns true if
* a is greater than b or equal to b
  @code{.cpp}
	return a > b || a == b;
  @endcode
  @return True or False
*/
bool operator>=(BigNumber a, BigNumber b) {
	return a > b || a == b;
}

/**
* @param o output stream
* @param d BigNumber to be printed
* @brief An Override for the << operator in ostream
* to print the contents of the BigNumber
  @code{.cpp}
	std::string output(d._number.begin(), d._number.end());
	o << output;
	return o;
  @endcode
  @return The output stream
*/
std::ostream & operator<<(std::ostream & o, BigNumber & d)
{
	std::string output(d._number.begin(), d._number.end());
	o << output;
	return o;
}