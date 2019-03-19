#include "PatientAccount.h"

PatientAccount::PatientAccount(int d)
{
	daysSpentInHospital = d;
	charges = (daysSpentInHospital * dailyRate);
}

double PatientAccount::getCharges()
{
	return charges;
}

void PatientAccount::addCharge(double price)
{
	charges += price;
}

