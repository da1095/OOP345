/*OOP345 WS02 P2
Name: Devang Ramubhai Ahir Ahir
Id: 153484209
Module: proteindatabase
File: proteindatabase.h*/
#ifndef SDDS_PROTEINDATABASE_H_
#define SDDS_PROTEINDATABASE_H_

namespace sdds
{
	class ProteinDatabase
	{
	public:
		unsigned int string_Length = 0;
		std::string* arr = nullptr;

		ProteinDatabase();
		ProteinDatabase(char*);

		ProteinDatabase(ProteinDatabase&&);

		ProteinDatabase(const ProteinDatabase& old);

		size_t size();
		std::string operator[](size_t);
		ProteinDatabase& operator=(const ProteinDatabase&);
		ProteinDatabase& operator=(ProteinDatabase&&);


		~ProteinDatabase();

	private:

	};

}
#endif