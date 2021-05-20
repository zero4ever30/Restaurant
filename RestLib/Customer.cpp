//
// Created by Momme Sherif on 19/05/2021.
//

#include "Customer.hpp"
using namespace std;

namespace RestLib {
    Customer::Customer(const string && _customerName)
            : customerName {_customerName}
    {}

    void Customer::ServeDish(DishType &_servedDish) {
        customerDish = move(_servedDish);
        cout << "The " << customerDish->GetDishName() << " for " << this->getName() << endl;
        this->customerDishes.push_back(move(customerDish));
    }

    void Customer::EatDish() {
        cout << this->getName() << " eats " << customerDish->GetDishName() << "." <<  endl;
        customerDish = nullptr;
    }

    string Customer::getName() const {
        return customerName;
    }
}