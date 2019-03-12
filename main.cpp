#include "ParkedCar.h"
#include "ParkingMeter.h"
#include "PoliceOfficer.h"

#include <iostream>
#include <string>
using namespace std;

int main() {
	
	//Creating first car and meter
	ParkedCar car1("Tesla", "Model 3", "Black", "8HHS900", 204);
	ParkingMeter meter1(60);
	
	//Creating second car and meter
	ParkedCar car2("Kia", "Forte", "Silver", "4FNQ345", 35);
	ParkingMeter meter2(60);
	
	//Creating third car and meter
	ParkedCar car3("Honda", "Civic", "White", "7JSY805", 60);
	ParkingMeter meter3(30);
	
	//Creating Pollice Officer
	PoliceOfficer officer("Billy Bronco", 509);

	//Checking each spot to see if the meter is expired
	//Issuing tickets if meter is expired
	if (officer.checkExpiration(car1, meter1)) { 
		cout << "------Parking Ticket------" << endl;
		officer.issueTicket(car1, meter1); 
	}
	if (officer.checkExpiration(car2, meter2)) { 
		cout << "------Parking Ticket------" << endl; 
		officer.issueTicket(car2, meter2); 
	}
	if (officer.checkExpiration(car3, meter3)) { 
		cout << "------Parking Ticket------" << endl;
		officer.issueTicket(car3, meter3); 
	}

}//END MAIN