/*
 PIC - Labor Versuch 3
 Created by Mohamed Mahmoud 930154 and Tobias Fricke 932874
 Last Edit: 01/06/2021
*/

#include "MixedDrink.hpp"

namespace RestLib {

    MixedDrink::MixedDrink(const std::string &_drinkname1, const std::string &_drinkname2) :
            Drink{_drinkname1 + " with "+_drinkname2} {

        this->AddIngredients(Ingredients::GetIngredientByName(_drinkname1));
        this->AddIngredients(Ingredients::GetIngredientByName(_drinkname2));
    }

    std::vector<Ingredient> MixedDrink::GetIngredients() {
        return vIngredients;
    }

    int MixedDrink::getNumberIngredients() const {
        return vIngredients.size();
    }

    void MixedDrink::AddIngredients(const Ingredient& _ingredient) {
        vIngredients.push_back(_ingredient);
    }
}
