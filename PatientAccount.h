#pragma once
#include <iostream>
using namespace std;

class PatientAccount
{
private:
	const double dailyRate = 1000;
	int daysSpentInHospital;
	double charges;
public:
	PatientAccount(int);
	double getCharges();
	void addCharge(double);
};

