#ifndef PARKEDCAR_H
#define PARKEDCAR_H

#include <string>
using namespace std;

class ParkedCar
{
private:
	string make;
	string model;
	string color;
	string licenseNumber;
	int minutesParked;

public:
	ParkedCar(string,string,string,string,int);
	string getMake();
	string getModel();
	string getColor();
	string getLicensePlate();
	int getMinutesParked();
};
#endif