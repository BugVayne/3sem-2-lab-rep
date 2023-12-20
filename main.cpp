#include"Product.h"
#include"Doctor.h"
#include"Patient.h"
#include"Company.h"
#include"MarketPlace.h"
int  main()
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
	patient.GoToMarket(market);
	Product newproduct("smth", { "somhow" }, "autism", 20);
	company.CreateNewProduct(newproduct);
	market.AddProductToTheList(newproduct);
	company.AdvertAProduct(newproduct);
	cout << "------------------\n";
	doctor.SetProductList(company);
	patient.GoToDoctor();
	patient.GoToMarket(market);

	return 0;
}