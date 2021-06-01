/*
 PIC - Labor Versuch 3
 Created by Mohamed Mahmoud 930154 and Tobias Fricke 932874
 Last Edit: 01/06/2021
*/

#include "Drink.hpp"

namespace RestLib
{
    Drink::Drink(const std::string &_drinkName):drinkName{_drinkName} {}
    Drink::~Drink() = default;

    std::string Drink::GetName() const {
        return drinkName;
    }

    std::vector<Ingredient> Drink::GetIngredients() {
        std::vector<Ingredient> vIngredients{Ingredients::GetIngredientByName(this->GetName())};
        return vIngredients;
    }
}