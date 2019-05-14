#pragma once
/**
* @file BigNumber.h
* @author Ryan Guidry
* @date 13 May 2019
* @brief Header file for the BigNumber Class
*/
#include <iostream>
#include <vector>
#include <string>

/**
* @class BigNumber
* @brief Contains all the declarations that coincide
* with the operations of a typical number; Add, Subtract,
* Divide, Multiply, Mod.
 @code{.cpp}
  private:
	std::vector<char> _number;							//Private member variable of type vector<char> representing the big number
  public:
	BigNumber(std::string num);							//Constructor that takes in a String of which represents the big number

	BigNumber add(BigNumber second);					//Member Function that adds another BigNumber to the BigNumber that called the function
	BigNumber subtract(BigNumber second);				//Member Function that subtracts another BigNumber from the BigNumber that called the function
	BigNumber divide(BigNumber second);					//Member Function that divides another BigNumber by the BigNumber that called the function
	BigNumber multiply(BigNumber second);				//Member Function that multiplies another BigNumber by the BigNumber that called the function
	BigNumber mod(BigNumber second);					//Member Function that mods another BigNumber by the BigNumber that called the function
	BigNumber flipSign();								//Member function that flips the sign of the BigNumber from pos to neg or neg to pos
	bool equals(BigNumber second);						//Member Function that returns true if another BigNumber equals the BigNumber that called the function
	bool isPositive();									//Member Function that returns true if the BigNumber is Positive (Doesn't have a '-' at the beginning)
	bool isNegative();									//Member Function that returns true if the BigNumber is Negative (Has a '-' at the beginning)

	friend BigNumber operator+(BigNumber a,BigNumber b);	//Operator overload for addition of two BigNumbers
	friend BigNumber operator-(BigNumber a, BigNumber b);	//Operator overload for subtraction of two BigNumbers
	friend BigNumber operator/(BigNumber a, BigNumber b);	//Operator overload for division of two BigNumbers
	friend BigNumber operator*(BigNumber a, BigNumber b);	//Operator overload for multiplication of two BigNumbers
	friend BigNumber operator%(BigNumber a, BigNumber b);	//Operator overload for moding two BigNumbers

	friend bool operator==(BigNumber a, BigNumber b);		//Operator overload of == for two BigNumbers
	friend bool operator>(BigNumber a, BigNumber b);		//Operator overload of > for two BigNumbers
	friend bool operator<(BigNumber a, BigNumber b);		//Operator overload of < for two BigNumbers
	friend bool operator>=(BigNumber a, BigNumber b);		//Operator overload of >= for two BigNumbers

	friend std::ostream& operator << (std::ostream & o, BigNumber & d);		//Operator overload of << to print a BigNumber to the console
  @endcode
*/
class BigNumber
{
private:
	std::vector<char> _number;							//Private member variable of type vector<char> representing the big number
public:
	BigNumber(std::string num);							//Constructor that takes in a String of which represents the big number

	BigNumber add(BigNumber second);					//Member Function that adds another BigNumber to the BigNumber that called the function
	BigNumber subtract(BigNumber second);				//Member Function that subtracts another BigNumber from the BigNumber that called the function
	BigNumber divide(BigNumber second);					//Member Function that divides another BigNumber by the BigNumber that called the function
	BigNumber multiply(BigNumber second);				//Member Function that multiplies another BigNumber by the BigNumber that called the function
	BigNumber mod(BigNumber second);					//Member Function that mods another BigNumber by the BigNumber that called the function
	BigNumber flipSign();								//Member function that flips the sign of the BigNumber from pos to neg or neg to pos
	bool equals(BigNumber second);						//Member Function that returns true if another BigNumber equals the BigNumber that called the function
	bool isPositive();									//Member Function that returns true if the BigNumber is Positive (Doesn't have a '-' at the beginning)
	bool isNegative();									//Member Function that returns true if the BigNumber is Negative (Has a '-' at the beginning)

	friend BigNumber operator+(BigNumber a, BigNumber b);	//Operator overload for addition of two BigNumbers
	friend BigNumber operator-(BigNumber a, BigNumber b);	//Operator overload for subtraction of two BigNumbers
	friend BigNumber operator/(BigNumber a, BigNumber b);	//Operator overload for division of two BigNumbers
	friend BigNumber operator*(BigNumber a, BigNumber b);	//Operator overload for multiplication of two BigNumbers
	friend BigNumber operator%(BigNumber a, BigNumber b);	//Operator overload for moding two BigNumbers

	friend bool operator==(BigNumber a, BigNumber b);		//Operator overload of == for two BigNumbers
	friend bool operator>(BigNumber a, BigNumber b);		//Operator overload of > for two BigNumbers
	friend bool operator<(BigNumber a, BigNumber b);		//Operator overload of < for two BigNumbers
	friend bool operator>=(BigNumber a, BigNumber b);		//Operator overload of >= for two BigNumbers

	friend std::ostream& operator << (std::ostream & o, BigNumber & d);		//Operator overload of << to print a BigNumber to the console
};

