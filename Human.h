#pragma once
#include<iostream>
#include<utility>
#include<vector>
using namespace std;
class Human
{
protected:
	string name;
	int age;
	pair<bool, string> illness;
	double money;
public:
	Human() { this->age = 0; this->name = ""; };
	virtual void PrintInfo() { cout << "this is a base class object"; }
};

