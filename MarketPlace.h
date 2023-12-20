#pragma once
#include"Product.h"
#include<utility>
class Company;
class MarketPlace
{
private:
	Company* company;
	vector<pair<Product, size_t>> products;
	double cashbox;
public:
	MarketPlace() {};
	MarketPlace(Company* _company, double _cashbox);
	pair<Product, bool> AskForPills(Product _product);
	bool BuyPills(Product _product, double& _money);
	void AskCompanyForMoreProducts(Product _product);
	void AddProductToTheList(Product _product);
 };

