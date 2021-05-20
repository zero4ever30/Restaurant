/*
 PIC - Labor Versuch 3
 Created by Mohamed Mahmoud 930154 and Tobias Fricke 932874
 Last Edit: 19/05/2021
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include "Customer.hpp"
#include "Kitchen.hpp"

using namespace std;
using namespace RestLib;

int main() {
    // 8 Vektor mit Datentyp Gerichten

    vector<DishType> vDishes;


    // 9 Factory erzeugt Gerichte
    vDishes.push_back(Kitchen::CreatDish(Kitchen::_DishType::PizzaMargherita));
    vDishes.push_back(Kitchen::CreatDish(Kitchen::_DishType::VegetableSoup));
    vDishes.push_back(Kitchen::CreatDish(Kitchen::_DishType::PizzaMargherita));
    vDishes.push_back(Kitchen::CreatDish(Kitchen::_DishType::VegetableSoup));

    // 10 Sortieren der Gerichte
    sort(vDishes.begin(), vDishes.end(), [](auto const & dish01 , const DishType& dish02) {
        return dish01->GetNumberIngredients() < dish02->GetNumberIngredients();
    });

    // 11 Ausgabe der Gerichte
    for(const auto &dish: vDishes){
        cout << "AbstractDish: " << dish->GetDishName() << " needs " << dish->GetNumberIngredients() << " Ingedients." << endl;
    }

    // 12 Vektor mit Datentyp Customer
    vector<unique_ptr<Customer>> vCustomer;

    vCustomer.push_back(make_unique<Customer>("Fred Firestone"));
    vCustomer.push_back(make_unique<Customer>("Homer Simpson"));
    vCustomer.push_back(make_unique<Customer>("Peter Griffin"));

    // 13 Servieren der Gerichte
    for(const auto &customer: vCustomer){
        cout << "Customer: " << customer->getName() << endl;
        unsigned long long maxSize {vDishes.size()};
        customer->ServeDish(vDishes.back());
        vDishes.resize(maxSize-1);
    }

    //14 Verspeisen der Gerichte
    for(const auto &customer: vCustomer){
        customer->EatDish();
    }
    return 0;
}
