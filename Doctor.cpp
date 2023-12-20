#include "Doctor.h"
pair<bool, string> Doctor::SetIllness()
{
	cout << "- Doctor sets illness\n";
	vector<string> illnesses;
	for (size_t i = 0; i < this->product_list.size(); i++)
	{
		illnesses.push_back(this->product_list.at(i).GetPurpose());
	}
	srand(time(0));
	return make_pair(true, illnesses.at(rand() % illnesses.size()));
}
Product Doctor::SetPrescription(string _illness)
{
	cout << "- Doctor sets prescription\n";
	if (this->product_list.size() < 1)
	{
		cout << "- Doctor dont know any treatments and cant set prescription\n";
		return Product("ERROR - product");
	}
	for (size_t i = 0; i < this->product_list.size(); i++)
	{
		if (this->product_list.at(i).GetPurpose() == _illness)
			return this->product_list.at(i);
	}
	
}
void Doctor::SetProductList(Company _company)
{
	cout << "- Doctor gets treatmeny list he can prescript somebody\n";
	this->product_list = _company.GetProductList();
}