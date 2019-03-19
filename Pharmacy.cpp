#include "Pharmacy.h"

Pharmacy::Pharmacy()
{
}

double Pharmacy::getMedicationPrice(int x)
{
	return medications[x-1];
}

void Pharmacy::updateCharges(double price, PatientAccount& patient)
{
	patient.addCharge(price);
}

