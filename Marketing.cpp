#include "Marketing.h"
void VectorOutput(vector<string> vector)
{
	for (size_t i = 0; i < vector.size(); i++)
	{
		cout << "\n - " << vector.at(i) << endl;
	}
}
void Marketing::SetNewProductAdvertisment(Product _product)
{
	cout << "\n ------ ADVERTISMENT ---------\n";
	cout << " Hey, guys You heard about " << _product.GetName() << " ? \n";
	cout << " it is very great for curing " << _product.GetPurpose() << endl;
	cout << " But be careful there are some usage rules: ";
	VectorOutput(_product.GetUsageRules());
	cout << " only now for only " << _product.GetPrice() << endl;
}
