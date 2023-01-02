/*OOP345 WS06 P2
Name: Devang Ramubhai Ahir Ahir
Id: 153484209
Module: Car
File: Car.cpp*/

#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include "Car.h"
using namespace std;
namespace sdds {
	//constructor 
	Car::Car(std::istream& is) {
		string tag;
		string speed;
		string substr;
		getline(is, substr, '\n');
		is.seekg(0);//for racecar to extract booster
		//tag
		tag = trim(extract(substr, ","));
		substr.erase(0, substr.find(',') + 1);
		//make of the car
		_Maker = trim(extract(substr, ","));
		substr.erase(0, substr.find(',') + 1);
		//condition of the car
		_Condition = trim(extract(substr, ","));
		substr.erase(0, substr.find(',') + 1);
		if (_Condition == "n" || _Condition == "")
		{
			_Condition = "new";
		}
		else if (_Condition == "u") {
			_Condition = "used";
		}
		else if (_Condition == "b") {
			_Condition = "broken";
		}
		else
		{
			throw "Invalid record!";
		}

		try
		{
			speed = trim(extract(substr, ","));
			substr.erase(0, substr.find(',') + 1);
			for (char const& c : speed) {
				if (std::isdigit(c) == 0) throw "Invalid record!";
			}
			stringstream ss(speed);
			ss >> _TopSpeed;
		}
		catch (const char* msg)
		{
			throw "Invalid Record!";
		}

	}
	//destructor
	Car::~Car() {

	}
	//getters
	std::string Car::condition()const { return _Condition; }
	double Car::topSpeed()const { return _TopSpeed; }
	//print
	void Car::display(std::ostream& out)const {
		out << "| ";
		out << std::right;
		out.width(10);
		out << _Maker;
		out << " | ";

		out.width(6);
		out << std::left;
		out << condition();
		out << " | ";

		out.width(6);
		out << std::right;
		out << std::fixed;
		out << std::setprecision(2);
		out << topSpeed();
		out << " |";
	}
	//helpers
	string extract(string str, string delimeter) {
		string str_extract;
		str_extract = str.substr(0, str.find(delimeter));
		return str_extract;
	}
	string trim(string str) {
		str.erase(str.find_last_not_of(' ') + 1);
		str.erase(0, str.find_first_not_of(' '));
		return str;
	}
}
