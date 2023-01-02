/*OOP345 WS06 P2
Name: Devang Ramubhai Ahir Ahir
Id: 153484209
Module: N/A
File: w6_p2.cpp*/



#include <iostream>
#include <iomanip>
#include <fstream>
#include "Autoshop.h"
#include "Autoshop.h"
#include "Utilities.h"
#include "Utilities.h"


void loadData(const char* filename, sdds::Autoshop& as)
{
	std::ifstream file(filename);
	if (!file)
	{
		std::cerr << "ERROR: Cannot open file [" << filename << "].\n";
		return;
	}
	while (file)
	{

		try {
			sdds::Vehicle* aVehicle = sdds::createInstance(file);
			if (aVehicle)
				as += aVehicle;
		}
		catch (char as) {
			std::cout << "Unrecognized record type: [" << as << "]" << std::endl;
		}
		catch (const char* msg) {
			std::cout << "Invalid record!" << std::endl;
		}
	}
}
int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	sdds::Autoshop as;
	loadData(argv[1], as);
	as.display(std::cout);
	std::cout << "\n";
	loadData(argv[2], as);
	as.display(std::cout);

	std::cout << std::endl;
	std::list<const sdds::Vehicle*> vehicles;
	{
		auto fastVehicles = [](const sdds::Vehicle* car)
		{
			if (car->topSpeed() > 300) {
				return true;
			}
			else
				return false;
		};
		as.select(fastVehicles, vehicles);
		std::cout << "--------------------------------\n";
		std::cout << "|       Fast Vehicles          |\n";
		std::cout << "--------------------------------\n";
		for (auto it = vehicles.begin(); it != vehicles.end(); ++it)
		{
			(*it)->display(std::cout);
			std::cout << std::endl;
		}
		std::cout << "--------------------------------\n";
	}

	vehicles.clear();
	std::cout << std::endl;
	{
		auto brokenVehicles = [](const sdds::Vehicle* car)
		{
			if (car->condition() == "broken") {
				return true;
			}
			else
				return false;
		};
		as.select(brokenVehicles, vehicles);
		std::cout << "--------------------------------\n";
		std::cout << "| Vehicles in need of repair   |\n";
		std::cout << "--------------------------------\n";
		for (auto it = vehicles.begin(); it != vehicles.end(); ++it)
		{
			(*it)->display(std::cout);
			std::cout << std::endl;
		}
		std::cout << "--------------------------------\n";
	}

	return 0;
}