#include "Fcatory.h"
void Factory::ManufactureProducts(Product _product, size_t size)
{
	bool is_produced = false;
	for (size_t i = 0; i <this->manufactured_products.size(); i++)
	{
		if (this->manufactured_products.at(i) == _product)
			is_produced = true;
	}
	if (!is_produced)
		this->manufactured_products.push_back(_product);
	this->stock.ReplenishProduct(_product, size);
}
