#include "pch.h"
#include "CppUnitTest.h"
#include"Product.h"
#include"Doctor.h"
#include"Patient.h"
#include"Company.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(HumanTest)
	{
	public:
		
		TEST_METHOD(PrintInfoTest)
		{
			Human human;
			stringstream buf;
			streambuf* oldbuf = cout.rdbuf(buf.rdbuf());
			human.PrintInfo();
			cout.rdbuf(oldbuf);

			string output = buf.str();
			char a = output[0];
			Assert::AreEqual('t', a);
		}


	};
	TEST_CLASS(PatientTest)
	{
	public:
		TEST_METHOD(SetDoctorTest)
		{
			Patient pat(13, "ivan", 200);
			Doctor doc;
			bool flag=false;
			pat.SetDoctor(&doc);
			if (pat.GetDoctor() != nullptr)
				flag = true;
			Assert::IsTrue(flag);
		}
		TEST_METHOD(GoToDoctorTest)
		{
			vector<Product> products{ Product("Fairy tale",{ "no letter a"}, "testicular torsion", 100), Product("Old tale",{ "no letter c"}, "cancer", 300) };
			Company company(products);
			MarketPlace market(&company, 300);
			company.AddMarketPlace(market);
			Patient patient(13, "Jhon", 200);
			Doctor doctor(27, "peter");
			doctor.AddPatient(patient);
			patient.SetDoctor(&doctor);
			doctor.SetProductList(company);
			patient.GoToDoctor();
		}
		TEST_METHOD(GoToMarketTest1)
		{
			Patient pat(13, "ivan", 0);
			MarketPlace market;
			pat.GoToMarket(market);
		}
		TEST_METHOD(GoToMarketTest2)
		{
			Patient pat(13, "ivan", 200);
			MarketPlace market;
			pat.GoToMarket(market);
		}
		
		
	};
	TEST_CLASS(ProductTest)
	{
		TEST_METHOD(GetNameTest)
		{
			Product prod("gg", { "smth" }, "losing sanity", 100);
			char a = prod.GetName()[0];
			Assert::AreEqual('g', a);
		}
		TEST_METHOD(GetPurposeTest)
		{
			Product prod("gg", { "smth" }, "losing sanity", 100);
			char a = prod.GetPurpose()[0];
			Assert::AreEqual('l', a);
		}
		TEST_METHOD(GetPriceTest)
		{
			Product prod("gg", { "smth" }, "losing sanity", 100);
			double val = prod.GetPrice();
			Assert::AreEqual((double)100, val);
		}
		TEST_METHOD(GetUsageRulesTest1)
		{
			Product prod("gg", { "smth" }, "losing sanity", 100);
			char val = prod.GetUsageRules()[0][0];
			Assert::AreEqual('s', val);
		}
		TEST_METHOD(PrintInfoTest)
		{
			Product prod("gg", { "smth" }, "losing sanity", 100);
			stringstream buf;
			streambuf* oldbuf = cout.rdbuf(buf.rdbuf());
			prod.PrintInfo();
			cout.rdbuf(oldbuf);
			string output = buf.str();
			char a = output[0];
			Assert::AreEqual(' ', a);
		}
	};
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
