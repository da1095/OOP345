/*OOP345 WS05 P2
Name: Devang Ramubhai Ahir Ahir
Id: 153484209
Module: Book
File: Book.h*/



#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
using namespace std;
namespace sdds {

	class Book {

		string m_author{};
		string m_title{};
		string m_country{};
		size_t m_year{ 0 };
		double m_price{ 0 };
		string m_desc{};
		void exterminate(string& str);
	public:
		Book();
		const string& author() const;
		const string& title() const;
		const string& country() const;
		const size_t& year() const;

		double& price();
		const std::string& description() const;
		Book(const string& strBook);

		friend std::ostream& operator<< (std::ostream& os, const Book& book);

		template<typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(m_desc);
		}

	};

}

#endif