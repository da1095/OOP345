/*OOP345 WS06 P2
Name: Devang Ramubhai Ahir Ahir
Id: 153484209
Module: Vehicle
File: Vehicle.h*/


// Workshop 6 - STL Containers
// 2020/02/26 - Cornel

#ifndef SDDS_VEHICLE_H
#define SDDS_VEHICLE_H
#include <iostream>
#include <string>

namespace sdds
{
	class Vehicle
	{
	public:
		virtual double topSpeed() const = 0;
		virtual void display(std::ostream&) const = 0;
		virtual std::string condition() const = 0;
		virtual ~Vehicle() {};
	};
}

#endif