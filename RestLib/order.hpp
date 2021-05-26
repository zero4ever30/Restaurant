//
// Created by Momme Sherif on 26/05/2021.
//

#ifndef MAIN_CPP_ORDER_HPP
#define MAIN_CPP_ORDER_HPP
#include <string>
namespace RestLib
{
    class order {
    public:
        order() = delete;
        order(std::string _orderdate, std::string _ordername);
        std::string getOrderName();
        std::string getOrderDate();
    friend class Customer;
    private:
        std::string orderdate;
        std::string ordername;

    };

}



#endif //MAIN_CPP_ORDER_HPP
