/*
 PIC - Labor Versuch 3
 Created by Mohamed Mahmoud 930154 and Tobias Fricke 932874
 Last Edit: 19/05/2021
*/

#ifndef MAIN_CPP_DRINKSBAR_HPP
#define MAIN_CPP_DRINKSBAR_HPP

#include <string>
#include <vector>
#include <memory>
#include "Drink.hpp"
#include "order.hpp"
#include "MixedDrink.hpp"

namespace RestLib {

    using  DrinkType = std::unique_ptr<Drink>;

    class DrinksBar {
    public:
        enum _DrinkType : int {
            Cola, Cola_Light, Sprite, Fanta, Water, Sparkling_Water, Red_Wine, White_Wine, Beer, Wheat_Beer, Banana_Juice, Apple_Juice, Cherry_Juice, Rum, Vodka, Gin, Redbull
        };
        static inline std::vector<std::string> availableDrinks  {"Cola", "Cola Light", "Sprite", "Fanta", "Water", "Sparkling Water", "Red Wine", "White Wine", "Beer", "Wheat Beer", "Banana Juice", "Apple Juice", "Cherry Juice", "Rum", "Vodka", "Gin", "Redbull"};




        static DrinkType PrepareDrink(_DrinkType const &drinkType);
        static DrinkType PrepareDrink(const _DrinkType &drinkType1, const _DrinkType &drinkType2);
        //static DrinkType Mix(_DrinkType const &drinkType1 , _DrinkType const &drinkType2);
        DrinksBar() = delete;
        ~DrinksBar() = delete;
    protected:

    private:


    };
}
#endif //MAIN_CPP_DRINKSBAR_HPP
