#include "pch.h"
#include "CppUnitTest.h"
#include"Product.h"
#include"Doctor.h"
#include"Patient.h"
#include"Company.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{




	TEST_CLASS(MarketPlaceTest)
	{
		TEST_METHOD(AddProductToTheListTest)
		{
			vector<Product> products{ Product("Fairy tale", { "no letter a" }, "testicular torsion", 100), Product("Old tale", { "no letter c" }, "cancer", 300) };
			Company company(products);
			MarketPlace market(&company, 300);
			Product prod("gg", { "smth" }, "losing sanity", 100);
			market.AddProductToTheList(prod);
		}
		TEST_METHOD(AskCompanyForMoreProductsTest)
		{
			vector<Product> products{ Product("Fairy tale", { "no letter a" }, "testicular torsion", 100), Product("Old tale", { "no letter c" }, "cancer", 300) };
			Company company(products);
			MarketPlace market(&company, 300);
			market.AskCompanyForMoreProducts(Product("Fairy tale", { "no letter a" }, "testicular torsion", 100));
		}
		TEST_METHOD(AskForPillsTest)
		{
			vector<Product> products{ Product("Fairy tale", { "no letter a" }, "testicular torsion", 100), Product("Old tale", { "no letter c" }, "cancer", 300) };
			Company company(products);
			MarketPlace market(&company, 300);
			market.AskForPills(Product("Fairy tale", { "no letter a" }, "testicular torsion", 100));

		}
		TEST_METHOD(BuyPillsTest1)
		{
			vector<Product> products{ Product("Fairy tale", { "no letter a" }, "testicular torsion", 100), Product("Old tale", { "no letter c" }, "cancer", 300) };
			Company company(products);
			MarketPlace market(&company, 300);
			double money = 200;
			market.BuyPills(Product("Fairy tale", { "no letter a" }, "testicular torsion", 100), money);
		}
		TEST_METHOD(BuyPillsTest2)
		{
			vector<Product> products{ Product("Fairy tale", { "no letter a" }, "testicular torsion", 100), Product("Old tale", { "no letter c" }, "cancer", 300) };
			Company company(products);
			MarketPlace market(&company, 300);
			double money = 20;
			market.BuyPills(Product("Fairy tale", { "no letter a" }, "testicular torsion", 100), money);
		}
	};
}
