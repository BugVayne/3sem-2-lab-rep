#pragma once
#include "Human.h"
#include"Patient.h"
#include"Company.h"
class Doctor : public Human
{
private:
	vector<Patient> patient_list;
	vector<Product> product_list;
public:
	Doctor() {};
	Doctor(int _age, string _name) { this->age = _age; this->name = _name; }
	void AddPatient(Patient _patient) { this->patient_list.push_back(_patient); }
	pair<bool, string> SetIllness();
	Product SetPrescription(string _illness);
	void SetProductList(Company _company);
	Patient GetPatient() { return this->patient_list.at(0); }
};

