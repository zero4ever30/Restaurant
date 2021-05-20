//
// Created by Momme Sherif on 19/05/2021.
//

#ifndef FINAL_PROJECT_CUSTOMER_HPP
#define FINAL_PROJECT_CUSTOMER_HPP


#include <iostream>
#include <memory>
#include "AbstractDish.hpp"
#include "vector"

using namespace std;

namespace RestLib {

    class Customer {
    public:
        Customer() = delete;
        explicit Customer(const string && _customerName);

    public:
        void ServeDish(DishType &_servedDish);
        void EatDish();
        string getName() const;
    protected:

    private:
        string customerName;
        float customerToPay;
        DishType customerDish;
        vector<DishType> customerDishes;
    };
}

#endif //FINAL_PROJECT_CUSTOMER_HPP
