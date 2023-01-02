/*OOP345 WS06 P2
Name: Devang Ramubhai Ahir Ahir
Id: 153484209
Module: Car
File: Car.h*/

#ifndef _SDDS_CAR_H
#define _SDDS_CAR_H
#include <iostream>
#include "Vehicle.h"
namespace sdds {
	class Car : public Vehicle {
		std::string _Maker = "";
		std::string _Condition = "";
		double _TopSpeed = 0;
	public:
		//constructor
		Car(std::istream& in);
		//destructor
		~Car();
		//getters
		std::string condition() const;
		double topSpeed() const;
		//print
		void display(std::ostream& out) const;
	};
	//helpers
	std::string extract(std::string str, std::string delimeter);
	std::string trim(std::string str);
}
#endif // !_SDDS_CAR_H