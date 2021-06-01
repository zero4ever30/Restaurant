/*
 PIC - Labor Versuch 3
 Created by Mohamed Mahmoud 930154 and Tobias Fricke 932874
 Last Edit: 01/06/2021
*/

#include "order.hpp"
#include <iostream>
#include <utility>
#include <vector>
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


