/*OOP345 WS06 P2
Name: Devang Ramubhai Ahir Ahir
Id: 153484209
Module: Racecar
File: Racecar.h*/

#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H
#include <iostream>
#include "Car.h"
using namespace std;
namespace sdds {
	class Racecar :public Car {
		double m_Booster = 0;
	public:
		//constructor
		Racecar(std::istream& in);
		//destructor
		~Racecar();
		//print
		void display(std::ostream& out)const;
		//getter
		double topSpeed()const;
	};
}
#endif // !SDDS_RACECAR_H