/*OOP345 WS04 P2
Name: Devang Ramubhai Ahir Ahir
Id: 153484209
Module: ConfirmOrder
File: Confirmorder.h*/
#ifndef SDDS_CONFIRMORDER_H
#define SDDS_CONFIRMORDER_H

#include "Toy.h"

namespace sdds
{
	class ConfirmOrder {
	private:
		const Toy** m_toy{ nullptr };
		size_t m_Number{ 0 };
	public:
		ConfirmOrder() = default;
		~ConfirmOrder();

		ConfirmOrder& operator=(const ConfirmOrder& order);
		ConfirmOrder(const ConfirmOrder& order);
		ConfirmOrder& operator=(ConfirmOrder&& order)noexcept;
		ConfirmOrder(ConfirmOrder&& order)noexcept;

		ConfirmOrder& operator+=(const Toy& toy);
		ConfirmOrder& operator-=(const Toy& toy);
		friend std::ostream& operator<<(std::ostream& os, const ConfirmOrder& order);
	};
}
#endif // !SDDS_CONFIRMORDER_H

