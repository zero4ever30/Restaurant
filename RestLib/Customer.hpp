//
// Created by Momme Sherif on 19/05/2021.
//

#ifndef FINAL_PROJECT_CUSTOMER_HPP
#define FINAL_PROJECT_CUSTOMER_HPP


#include <iostream>
#include <memory>
#include "AbstractDish.hpp"
#include "vector"
#include "order.hpp"
//#include "Restaurant.hpp"

using namespace std;

namespace RestLib {

    class Customer {
    public:
        Customer() = delete;
        explicit Customer(const string  _customerName , const string _customerLastName);
        friend class Restaurant;
    public:
        void ServeDish(DishType &_servedDish);
        void EatDish();
        string getName() const;
        void printOrders ();
    protected:

    private:
        string customerName {""};
        string customerLastName {""};
        float customerToPay;
        DishType customerDish;
        vector<order> customerOrderHistory;



    };
}

#endif //FINAL_PROJECT_CUSTOMER_HPP
