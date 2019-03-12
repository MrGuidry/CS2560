#ifndef POLICEOFFICER_H
#define POLICEOFFICER_H

#include <string>
#include "ParkingMeter.h"
#include "ParkedCar.h"
#include "ParkingTicket.h"

using namespace std;

class PoliceOfficer
{
private:
	string name;
	int badgeNumber;
public:
	PoliceOfficer(string,int);
	string getName();
	int getBadgeNumber();
	void issueTicket(ParkedCar &car,ParkingMeter &meter);
	bool checkExpiration(ParkedCar &car, ParkingMeter &meter);
};
#endif