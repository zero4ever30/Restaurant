//
// Created by Momme Sherif on 26/05/2021.
//

#include "order.hpp"
#include <iostream>
#include <utility>

RestLib::order::order(std::string _orderdate, std::string _ordername) : orderdate{std::move(_orderdate)} , ordername {std::move(_ordername)} {

}

std::string RestLib::order::getOrderName() {
    return this->ordername;
}

std::string RestLib::order::getOrderDate() {
    return this->orderdate;
}

