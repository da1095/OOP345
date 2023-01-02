/*OOP345 WS04 P2
Name: Devang Ramubhai Ahir Ahir
Id: 153484209
Module: Toy
File: Toy.h*/
#ifndef SDDS_TOY_H
#define SDDS_TOY_H

#include <string>

namespace sdds {
	class Toy
	{
		unsigned int m_OrderId;
		std::string m_Toy_Name;
		int m_No_Item;
		double m_Price;
		double m_HST = 0.13;

	public:
		Toy() = default;
		void update(int numItems);
		Toy(const std::string& toy);
		friend std::ostream& operator<<(std::ostream& os, const Toy& toy);
	};
}
#endif // !SDDS_TOY_H
