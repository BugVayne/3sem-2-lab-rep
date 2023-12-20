#pragma once
#include<vector>
#include"Fcatory.h"
#include<utility>
#include"Product.h"
#include"Stock.h"
#include"Marketing.h"
#include"MarketPlace.h"
class Company
{
private:
	Stock stock;
	Factory factory;
	Marketing marketing;
	MarketPlace market_place;
public:
	Company() {};
	Company(vector<Product>);
	size_t GetProductsForMarket(Product _product);
	vector<Product> GetProductList();
	void RequestToFactory(Product _product, size_t _amount);
	void CreateNewProduct(Product _product);
	void AdvertAProduct(Product _product) { this->marketing.SetNewProductAdvertisment(_product); }
	void AddMarketPlace(MarketPlace _market_place) { this->market_place = _market_place; }
};

