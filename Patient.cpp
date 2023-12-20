#include "Patient.h"
#include "Doctor.h"
void Patient::GoToDoctor()
{
	cout << " - Patient goes to doctor \n";
	Doctor my_doc = *(this->doctor);
	this->illness = my_doc.SetIllness();
	this->prescription = my_doc.SetPrescription(this->illness.second);
	cout << " - Patient has " << this->prescription.GetPurpose() << endl;;
}
void Patient::GoToMarket(MarketPlace _market)
{
	cout << "- patient is going to buy some treats\n";
	if (this->money <= 0)
	{
		cout << "- Patient has no money anyway\n";	
		return;
	}	
	if (!_market.AskForPills(this->prescription).second)
	{
		cout << "- Patient is going to cry\n";
		return;
	}
	else
	{
		cout << "- Patient is trying to buy them\n";
		if (_market.BuyPills(_market.AskForPills(this->prescription).first, this->money))
		{  
			cout << "- Patient bought his pills and is happy with them\n";
			this->CureIllness();
		}
		else
		{
			cout << "- Patient will try to get some money\n";
		}
	}
		


}
void Patient::CureIllness()
{
	this->illness.first = false;
	this->illness.second = "";
	this->prescription = Product("no  product");
}