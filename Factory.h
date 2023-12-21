#pragma once
#include"Stock.h"
#include"Product.h"
class Factory
{
private:
	Stock stock;
	vector<Product> manufactured_products;
public:
	Factory() {};
	Factory(Stock _stock, vector<Product> _manufactured):stock(_stock), manufactured_products(_manufactured){};
	void ManufactureProducts (Product _product, size_t size);
	vector<Product> GetProductList() { return this->manufactured_products; };
};

