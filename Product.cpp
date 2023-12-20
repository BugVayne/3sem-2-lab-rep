#include "Product.h"

void Product::PrintInfo()
{
	cout << " - This Product is - " << this->name << endl;
	cout <<" \t- This product is used for curing "<<this->purpose << endl;
	if (this->usage_rules.size() == 0)
		cout << "\t- This product has no restrictions " << endl;
	else
	{
		cout << "\t- Usage rules:\n";
		for (size_t i = 0; i < this->usage_rules.size(); i++)
		{
			cout << "\t\t - " << this->usage_rules.at(i) << endl;
		}
	}
	cout << "\t- This product cost - " << this->price << endl;
}
