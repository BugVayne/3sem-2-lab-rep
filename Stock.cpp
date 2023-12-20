#include "Stock.h"
size_t Stock::HowManyProductIsInStock(Product _product)
{
	return (*this->FindProduct(_product)).second;
}

void Stock::ReplenishProduct(Product _product, size_t _amount)
{
	if (this->FindProduct(_product) == nullptr)
	{
		this->Products_in_stock.push_back(make_pair(_product, _amount));
	}
	else
	{
	(*this->FindProduct(_product)).second += _amount;
	}
}
pair<Product, size_t>* Stock::FindProduct(Product _product)
{
	for (size_t i = 0; i < this->Products_in_stock.size(); i++)
	{
		if (this->Products_in_stock.at(i).first == _product) {
			pair<Product, size_t>* found_product = &this->Products_in_stock.at(i);
			return found_product;
		}
	}
	return nullptr;
}
 size_t Stock::TakeProductAway(Product _product)
{
	 size_t amount_in_stock;
	 for (size_t i = 0; i < this->Products_in_stock.size(); i++)
	 {
		 if (this->Products_in_stock.at(i).first == _product) {
			 amount_in_stock = this->Products_in_stock.at(i).second;
			 this->Products_in_stock.at(i).second = 0;
			 break;
		 }
	 }
	return amount_in_stock;	
}
