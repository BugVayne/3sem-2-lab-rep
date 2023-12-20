#pragma once
#include<iostream>
#include<vector>
#include<utility>
using namespace std;

class Product
{
private:
	string name;
	vector<string> usage_rules;
	string purpose;
	double price;
public:
	Product() {};
	Product(string _name) :name(_name) {};
	Product(string _name, vector<string> _restrictions, string _usage, double _cost_price):name(_name), usage_rules(_restrictions), purpose(_usage), price(_cost_price) {}
	string GetName() { return this->name; }
	vector<string> GetUsageRules() { return this->usage_rules; }
	string GetPurpose() { return this->purpose; }
	double GetPrice() { return this->price; }
	void PrintInfo();
	bool operator==(Product& _product)
	{
		return this->GetName() == _product.GetName();
	}
};

