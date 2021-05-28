//
// Created by Momme Sherif on 26/05/2021.
//

#include "order.hpp"
#include <iostream>
#include <ctime>
#include <utility>
#include <vector>
#include <sstream>
#include "Customer.hpp"

using namespace std;
using namespace RestLib;

order::order(string _orderdate, string _ordername) : orderdate{move(_orderdate)} , ordername {move(_ordername)} {

}

string order::getOrderName() {
    return this->ordername;
}

string order::getOrderDate() {
    return this->orderdate;
}

void order::createNewOrder(const string &customerName, const string &dishName, const std::string& drinkName) {
    // Get current date
    time_t t = time(0);
    tm* now = localtime(&t);
    ostringstream stringStream;
    stringStream << now->tm_mday << "." << (now->tm_mon + 1) << "." << (now->tm_year + 1900);
    string orderDate = stringStream.str();

    // Create new dish order
    if ("No Dish" != dishName) {
        order newDish(orderDate, dishName);
        cout << "Customer: " << customerName << " ordered Dish: " << newDish.getOrderName() << " [" << newDish.getOrderDate() << "]" << endl;
    }
    // Create new drink order
    if ("No Drink" != drinkName) {
        order newDrink(orderDate, drinkName);
        cout << "Customer: " << customerName << " ordered Drink: " << newDrink.getOrderName() << " [" << newDrink.getOrderDate() << "]" << endl;
    }
}
