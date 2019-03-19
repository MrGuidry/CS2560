#pragma once
#include "PatientAccount.h"
#include <iostream>
using namespace std;

class Pharmacy
{
private:
	double medications[5] = { 59.30,9.00,165.00,12.93,6.63};
public:
	Pharmacy();
	double getMedicationPrice(int);
	void updateCharges(double, PatientAccount&);
};

