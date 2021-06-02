/*
 PIC - Labor Versuch 3
 Created by Mohamed Mahmoud 930154 and Tobias Fricke 932874
 Last Edit: 01/06/2021
*/

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
        string getSaveName() const;
        void printOrders ();
        int getNumberOfOrdersFromHistory();
        vector<order> getcustomerOrderHistory();
        void addToOpenOrders(order&);
        void Pay();
        float getDueAmount();
    protected:

    private:
        string customerName;
        string customerLastName;
        float customerToPay {0};
        DishType customerDish;
        DrinkType customerDrink;
        vector<order> customerOrderHistory;
        vector<order> openOrders;
    };
}

#endif //FINAL_PROJECT_CUSTOMER_HPP
