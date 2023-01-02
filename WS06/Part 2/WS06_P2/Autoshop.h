/*OOP345 WS06 P2
Name: Devang Ramubhai Ahir Ahir
Id: 153484209
Module: Autoshop
File: Autoshop.h*/

#ifndef _SDDS_AUTOSHOP_H
#define _SDDS_AUTOSHOP_H
#include <iostream>
#include <vector>
#include <list>
#include "Vehicle.h"
namespace sdds {
	class Autoshop {
		std::vector<Vehicle*> m_Vehicles;
	public:
		//operator overloads
		Autoshop& operator+=(Vehicle* theVehicle);
		//destructor
		~Autoshop();
		//print
		void display(std::ostream& out) const;
		//template
		template <class T>
		void select(T test, std::list<const Vehicle*>& vehicles) {
			for (auto ptr = m_Vehicles.begin(); ptr < m_Vehicles.end(); ptr++) {
				if (test(*ptr)) {
					vehicles.push_back(*ptr);
				}
			}

		}

	};

}

#endif // !_SDDS_AUTOSHOP_H