/*OOP345 WS08 P2
Name: Devang Ramubhai Ahir Ahir
Id: 153484209
Module: GeneratingList
File: GeneratingList.h*/

#ifndef SDDS_GENERATINGLIST_H
#define SDDS_GENERATINGLIST_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <fstream>

namespace sdds {
	template<typename T>
	class GeneratingList {

		std::vector<T> List;
	public:

		GeneratingList() {}
		GeneratingList(const char* f) {
			std::ifstream file(f);
			if (!file)
				throw std::string("*** Failed to open file ") + std::string(f) + std::string(" ***");

			while (file) {
				T t;
				if (t.load(file))
					List.push_back(T(t));
			}
		}

		size_t size() const { return List.size(); }
		const T& operator[](size_t i) const { return List[i]; }

		bool luhnAlgorithm(std::string sin) {
			int sum = 0;
			int parity = false;

			for (int i = (int)sin.length() - 1; i >= 0; i--) {
				int digit = (int)(sin[i] - '0');

				if (parity) {
					digit = digit * 2;
				}

				sum += digit / 10;
				sum += digit % 10;
				parity = !parity;
			}

			return sum % 10 == 0;

		}

		void operator+=(std::unique_ptr<T>& t) {
			List.emplace_back(*t.get());
		}


		void operator+=(T* t) {
			List.emplace_back(*t);
		}


		void print(std::ostream& os) const {
			os << std::fixed << std::setprecision(2);
			for (auto& e : List)
				e.print(os);
		}
	};

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const GeneratingList<T>& rd) {
		rd.print(os);
		return os;
	}
}
#endif // !SDDS_GENERATINGLIST_H
