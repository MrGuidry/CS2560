#include "PatientAccount.h"
#include "Pharmacy.h"
#include "Surgery.h"
#include <iostream>

using namespace std;

int main() {
	cout << "-----Welcome to Billy Bronco Medical Hospital-----" << endl;
	
	//Get days in hospital
	bool good = false;
	int days;
	while (!good) {
		cout << "How many days will the patient be at the hospital?" << endl;
		cin >> days;
		if (days > 0) { 
			good = true; 
		}
		else {
			cout << "Invalid number of days...Try Again." << endl;
		}
	}

	//Creation of PatientAccount, Surgery, and Pharmacy
	PatientAccount patient(days);
	Surgery surgery;
	Pharmacy pharmacy;

	//Main loop
	bool finished = false;
	int choice;
	while (!finished) {
		bool valid = false;
		while (!valid) {
			cout << "----Hospital Main Menu----" << endl;
			cout << "1. Choose Surgery" << endl;
			cout << "2. Choose Medication" << endl;
			cout << "3. Checkout patient" << endl;
			cin >> choice;
			if (choice >= 1 && choice <= 3) { 
				valid = true; 
			}
			else {
				cout << "Invalid Choice...Try Again." << endl;
			}
		}
		switch (choice) {
			case 1:
				valid = false;
				while (!valid) {
					cout << "Which surgery would you like?" << endl;
					cout << "1. Hip Replacement" << endl;
					cout << "2. Knee Replacement" << endl;
					cout << "3. Gastric Bypass" << endl;
					cout << "4. Cornea" << endl;
					cout << "5. Spinal Fusion" << endl;
					cin >> choice;
					if (choice >= 1 && choice <= 5) { 
						valid = true; 
					}
					else {
						cout << "Invalid Choice...Try Again" << endl;
					}
				}
				surgery.updateCharges(surgery.getSurgeryCost(choice),patient);
				break;
			case 2:
				valid = false;
				while (!valid) {
					cout << "Which medication would you like?" << endl;
					cout << "1. Vicodin (60 10 mg tablets)" << endl;
					cout << "2. Amoxicillin (4 250 mg tablets)" << endl;
					cout << "3. Lipitor (30 10 mg tablets)" << endl;
					cout << "4. Hydrochlorothiazide (30 25 mg tablets)" << endl;
					cout << "5. Lisinopril (30 20 mg tablets)" << endl;
					cin >> choice;
					if (choice >= 1 && choice <= 5) {
						valid = true;
					}
					else {
						cout << "Invalid Choice...Try Again" << endl;
					}
				}
				pharmacy.updateCharges(pharmacy.getMedicationPrice(choice), patient);
				break;
			case 3:
				cout << "Patient has been checked out." << endl;
				cout << "Total Charges: $" << patient.getCharges() << endl;
				finished = true;
				break;
			default:
				break;
		}

	}

	return 0;
}
