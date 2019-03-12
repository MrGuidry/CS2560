#ifndef PARKINGTICKET_H
#define PARKINGTICKET_H

#include "ParkingMeter.h"
#include "ParkedCar.h"

class ParkingTicket
{
private:
	string officerName;
	int officerNumber;
public:
	ParkingTicket(string s, int i);
	void reportCar(ParkedCar &IllegalCar);
	void reportFine(ParkedCar &IllegalCar, ParkingMeter &meter);
	void reportOfficer();
};
#endif