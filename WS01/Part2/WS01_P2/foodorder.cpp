/*OOP345 WS01 P2
Name: Devang Ramubhai Ahir Ahir
Id: 153484209
Module: foodorder
File: foodorder.cpp*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>

#include "foodorder.h"

using namespace std;

double g_taxrate;
double g_dailydiscount;

namespace sdds {
	static int counter = 0;

	void FoodOrder::set(const char* custName, const char* foodDesc, const double foodPrice, const char isDailySpecial) {
		strcpy(Customer_Name, custName);

		Food_Description = new char[strlen(foodDesc) + 1];
		strcpy(Food_Description, foodDesc);

		Food_Price = foodPrice;
		Is_Daily_Special = isDailySpecial == 'Y' ? true : false;
	}

	void FoodOrder::setEmpty() {
		Food_Description = nullptr;
		Customer_Name[0] = '\0';
		Food_Price = -1;
		Is_Daily_Special = false;
	}

	double FoodOrder::computeTax(double price, double tax) {
		return price + (price * tax);
	}

	double FoodOrder::computeDiscount(double price, double discount) {
		return price - discount;
	}

	bool FoodOrder::isCustomerEmpty() {
		return Customer_Name[0] == '\0';
	}

	FoodOrder::FoodOrder() {
		setEmpty();
	};


	FoodOrder::~FoodOrder() {
		if (Food_Description != nullptr)
			delete[] Food_Description;
	};

	void FoodOrder::read(istream& istr) {
		setEmpty();

		char custName[10];
		istr.get(custName, 10, ',');

		istr.ignore();

		string foodDesc;
		getline(istr, foodDesc, ',');

		double foodPrice = -1;
		istr >> foodPrice;

		istr.ignore();

		char dailySpecialStatus;
		istr >> dailySpecialStatus;

		if (!istr.fail()) {
			// all data were read successfully, use the set private function to set values of the object to read value
			this->set(custName, foodDesc.c_str(), foodPrice, dailySpecialStatus);
		}
	}

	void FoodOrder::display() {
		if (isCustomerEmpty()) {
			cout << left << setw(2) << ++counter
				<< ". "
				<< "No Order"
				<< endl;
		}
		else {
			double taxedFoodPrice = computeTax(Food_Price, g_taxrate);
			double discountedTaxedFoodPrice = computeDiscount(taxedFoodPrice, g_dailydiscount);

			cout << left << setw(2) << ++counter
				<< ". "
				<< left << setw(10) << Customer_Name
				<< "|"
				<< left << setw(25) << Food_Description
				<< "|"
				<< left << setw(12) << fixed << setprecision(2) << taxedFoodPrice
				<< "|";

			if (Is_Daily_Special)
				cout << right << setw(13) << discountedTaxedFoodPrice;

			cout << endl;
		}
	}
}