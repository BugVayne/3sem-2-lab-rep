#include "Company.h"
 size_t Company::GetProductsForMarket(Product _product)
{
	return this->stock.TakeProductAway(_product);
}
vector<Product> Company::GetProductList()
{
	return this->factory.GetProductList();
	
}
void Company::RequestToFactory(Product _product, size_t _amount)
{
	this->factory.ManufactureProducts(_product, _amount);
}
Company::Company(vector<Product> _products)
{
	this->marketing = Marketing();
	this->stock = Stock();
	this->factory = Factory(this->stock,_products );
	for (size_t i = 0; i < _products.size(); i++)
	{
		this->stock.ReplenishProduct(_products.at(i), 0);
		this->factory.ManufactureProducts(_products.at(i), 1);
	}
}
void Company::CreateNewProduct(Product _product)
{
	this->factory.ManufactureProducts(_product, 1);
	this->stock.ReplenishProduct(_product, 0);
	this->market_place.AddProductToTheList(_product);
}