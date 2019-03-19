#include "Date.h"
#include <iostream>

using namespace std;

//Constructors
Date::Date()
{
}

Date::Date(int m, int d, int y)
{
	month = m;
	day = d;
	year = y;
	if (month == 1) { monthName = "January"; }
	if (month == 2) { monthName = "February"; }
	if (month == 3) { monthName = "March"; }
	if (month == 4) { monthName = "April"; }
	if (month == 5) { monthName = "May"; }
	if (month == 6) { monthName = "June"; }
	if (month == 7) { monthName = "July"; }
	if (month == 8) { monthName = "August"; }
	if (month == 9) { monthName = "September"; }
	if (month == 10) { monthName = "October"; }
	if (month == 11) { monthName = "November"; }
	if (month == 12) { monthName = "December"; }
}

//Accessor Methods
int Date::getDay()
{
	return day;
}

int Date::getMonth()
{
	return month;
}

string Date::getMonthName()
{
	return monthName;
}

int Date::getYear()
{
	return year;
}

//Prints date in form 12/25/2014
void Date::printDate1()
{
	cout << month << "/" << day << "/" << year << endl;
}

//Prints date in form December 25, 2014
void Date::printDate2()
{
	cout << monthName << " " << day << ", " << year << endl;
}

//Prints date in form 25 December 2014
void Date::printDate3()
{
	cout << day << " " << monthName << " " << year << endl;
}

//Overloads for postfix and prefix incrementing
Date Date::operator++()
{
	int newDay = getDay();
	int newMonth = getMonth();
	int newYear = getYear();

	newDay += 1;

	if (newMonth == 2) {
		if (newDay > 28) {
			newDay = 1;
			newMonth = newMonth + 1;
		}
	}
	else {
		if (newMonth == 1 || newMonth == 3 || newMonth == 5 || newMonth == 7 || newMonth == 8 || newMonth == 10 || newMonth == 12) {
			if (newDay > 31) {
				newDay = 1;
				if (newMonth == 12) {
					newMonth = 1;
					newYear = newYear + 1;
				}
				else {
					newMonth = newMonth + 1;
				}
			}
		}
		else {
			if (newMonth == 4 || newMonth == 6 || newMonth == 9 || newMonth == 11) {
				if (newDay > 30) {
					newDay = 1;
					newMonth = newMonth + 1;
				}
			}
		}
	}

	return Date(newMonth,newDay,newYear);
}

Date Date::operator++(int i)
{
	int newDay = getDay();
	int newMonth = getMonth();
	int newYear = getYear();

	newDay = 1 + newDay;

	if (newMonth == 2) {
		if (newDay > 28) {
			newDay = 1;
			newMonth = newMonth + 1;
		}
	}
	else {
		if (newMonth == 1 || newMonth == 3 || newMonth == 5 || newMonth == 7 || newMonth == 8 || newMonth == 10 || newMonth == 12) {
			if (newDay > 31) {
				newDay = 1;
				if (newMonth == 12) {
					newMonth = 1;
					newYear = newYear + 1;
				}
				else {
					newMonth = newMonth + 1;
				}
			}
		}
		else {
			if (newMonth == 4 || newMonth == 6 || newMonth == 9 || newMonth == 11) {
				if (newDay > 30) {
					newDay = 1;
					newMonth = newMonth + 1;
				}
			}
		}
	}

	return Date(newMonth, newDay, newYear);
}

//Overloads for postfix and prefix decrementing
Date Date::operator--()
{
	int newMonth = getMonth();
	int newDay = getDay();
	int newYear = getYear();

	newDay -= 1;

	if (newDay == 0) {
		if (newMonth == 1 || newMonth == 2 || newMonth == 4 || newMonth == 6 || newMonth == 8 || newMonth == 9 || newMonth == 11) {
			newDay = 31;
			if (newMonth == 1) {
				newMonth = 12;
				newYear -= 1;
			}
			else {
				newMonth -= 1;
			}
		}
		else {
			if (newMonth == 5 || newMonth == 7 || newMonth == 10 || newMonth == 12) {
				newDay = 30;
				newMonth -= 1;
			}
			else {
				if (newMonth == 3) {
					newDay = 28;
					newMonth -= 1;
				}
			}
		}
	}

	return Date(newMonth, newDay, newYear);
}

Date Date::operator--(int)
{
	int newMonth = getMonth();
	int newDay = getDay();
	int newYear = getYear();

	newDay -= 1;

	if (newDay == 0) {
		if (newMonth == 1 || newMonth == 2 || newMonth == 4 || newMonth == 6 || newMonth == 8 || newMonth == 9 || newMonth == 11) {
			newDay = 31;
			if (newMonth == 1) {
				newMonth = 12;
				newYear -= 1;
			}
			else {
				newMonth -= 1;
			}
		}
		else {
			if (newMonth == 5 || newMonth == 7 || newMonth == 10 || newMonth == 12) {
				newDay = 30;
				newMonth -= 1;
			}
			else {
				if (newMonth == 3) {
					newDay = 28;
					newMonth -= 1;
				}
			}
		}
	}

	return Date(newMonth, newDay, newYear);
}

//Overloads for the subtraction operator
int Date::operator-(Date & d)
{
	int monthsDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31};

	int firstMonth = this->month;
	int firstDay = this->day;
	int firstYear = this->year;
	
	//Algorithm created by Abhay Rathi from GeeksforGeeks
	int totalDays1 = firstYear * 365 + firstDay;
	for (int x = 0; x < firstMonth - 1; x++) {
		totalDays1 += monthsDays[x];
	}

	int secondMonth = d.getMonth();
	int secondDay = d.getDay();
	int secondYear = d.getYear();

	int totalDays2 = secondYear * 365 + secondDay;
	for (int x = 1; x < secondMonth; x++) {
		totalDays2 += monthsDays[x];
	}

	return abs(totalDays1 - totalDays2);
}

//Overload for the cout's stream insertion operator
ostream & operator<<(ostream & o, Date & d)
{
	o << d.getMonthName() << " " << d.getDay() << ", " << d.getYear();
	return o;
}

//Overload for the cin's stream extraction operator
istream & operator>>(istream & i, Date & obj)
{
	bool valid = false;
	while (!valid) {
		cout << "Please enter a Date (month day year): ";
		i >> obj.month;
		i >> obj.day;
		i >> obj.year;

		if (obj.month >= 1 && obj.month <= 12) {
			if (obj.day >= 1 && obj.month <= 31) {
				if (obj.month == 1) { obj.monthName = "January"; }
				if (obj.month == 2) { obj.monthName = "February"; }
				if (obj.month == 3) { obj.monthName = "March"; }
				if (obj.month == 4) { obj.monthName = "April"; }
				if (obj.month == 5) { obj.monthName = "May"; }
				if (obj.month == 6) { obj.monthName = "June"; }
				if (obj.month == 7) { obj.monthName = "July"; }
				if (obj.month == 8) { obj.monthName = "August"; }
				if (obj.month == 9) { obj.monthName = "September"; }
				if (obj.month == 10) { obj.monthName = "October"; }
				if (obj.month == 11) { obj.monthName = "November"; }
				if (obj.month == 12) { obj.monthName = "December"; }

				valid = true;
			}
			else {
				cout << "Invalid Date...Try Again" << endl;
			}
		}
		else {
			cout << "Invalid Date...Try Again" << endl;
		}
	}
	
	return i;
}
