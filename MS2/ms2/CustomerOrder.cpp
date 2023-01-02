// Name: Devang Ramubhai Ahir Ahir 
// Seneca Student ID: 153484209
// Seneca email: drahir-ahir@myseneca.ca
// Date of completion: 7/27/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <utility>
#include "CustomerOrder.h"
#include "Utilities.h"

using namespace std;
using namespace sdds;

size_t CustomerOrder::m_widthField = 0;

CustomerOrder::CustomerOrder() :
    m_name{}, m_product{}, m_cntItem{}, m_lstItem{ nullptr } {

}

CustomerOrder::CustomerOrder(const string& input) {
    Utilities utility;
    size_t pos = 0;
    bool more = true;

    m_name = utility.extractToken(input, pos, more);
    m_product = utility.extractToken(input, pos, more);

    string listOfItems = "";
    size_t count = 0;

    do {
        string tmp = utility.extractToken(input, pos, more);
        if (listOfItems.length() > 0) {
            listOfItems += Utilities::getDelimiter();
        }
        listOfItems += tmp;
        count++;
    } while (more);

    m_lstItem = new Item * [count];
    m_cntItem = count;
    pos = 0;
    count = 0;
    more = true;

    do {
        string tmp = utility.extractToken(listOfItems, pos, more);
        m_lstItem[count++] = new Item(tmp);
    } while (more);

    if (m_widthField < utility.getFieldWidth()) {
        m_widthField = utility.getFieldWidth();
    }
}

CustomerOrder::CustomerOrder(const CustomerOrder& order) {
    throw string("Copy constructor cannot be called");
}

CustomerOrder::CustomerOrder(CustomerOrder&& order) noexcept :
    m_name{}, m_product{}, m_cntItem{}, m_lstItem{ nullptr } {
    *this = move(order);
}

CustomerOrder& CustomerOrder::operator=(CustomerOrder&& order) noexcept {
    if (this == &order) {
        return *this;
    }

    swap(m_name, order.m_name);
    swap(m_product, order.m_product);
    swap(m_cntItem, order.m_cntItem);
    swap(m_lstItem, order.m_lstItem);

    return *this;
}

CustomerOrder::~CustomerOrder() {
    for (size_t i = 0; i < m_cntItem; i++) {
        delete m_lstItem[i];
    }

    delete[] m_lstItem;
}

bool CustomerOrder::isOrderFilled() const {
    size_t count = 0;

    for (size_t i = 0; i < m_cntItem; i++) {
        if (m_lstItem[i]->m_Is_Filled) {
            count++;
        }
    }

    return count == m_cntItem;
}

bool CustomerOrder::isItemFilled(const string& itemName) const {
    size_t itemCount = 0;
    size_t filledCount = 0;

    for (size_t i = 0; i < m_cntItem; i++) {
        if (m_lstItem[i]->m_Item_Name == itemName) {
            itemCount++;

            if (m_lstItem[i]->m_Is_Filled) {
                filledCount++;
            }
        }
    }

    return itemCount == filledCount;
}

void CustomerOrder::fillItem(Station& station, ostream& os) {
    for (size_t i = 0; i < m_cntItem; i++) {

        if (m_lstItem[i]->m_Item_Name == station.getItemName()) {

            if (station.getQuantity() > 0) {

                m_lstItem[i]->m_Serial_Number = station.getNextSerialNumber();
                m_lstItem[i]->m_Is_Filled = true;
                station.updateQuantity();
                os << setw(11) << right;
                os << "Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_Item_Name << "]" << endl;
                break;

            }
            else {

                os << setw(11) << right;
                os << "Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_Item_Name << "]" << endl;
                break;

            }
        }
    }


}

void CustomerOrder::display(ostream& os) const {
    os << m_name << " - " << m_product << endl;

    for (size_t i = 0; i < m_cntItem; i++) {
        os << "[" << setw(6) << setfill('0') << m_lstItem[i]->m_Serial_Number << "] ";
        os << setfill(' ') << left;
        os << setw(m_widthField + 2) << m_lstItem[i]->m_Item_Name << " - ";
        os << (m_lstItem[i]->m_Is_Filled ? "FILLED" : "TO BE FILLED");
        os << endl;
    }
}
