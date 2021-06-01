//
// Created by Momme Sherif on 28/05/2021.
//

#include "Drink.hpp"
#include "vector"
namespace RestLib
{

    Drink::Drink(const std::string &_drinkName):drinkName{_drinkName} {}
    Drink::~Drink() = default;

    std::string Drink::GetName() const {
        return drinkName;
    }

}