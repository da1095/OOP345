// Name: Devang Ramubhai Ahir Ahir 
// Seneca Student ID: 153484209
// Seneca email: drahir-ahir@myseneca.ca
// Date of completion: 7/13/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef STATION_H
#define STATION_H

#include <string>

using namespace std;

namespace sdds {
    class Station {
        int m_ID;
        string m_Name;
        string m_Description;
        unsigned int m_Next_Serial_Num;
        unsigned int m_Num_Items;

        static size_t m_Width_Field;
        static int m_ID_Generator;

    public:
        Station(string& record);
        const string& getItemName() const;
        size_t getNextSerialNumber();
        size_t getQuantity() const;
        void updateQuantity();
        void display(ostream& os, bool full) const;
    };
};


#endif