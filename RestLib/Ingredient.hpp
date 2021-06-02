/*
 PIC - Labor Versuch 3
 Created by Mohamed Mahmoud 930154 and Tobias Fricke 932874
 Last Edit: 01/06/2021
*/

#ifndef MAIN_CPP_INGREDIENT_HPP
#define MAIN_CPP_INGREDIENT_HPP

#include <string>

namespace RestLib {
    class Ingredient {
    public:
        Ingredient(const std::string &_name, const double &_price, const double &_priceToSell, const bool &_modifieable);

        std::string GetName() const;
        double GetPrice() const;
        double GetSellPrice() const;
        bool IsModifieable() const;

    private:
        std::string name;
        double price;
        double priceToSell;
        bool modifieable;
    };

    //using Ingredient = Ingredient;
}


#endif //MAIN_CPP_INGREDIENT_HPP
