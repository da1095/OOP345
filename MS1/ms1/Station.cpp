// Name: Devang Ramubhai Ahir Ahir 
// Seneca Student ID: 153484209
// Seneca email: drahir-ahir@myseneca.ca
// Date of completion: 7/13/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <iomanip>
#include "Station.h"
#include "Utilities.h"

size_t sdds::Station::m_Width_Field = 0;
int sdds::Station::m_ID_Generator = 0;

sdds::Station::Station(string& record) {
    Utilities utilities;
    size_t next_pos = 0;
    bool more = true;

    m_ID = ++m_ID_Generator;
    m_Name = utilities.extractToken(record, next_pos, more);
    m_Next_Serial_Num = stoi(utilities.extractToken(record, next_pos, more));
    m_Num_Items = stoi(utilities.extractToken(record, next_pos, more));
    m_Width_Field = m_Width_Field > utilities.getFieldWidth() ? m_Width_Field : utilities.getFieldWidth();
    m_Description = utilities.extractToken(record, next_pos, more);
}

const string& sdds::Station::getItemName() const {
    return m_Name;
}

size_t sdds::Station::getNextSerialNumber() {
    return m_Next_Serial_Num++;
}

size_t sdds::Station::getQuantity() const {
    return m_Num_Items;
}

void sdds::Station::updateQuantity() {
    if (m_Num_Items > 0) {
        m_Num_Items--;
    }
}

void sdds::Station::display(ostream& os, bool full) const {
    os << setw(3) << setfill('0') << m_ID << " | ";
    os << left << setfill(' ') << setw(m_Width_Field + 1) << m_Name << " | ";
    os << right << setw(6) << setfill('0') << m_Next_Serial_Num << " | ";

    if (full) {
        os << setfill(' ');
        os << right;
        os << setw(4) << m_Num_Items << " | " << m_Description;
    }

    os << endl;
}