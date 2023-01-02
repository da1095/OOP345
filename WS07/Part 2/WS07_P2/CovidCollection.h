/*OOP345 WS07 P2
Name: Devang Ramubhai Ahir Ahir
Id: 153484209
Module: CovidCollection
File: CovidCollection.h*/



#ifndef SDDS_COVID_COLLECTION_H
#define SDDS_COVID_COLLECTION_H

#include <string>
#include <vector>
#include <algorithm>
#include <list>

namespace sdds {
    struct Covid {
        std::string m_Country;
        std::string m_City;
        std::string m_Variant;
        int m_Cases;
        int m_Year;
        int m_deaths;
    };

    class CovidCollection {
        std::vector<Covid*> covidList;
        std::string remove_spaces(std::string);

    public:
        CovidCollection(std::string);
        void display(std::ostream&) const;
        friend std::ostream& operator<<(std::ostream&, const Covid&);
        void sort(std::string);
        void cleanList();
        bool inCollection(std::string) const;
        std::list<Covid> getListForCountry(std::string) const;
        std::list<Covid> getListForVariant(std::string) const;
        ~CovidCollection();
    };

    std::ostream& operator<<(std::ostream&, const Covid&);
};

#endif