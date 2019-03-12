#include "ParkedCar.h"

using namespace std;

//Constructor to create a car
ParkedCar::ParkedCar(string make, string model, string color, string plate, int minutes)
{
	this->make = make;
	this->model = model;
	this->color = color;
	this->licenseNumber = plate;
	minutesParked = minutes;
}

//Accessor Functions
string ParkedCar::getMake(){return make;}
string ParkedCar::getModel(){return model;}
string ParkedCar::getColor(){return color;}
string ParkedCar::getLicensePlate(){return licenseNumber;}
int ParkedCar::getMinutesParked(){return minutesParked;}
