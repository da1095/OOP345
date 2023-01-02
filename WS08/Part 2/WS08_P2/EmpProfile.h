/*OOP345 WS08 P2
Name: Devang Ramubhai Ahir Ahir
Id: 153484209
Module: EmpProfile
File: EmpProfile.h*/


#ifndef SDDS_EMPPROFILE_H
#define SDDS_EMPPROFILE_H

#include <iomanip>
#include <string>
#include <fstream>
#include <iostream>

namespace sdds {
	struct Employee {
		std::string ID;
		std::string Name;
		bool load(std::ifstream& f) {
			f >> ID >> Name;
			return f.good();
		}

		void print(std::ostream& os) const {
			os << std::setw(10) << ID << std::setw(7) << Name << std::endl;
		}
	};

	struct Salary {
		std::string ID;
		double Salary;
		bool load(std::ifstream& f) {
			f >> ID >> Salary;
			return f.good();
		}

		void print(std::ostream& os) const {
			os << std::setw(10) << ID << std::setw(10) << Salary << std::endl;
		}
	};

	struct EmployeeWage {
		std::string Name{};
		double m_Salary{};
		int m_Counter{};
		static int recCount;
		static bool Trace;

		EmployeeWage() {
			m_Counter = ++recCount;
			if (Trace)
			{
				std::cout << "Default Constructor [" << m_Counter << "]" << std::endl;
			}
		}

		EmployeeWage(const std::string& str, double sal)
		{
			this->Name = str;
			this->m_Salary = sal;
			m_Counter = ++recCount;
			if (Trace)
			{
				std::cout << "Ovdrloaded Constructor" << std::setw(6) << "[" << m_Counter << "]" << std::endl;
			}
		}

		EmployeeWage(const EmployeeWage& copyEmpProf) {
			this->Name = copyEmpProf.Name;
			this->m_Salary = copyEmpProf.m_Salary;
			m_Counter = ++recCount;
			if (Trace)
			{
				std::cout << "Copy Constructor " << std::setw(11) << "[" << m_Counter << "] from [" << copyEmpProf.m_Counter << "]" << std::endl;
			}
		}

		~EmployeeWage() {
			if (Trace)
			{
				std::cout << "Destructor " << std::setw(17) << "[" << m_Counter << "]" << std::endl;
			}
		}

		void rangeValidator() {
			if (m_Salary > 99999 || m_Salary < 0) {
				throw std::string("*** Employees salaray range is not valid");
			}
		}


		void print(std::ostream& os)const {
			os << std::setw(15) << Name << std::setw(10) << m_Salary << std::endl;
		}

	};
}
#endif // !SDDS_EMPPROFILE_H
