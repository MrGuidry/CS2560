#include "Surgery.h"

Surgery::Surgery()
{
}

double Surgery::getSurgeryCost(int x)
{
	return surgeries[x-1];
}

void Surgery::updateCharges(double price, PatientAccount& patient)
{
	patient.addCharge(price);
}
