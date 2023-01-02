#ifndef SDDS_TOY_H
#define SDDS_TOY_H
#include <string>


namespace sdds
{
	class Toy
	{
		int m_OrderId;
		std::string m_Toy_Name;
		int m_No_Item;
		double m_Price;
		double m_HST = 0.13;
	public:
		Toy();
		void update(int numItems);
		Toy(const std::string& toy);
		friend std::ostream& operator<<(std::ostream& os, const Toy& toy);
	};
}



#endif
