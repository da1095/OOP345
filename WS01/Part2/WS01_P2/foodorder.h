/*OOP345 WS01 P2
Name: Devang Ramubhai Ahir Ahir 
Id: 153484209
Module: foodorder
File: foodorder.h*/
#ifndef SDDS_FOODORDER_H
#define SDDS_FOODORDER_H 

extern double g_taxrate;
extern double g_dailydiscount;

namespace sdds {
	class FoodOrder {
		char Customer_Name[10];
		char* Food_Description{};
		double Food_Price;
		bool Is_Daily_Special;

	private:
		void set(const char* custName, const char* foodDesc, const double foodPrice, const char isDailySpecial);

		void setEmpty();

		double computeTax(double price, double tax);

		double computeDiscount(double price, double discount);

		bool isCustomerEmpty();

	public:
		FoodOrder();

		~FoodOrder();

		void read(std::istream& istr);

		void display();
	};
}

#endif