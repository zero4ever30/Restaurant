//
// Created by Momme Sherif on 28/05/2021.
//

#include "MixedDrink.hpp"
namespace RestLib {

    MixedDrink::MixedDrink(const std::string &_drinkname1, const std::string &_drinkname2) :
    Drink{_drinkname1 + "with "+_drinkname2} ,
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


}
