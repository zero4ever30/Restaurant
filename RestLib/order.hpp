/*
 PIC - Labor Versuch 3
 Created by Mohamed Mahmoud 930154 and Tobias Fricke 932874
 Last Edit: 01/06/2021
*/

#ifndef MAIN_CPP_ORDER_HPP
#define MAIN_CPP_ORDER_HPP
#include <string>

namespace RestLib
{
    class order {
    public:
        order() = delete;

        order(std::string _orderdate, std::string _ordername , double price);
        std::string getOrderName();
        std::string getOrderDate();
        double getOrderPrice() const;
        friend class Restaurant;
    private:
        std::string orderdate;
        std::string ordername;
        double orderPrice;
    };

}



#endif //MAIN_CPP_ORDER_HPP
