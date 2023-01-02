/*OOP345 WS08 P2
Name: Devang Ramubhai Ahir Ahir
Id: 153484209
Module: WritingRecord
File: WritingRecord.cpp*/

#include "GeneratingList.h"
#include "EmpProfile.h"
#include "WritingRecord.h"

using namespace std;

namespace sdds {
	GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;

		for (unsigned int i = 0; i < emp.size(); i++) {

			for (unsigned int j = 0; j < sal.size(); j++) {

				if (emp[i].ID == sal[j].ID) {
					EmployeeWage* empWage = new EmployeeWage(emp[i].Name, sal[j].Salary);

					if (!activeEmp.luhnAlgorithm(emp[i].ID)) {
						delete empWage;
						throw std::string("*** This is not a valid sin number!");
					}
					else {
						try {
							empWage->rangeValidator();
						}
						catch (std::string err) {
							delete empWage;
							throw std::string(err);
						}
					}

					activeEmp += empWage;
					delete empWage;
				}
			}
		}


		return activeEmp;
	}

	GeneratingList<EmployeeWage> writeSmart(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;

		for (unsigned int i = 0; i < emp.size(); i++) {

			for (unsigned int j = 0; j < sal.size(); j++) {

				if (emp[i].ID == sal[j].ID) {
					std::unique_ptr<EmployeeWage> empWage = std::make_unique<EmployeeWage>(emp[i].Name, sal[j].Salary);

					if (!activeEmp.luhnAlgorithm(emp[i].ID)) {
						throw std::string("*** This is not a valid sin number!");
					}
					else {
						empWage.get()->rangeValidator();
					}

					activeEmp += empWage;
				}
			}
		}

		return activeEmp;
	}
}