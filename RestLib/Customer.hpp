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
#include "Drink.hpp"
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
        void ServeDrink(DrinkType &_servedDrink);
        void EatDish();
        void DrinkDrink();
        string getName() const;
        void printOrders ();
        int getNumberOfOrdersFromHistory();
        vector<order> getcustomerOrderHistory();
    protected:

    private:
        string customerName {""};
        string customerLastName {""};
        float customerToPay;
        DishType customerDish;
        DrinkType customerDrink;
        vector<order> customerOrderHistory;



    };
}

#endif //FINAL_PROJECT_CUSTOMER_HPP
