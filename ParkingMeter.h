#ifndef PARKINGMETER_H
#define PARKINGMETER_H

class ParkingMeter
{
private:
	int minutesPurchased;
public:
	ParkingMeter(int);
	int getMinutesPurchased();
};
#endif