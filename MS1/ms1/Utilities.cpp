// Name: Devang Ramubhai Ahir Ahir 
// Seneca Student ID: 153484209
// Seneca email: drahir-ahir@myseneca.ca
// Date of completion: 7/13/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include "Utilities.h"

char sdds::Utilities::m_Delimiter = '|';

void sdds::Utilities::setFieldWidth(size_t newWidth) {
    m_Width_Field = newWidth;
}

size_t sdds::Utilities::getFieldWidth() const {
    return m_Width_Field;
}

string sdds::Utilities::extractToken(const string& str, size_t& next_pos, bool& more) {

    if (str[next_pos] == m_Delimiter || next_pos >= str.length()) {
        more = false;
        throw invalid_argument("Invalid next_pos arguement");
    }

    string token = "";
    string whitespace = "";

    while (next_pos < (size_t)str.length()) {
        if (str[next_pos] != ' ') {
            if (str[next_pos] == '\n' || str[next_pos] == '\r') {
                break;
            }
            else if (str[next_pos] == m_Delimiter) {
                if (m_Width_Field < token.length()) {
                    m_Width_Field = token.length();
                }
                more = true;
                next_pos++;
                return token;
            }
            else {
                if (token.length() > 0) {
                    token += whitespace + str[next_pos];
                    whitespace = "";
                }
                else {
                    token += str[next_pos];
                    whitespace = "";
                }

                if (next_pos == (size_t)str.length() - 1) {
                    if (m_Width_Field < token.length()) {
                        m_Width_Field = token.length();
                    }
                    more = false;
                    next_pos++;
                    return token;
                }
            }
        }
        else {
            whitespace += ' ';
        }
        next_pos++;
    }

    more = false;
    return token;
}
