#include "PoliceOfficer.h"
#include <iostream>
using namespace std;

//COnstructor
PoliceOfficer::PoliceOfficer(string name, int number)
{
	this->name = name;
	badgeNumber = number;
}

//Accessor Functions
string PoliceOfficer::getName(){return name;}
int PoliceOfficer::getBadgeNumber(){return badgeNumber;}

//Member Functions

//IssueTicket creates a parking ticket and will display the car's information, the fine, and the officer's information
void PoliceOfficer::issueTicket(ParkedCar &car, ParkingMeter &meter)
{
	ParkingTicket ticket(getName(),getBadgeNumber());
	ticket.reportCar(car);
	cout << endl;
	ticket.reportFine(car, meter);
	cout << endl;
	ticket.reportOfficer();
	cout << endl;
}

//checkExperiation returns true if the total minutes parked exceeds the amount of minutes purchased
bool PoliceOfficer::checkExpiration(ParkedCar &car, ParkingMeter &meter)
{
	return (car.getMinutesParked() > meter.getMinutesPurchased());
}
