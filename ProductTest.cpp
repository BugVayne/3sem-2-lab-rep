#include "pch.h"
#include "CppUnitTest.h"
#include"Product.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
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
}