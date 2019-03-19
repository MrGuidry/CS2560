#include "Date.h"
#include <iostream>
#include "main.h"

using namespace std;

int main() {
	int day;
	int month;
	int year;
	bool valid = false;

	//Input validation for the month and day
	while (!valid) {
		cout << "Enter the month (1-12):";
		cin >> month;
		cout << "Enter the day (1-31):";
		cin >> day;
		if (month >= 1 && month <= 12) {
			if (day >= 1) {
				if (month == 2 && day <= 28) {
					valid = true;
				}
				else {
					if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day <= 31) {
						valid = true;
					}
					else {
						if ((month == 4 || month == 6 || month == 9 || month == 11) && day <= 30) {
							valid = true;
						}
						else {
							cout << "Invalid day...Try again." << endl;
						}
					}
				}
			}
			 
		}
		else {
			cout << "Invalid month...Try again." << endl;
		}
	}
	cout << "Enter the year:" << endl;
	cin >> year;
	
	//Creating first Date
	Date date(month, day, year);
	
	//Printing different layouts of the Date
	date.printDate1();
	date.printDate2();
	date.printDate3();

	//Incrementing the Date by 1
	date = date++;
	cout << "Incremented Date: ";
	cout << date << endl;

	//Return Date back to original
	date = date--;

	//Decrementing the Date by 1
	date = date--;
	cout << "Decremented Date: ";
	cout << date << endl;

	//Creating new date using overload of >>
	Date date2;
	cin >> date2;
	cout << "Second Date: ";
	cout << date2 << endl;

	//Printing the overload of - so represent the days between two dates
	cout << "Days between the two dates: " << date - date2 << endl;

	return 0;
}