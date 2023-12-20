#pragma once
#include"Product.h"


class Stock
{
private:
	vector<pair<Product, size_t>> Products_in_stock;
public:
	size_t HowManyProductIsInStock(Product _product);
	void ReplenishProduct(Product _product, size_t _amount);
	pair<Product, size_t>* FindProduct(Product _product);
	size_t TakeProductAway(Product _product);
};

