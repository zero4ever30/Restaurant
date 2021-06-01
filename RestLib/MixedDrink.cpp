//
// Created by Momme Sherif on 28/05/2021.
//

#include "MixedDrink.hpp"
#include "Restaurant.hpp"
#include "Ingredients.hpp"

namespace RestLib {

    MixedDrink::MixedDrink(const std::string &_drinkname1, const std::string &_drinkname2) :
    Drink{_drinkname1 + " with "+_drinkname2} ,
    vIngredients{_drinkname1 , _drinkname2}{}

    std::vector<std::string> MixedDrink::getIngredients() const {
        return vIngredients;
    }

    int MixedDrink::getNumberIngredients() const {
        return vIngredients.size();
    }

    void MixedDrink::AddIngredients(const std::string& _ingredient) {
        vIngredients.push_back(_ingredient);
    }

    double MixedDrink::GetPrice() {
        double price {0};
        for (auto &IngredientName : vIngredients) {
            Ingredient localI = Ingredients::GetIngredientByName(IngredientName);
            price = price + (localI.GetPrice() / 2);
        }
        return price;
    }
}
