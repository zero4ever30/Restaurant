/*
 PIC - Labor Versuch 3
 Created by Mohamed Mahmoud 930154 and Tobias Fricke 932874
 Last Edit: 01/06/2021
*/

#ifndef MAIN_CPP_MIXEDDRINK_HPP
#define MAIN_CPP_MIXEDDRINK_HPP

#include "Drink.hpp"
#include "Restaurant.hpp"
#include "Ingredients.hpp"
#include <vector>

namespace RestLib{

    class MixedDrink  : public  Drink {
    public:
        MixedDrink() = delete;
        MixedDrink(const std::string &_drinkname1, const std::string &_drinkname2);
        std::vector<Ingredient> GetIngredients();

        int getNumberIngredients() const;// override;
        void AddIngredients(const Ingredient& _ingredient) ;// override;

    private:
        std::vector<Ingredient> vIngredients;
    };
}



#endif //MAIN_CPP_MIXEDDRINK_HPP
