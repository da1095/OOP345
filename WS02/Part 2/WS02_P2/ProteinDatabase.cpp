
//Name: Vipin Yadav
//Email : vyadav7@myseneca.ca
//ID : 132527201
//Date: Jan 30, 2022

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//In this workshop, I learned how to use the move operator and the move assignment operator.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include<string>
using namespace std;

#include "ProteinDatabase.h"

namespace sdds {

	ProteinDatabase::ProteinDatabase() {
		string_Length = 0;
		arr = nullptr;
	}

	ProteinDatabase::ProteinDatabase(char* flName) {

		ifstream f(flName);

		string_Length = 0;
		arr = nullptr;

		if (!f)
			return;

		std::string ln, name;

		while (std::getline(f, ln).good()) {
			if (ln[0] == '>') {
				string_Length++;
			}
		}


		f.clear();
		f.seekg(std::ios::beg);

		arr = new string[string_Length];
		ln.clear();
		int i = -1;

		while (getline(f, ln).good()) {
			if (ln[0] == '>') {
				++i;
				name = ln.substr(1);

			}
			else if (!name.empty()) {
				arr[i] += ln;
			}

		}

	}
	ProteinDatabase::ProteinDatabase(const ProteinDatabase& old) {
		*this = old;
	}
	ProteinDatabase::~ProteinDatabase() {
		delete[] arr;
	}
	size_t ProteinDatabase::size() {
		return string_Length;
	}

	std::string ProteinDatabase::operator[](size_t pIndex) {
		if (pIndex < string_Length)
			return arr[pIndex];
		return "";
	}

	ProteinDatabase::ProteinDatabase(ProteinDatabase&& old)
	{
		*this = std::move(old);

	}
	ProteinDatabase& ProteinDatabase::operator=(const ProteinDatabase& srcP) {
		if (this != &srcP) {
			delete[] arr;
			string_Length = srcP.string_Length;
			arr = new string[string_Length]{};
			for (unsigned int i = 0; i < string_Length; i++) {
				arr[i] = srcP.arr[i];
			}
		}
		return *this;
	}
	ProteinDatabase& ProteinDatabase::operator=(ProteinDatabase&& srcP)
	{
		if (this != &srcP)
		{
			delete[] arr;
			arr = srcP.arr;

			srcP.arr = nullptr;
			string_Length = srcP.string_Length;

			srcP.string_Length = 0;
		}
		return *this;
	}


}