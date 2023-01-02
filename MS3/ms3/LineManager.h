// Name: Devang Ramubhai Ahir Ahir 
// Seneca Student ID: 153484209
// Seneca email: drahir-ahir@myseneca.ca
// Date of completion: 8/3/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_LINE_MANAGER_H
#define SDDS_LINE_MANAGER_H

#include <string>
#include <vector>
#include <iostream>
#include "Workstation.h"

using namespace std;

namespace sdds {
    class LineManager {
        vector<Workstation*> m_Active_Line;
        size_t m_cntCustomerOrder;
        Workstation* m_First_Station;

    public:
        LineManager(const string& file, const vector<Workstation*>& stations);
        void reorderStations();
        bool run(ostream& os);
        void display(ostream& os) const;
    };
};

#endif