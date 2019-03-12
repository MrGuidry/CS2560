#include "ParkingMeter.h"

using namespace std;

//Constructor to create meter
ParkingMeter::ParkingMeter(int minutes)
{
	minutesPurchased = minutes;
}

//Accessor Function
int ParkingMeter::getMinutesPurchased(){return minutesPurchased;}
