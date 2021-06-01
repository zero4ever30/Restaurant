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

    void Customer::ServeDrink(DrinkType &_servedDrink) {
        customerDrink = move(_servedDrink);
        cout << "The " << customerDrink->GetName() << " for " << this->getName() << endl;
    }

    void Customer::EatDish() {
        cout << this->getName() << " eats " << customerDish->GetDishName() << "." <<  endl;
        //this->customerOrderHistory.push_back(order("1.1.2000",customerDish->GetDishName()));        //// Date has to be changed
        customerDish = nullptr;

    }
    void Customer::DrinkDrink() {
        cout << this->getName() << " drinks " << customerDrink->GetName() << "." <<  endl;
        //this->customerOrderHistory.push_back(order("1.1.2000",customerDish->GetDishName()));        //// Date has to be changed
        customerDrink = nullptr;

    }

    string Customer::getName() const {
        string name = customerName + ' ' + customerLastName;
        return name;
    }

    string Customer::getSaveName() const {
        string saveName = customerName + ',' + customerLastName;
        return saveName;
    }

    void Customer::printOrders() {
        cout << "The costumer " << this->getName();
        if (!this->customerOrderHistory.empty()) {
            cout  << " has ordered  " << endl;
            for (auto &order : customerOrderHistory) {
                cout << "    " << order.getOrderName() << " on the " << order.getOrderDate() << std::endl;
            }
        }
        else cout  << " has ordered nothing yet " << endl;
    }

    int Customer::getNumberOfOrdersFromHistory() {
        return this->customerOrderHistory.size();
    }

    vector<order> Customer::getcustomerOrderHistory() {
        return customerOrderHistory;
    }
}