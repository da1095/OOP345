/*OOP345 WS04 P2
Name: Devang Ramubhai Ahir Ahir
Id: 153484209
Module: Child
File: Child.h*/
#ifndef SDDS_CHILD_H
#define SDDS_CHILD_H

#include <iostream>
#include <string>
#include "Toy.h"

namespace sdds {
	class Child
	{
	private:
		Toy* toy{};
		size_t m_Number;
		std::string m_Child_Name;
		int m_Age;
	public:
		Child();
		Child& operator=(const Child& child);
		Child(const Child& child);
		Child(Child&& child) noexcept;
		Child& operator=(Child&& child) noexcept;
		~Child();

		Child(std::string name, int age, const Toy* toys[], size_t count);
		size_t size() const;
		friend std::ostream& operator<<(std::ostream& os, const Child& child);
	};
}
#endif // !SDDS_CHILD_H
