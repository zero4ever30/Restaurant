//
// Created by Momme Sherif on 19/05/2021.
//

#include "Customer.hpp"
using namespace std;

namespace RestLib {
    Customer::Customer(const string _customerName , const string _customerLastName)
            : customerName {_customerName} , customerLastName{_customerLastName}
    {}

    void Customer::ServeDish(DishType &_servedDish) {
        customerDish = move(_servedDish);
        cout << "The " << customerDish->GetDishName() << " for " << this->getName() << endl;

    }

    void Customer::EatDish() {
        cout << this->getName() << " eats " << customerDish->GetDishName() << "." <<  endl;
        this->customerOrderHistory.push_back(order("1.1.2000",customerDish->GetDishName()));        //// Date has to be changed
        customerDish = nullptr;

    }

    string Customer::getName() const {
        string name = customerName + ' ' + customerLastName;
        return name;
    }

    void Customer::printOrders() {
        cout << "The costumer " << this->getName() << " has ordered  ";
        for (auto &order : customerOrderHistory)
        {
            cout << order.getOrderName() << " on the " << order.getOrderDate() << std::endl;
        }
    }
}