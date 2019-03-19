#pragma once
#include "PatientAccount.h"
#include <iostream>
using namespace std;

class Surgery
{
private:
	double surgeries[5] = { 40364.00,35000.00,25000.00,17500.00,110000.00 };
public:
	Surgery();
	double getSurgeryCost(int);
	void updateCharges(double, PatientAccount&);
};

