#include "MarketPlace.h"
#include"Company.h"
pair<Product, bool> MarketPlace::AskForPills(Product _product)
{
	for (size_t i = 0; i < this->products.size(); i++)
	{
		if (products.at(i).first == _product)
		{
			if (products.at(i).second < 1)
			{
				cout << "- Market has not enough of theese pills\n";
				AskCompanyForMoreProducts(_product);
			}
			cout << "- Market sells this product\n";
			return make_pair(products.at(i).first, true);
		}
	}
	cout << "- Market does not sell this product\n";
	return  make_pair(Product(), false);	
}

bool MarketPlace::BuyPills(Product _product, double& _money)
{
	for (size_t i = 0; i < products.size(); i++)
	{
		if (this->products.at(i).first == _product)
		{
			if (_money > this->products.at(i).first.GetPrice())
			{
			this->products.at(i).second--;
			this->cashbox += this->products.at(i).first.GetPrice();
			_money-= this->products.at(i).first.GetPrice();
			return true;
			}
			else {
				cout << "- You have not enough money\n";
				return false;
			}
			break;
		}
	}
	cout << "this is bad\n";
	return false;
}
void MarketPlace::AskCompanyForMoreProducts(Product _product)
{
	cout << "- Market asked Company for product\n";
	Company my_company = *(this->company);
	for (size_t i = 0; i < this->products.size(); i++)
	{
		if (this->products.at(i).first == _product)
		{
			this->products.at(i).second += my_company.GetProductsForMarket(_product);
			cout << "- Market got some more of this product\n";
			break;
		}
	}
}

MarketPlace::MarketPlace(Company* _company, double _cashbox)
{
	this->company = _company;
	this->cashbox = _cashbox;
	for (size_t i = 0; i < this->company->GetProductList().size(); i++)
	{
		this->products.push_back(make_pair(this->company->GetProductList().at(i), 0));
	}
}
void MarketPlace::AddProductToTheList(Product _product)
{
	this->products.push_back(make_pair(_product, 0));
}
