/*OOP345 WS07 P2
Name: Devang Ramubhai Ahir Ahir
Id: 153484209
Module: CovidCollection
File: CovidCollection.cpp*/




#include <fstream>
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <numeric>
#include "CovidCollection.h"

std::string sdds::CovidCollection::remove_spaces(std::string str) {
    std::string newStr = "";
    std::string spaces = "";

    for (unsigned int i = 0; i < str.length(); i++) {
        if (str[i] == ' ') {
            spaces += ' ';
        }
        else if (str[i] == '\r' || str[i] == '\n') {
            break;
        }
        else {
            newStr += spaces + str[i];
            spaces = "";
        }
    }

    return newStr;

}

sdds::CovidCollection::CovidCollection(std::string filename) {
    std::ifstream ifile(filename);
    std::string line;

    if (ifile.is_open()) {
        while (std::getline(ifile, line)) {
            Covid* tmp = new Covid();
            tmp->m_Country = remove_spaces(line.substr(0, 25));
            tmp->m_City = remove_spaces(line.substr(25, 25));
            tmp->m_Variant = remove_spaces(line.substr(50, 25));
            tmp->m_Year = stoi(line.substr(75, 5));
            tmp->m_Cases = stoi(line.substr(80, 5));
            tmp->m_deaths = stoi(line.substr(85, 5));
            covidList.emplace_back(tmp);
        }

    }
    else {
        throw std::invalid_argument("Invalid file!");
    }
}

std::ostream& sdds::operator<<(std::ostream& out, const Covid& theCovid) {
    out << std::left << "| " << std::setw(21) << theCovid.m_Country << " | ";
    out << std::setw(15) << theCovid.m_City << " | ";
    out << std::setw(20) << theCovid.m_Variant << " | ";
    out << std::right << std::setw(6) << (theCovid.m_Year >= 0 ? std::to_string(theCovid.m_Year) : "") << " | ";
    out << std::setw(4) << theCovid.m_Cases << " | ";
    out << std::setw(3) << theCovid.m_deaths << " |";

    return out;
}

void sdds::CovidCollection::display(std::ostream& out) const {
    int cases = 0;
    int deaths = 0;
    std::for_each(covidList.begin(), covidList.end(), [&out, &cases, &deaths](const Covid* theCovid) {
        out << *theCovid << std::endl;
        cases += theCovid->m_Cases;
        deaths += theCovid->m_deaths;
        });
    out << "----------------------------------------------------------------------------------------" << std::endl;
    out << "|" << std::right << std::setw(80) << "Total Cases Around the World:  " << cases << " |" << std::endl;
    out << "|" << std::right << std::setw(80) << "Total Deaths Around the World:  " << deaths << " |" << std::endl;
}

void sdds::CovidCollection::sort(std::string type) {
    std::sort(covidList.begin(), covidList.end(), [type](Covid* a, Covid* b) {
        if (type == "country") {
            return a->m_Country < b->m_Country;
        }
        else if (type == "variant") {
            return a->m_Variant < b->m_Variant;
        }
        else if (type == "cases") {
            return a->m_Cases < b->m_Cases;
        }
        else {
            return a->m_deaths < b->m_deaths;
        }
        });
}

void sdds::CovidCollection::cleanList() {
    std::for_each(covidList.begin(), covidList.end(), [](Covid* theCovid) {
        if (theCovid->m_Variant == "[None]") {
            theCovid->m_Variant = "";
        }
        });
}

bool sdds::CovidCollection::inCollection(std::string variant) const {
    return std::find_if(covidList.begin(), covidList.end(), [variant](Covid* theCovid) {
        return theCovid->m_Variant == variant;
        }) != covidList.end();
}

std::list<sdds::Covid> sdds::CovidCollection::getListForCountry(std::string country) const {
    std::list<Covid> list;
    std::for_each(covidList.begin(), covidList.end(), [&list, country](Covid* theCovid) {
        if (theCovid->m_Country == country) {
            list.emplace_back(*theCovid);
        }
        });
    return list;
}

std::list<sdds::Covid> sdds::CovidCollection::getListForVariant(std::string variant) const {
    std::list<Covid> list;
    std::for_each(covidList.begin(), covidList.end(), [&list, variant](Covid* theCovid) {
        if (theCovid->m_Variant == variant) {
            list.emplace_back(*theCovid);
        }
        });
    return list;
}

sdds::CovidCollection::~CovidCollection() {
    for (auto it = covidList.begin(); it != covidList.end(); it++) {
        delete* it;
    }
}