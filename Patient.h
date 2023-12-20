#pragma once
#include "Human.h"
#include"MarketPlace.h"
class Doctor;
class Patient :	public Human
{
private:
	Product prescription;
	Doctor* doctor;
public:
	Patient() {};
	Patient(int _age, string _name, double _cash) { this->age = _age; this->name = _name; this->money = _cash; };
	Patient(Doctor* _doctor) :doctor(_doctor) {};
	void SetDoctor(Doctor *_doc) { this->doctor = _doc; };
	Doctor* GetDoctor() { return this->doctor; }
	Product GetPrescription() { return this->prescription; }
	void GoToDoctor();
	void GoToMarket(MarketPlace _market);
	void CureIllness();
};

