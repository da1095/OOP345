/*OOP345 WS06 P2
Name: Devang Ramubhai Ahir Ahir
Id: 153484209
Module: Autoshop
File: Autoshop.cpp*/

#include <iostream>
#include <vector>
#include "Autoshop.h"
using namespace std;
namespace sdds {
	//operator overload
	Autoshop& Autoshop::operator+=(Vehicle* theVehicle) {
		m_Vehicles.push_back(theVehicle);
		return *this;
	}
	//destructor
	Autoshop::~Autoshop() {
		for (auto ptr = m_Vehicles.begin(); ptr < m_Vehicles.end(); ptr++)
			delete* ptr;
	}
	//print
	void Autoshop::display(std::ostream& out) const {
		out << "--------------------------------" << endl;
		out << "| Cars in the autoshop!        |" << endl;
		out << "--------------------------------" << endl;
		for (auto ptr = m_Vehicles.begin(); ptr < m_Vehicles.end(); ptr++) {
			(*ptr)->display(out);
			out << endl;
		}

		out << "--------------------------------" << endl;

	}
}