#pragma once
#include <iostream>
#include <string>
using namespace std;

class Date
{
private:
	int month;
	string monthName;
	int day;
	int year;
public:
	Date();
	Date(int,int,int);
	
	int getDay();
	int getMonth();
	string getMonthName();
	int getYear();

	void printDate1();
	void printDate2();
	void printDate3();

	Date operator++();
	Date operator++(int);

	Date operator--();
	Date operator--(int);

	int operator -(Date & d);
	
	friend ostream& operator << (ostream & o, Date & d);
	friend istream& operator >> (istream & i, Date & obj);
};

