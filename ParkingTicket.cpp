#include "ParkingTicket.h"
#include <iostream>

//Constructor
ParkingTicket::ParkingTicket(string name, int number)
{
	officerName = name;
	officerNumber = number;
}

//Member Functions

//ReportCar prints out the car's information
void ParkingTicket::reportCar(ParkedCar & IllegalCar)
{
	cout << "Car Information" << endl;
	cout << "Make: " << IllegalCar.getMake() << endl;
	cout << "Model: " << IllegalCar.getModel() << endl;
	cout << "Color: " << IllegalCar.getColor() << endl;
	cout << "License Number: " << IllegalCar.getLicensePlate() << endl;
}

//ReportFine prints out the fine for the violation based on how much time they were parked over what they payed
void ParkingTicket::reportFine(ParkedCar & IllegalCar, ParkingMeter & meter)
{
	int fine = 0;
	double amountOver = IllegalCar.getMinutesParked() - meter.getMinutesPurchased();
	if (amountOver < 60) {
		fine = 25;
	}
	else {
		fine += 25;
		amountOver -= 60;
		while (amountOver > 0) {
			amountOver -= 60;
			fine += 10;
		}
	}
	cout << "Fine: $" << fine << endl;
}

//ReportOfficer prints out the information on the Officer who issued the ticket
void ParkingTicket::reportOfficer()
{
	cout << "Police Officer\nName: " << officerName << endl;
	cout << "Badge Number: " << officerNumber << endl;
}
