#include "pch.h"
#include "CppUnitTest.h"
#include"Product.h"
#include"Doctor.h"
#include"Patient.h"
#include"Company.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	
	TEST_CLASS(PatientTest)
	{
	public:
		TEST_METHOD(SetDoctorTest)
		{
			Patient pat(13, "ivan", 200);
			Doctor doc;
			bool flag = false;
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
	
	
}
