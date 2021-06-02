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
#include "order.hpp"
#include "Drink.hpp"
#include "MixedDrink.hpp"

namespace RestLib {

    class DrinksBar {
    public:
        enum _DrinkType : int {
            Cola, Cola_Light, Sprite, Fanta, Water, Sparkling_Water, Red_Wine, White_Wine, Beer, Wheat_Beer, Banana_Juice, Apple_Juice, Cherry_Juice, Rum, Vodka, Gin, Redbull
        };
        static inline std::vector<std::string> availableDrinks  {"Cola", "Cola Light", "Sprite", "Fanta", "Water", "Sparkling Water", "Red Wine", "White Wine", "Beer", "Wheat Beer", "Banana Juice", "Apple Juice", "Cherry Juice", "Rum", "Vodka", "Gin", "Redbull"};
/*

        // Drink Template
        template<class type, class uniqueType>
        static type PrepareDrink(std::vector<_DrinkType> &vDrinkTypes) {
            type drink = std::make_unique<uniqueType>(DrinksBar::availableDrinks[vDrinkTypes[1]]);
            return drink;
        };

        template<class type>
        static type PrepareDrink(std::vector<_DrinkType> &vDrinkTypes) {
            type drink = std::make_unique<MixedDrink::Drink>(DrinksBar::availableDrinks[vDrinkTypes[1]], DrinksBar::availableDrinks[vDrinkTypes[2]]);
            return drink;
        };

/*
        / Drink Template specialization with parameter pack
        template<class ... Args>
        MixedDrink PrepareDrink(Args ... args) {
            std::vector<Args...> argVector{args...};
            MixedDrink _drink = std::make_unique<MixedDrink>(DrinksBar::availableDrinks[argVector[1]], DrinksBar::availableDrinks[argVector[2]]);
            return _drink;
        };
         */


/*
        // Drink Template with parameter pack
        template<class type, class ... Args>
        static type PrepareDrink(Args ... args) {
            std::vector<Args...> argVector{args...};
            type _drink = std::make_unique<type>(DrinksBar::availableDrinks[argVector[1]]);
            return _drink;
        };

        // Drink Template specialization with parameter pack
        template<class ... Args>
        static MixedDrink PrepareDrink(Args ... args) {
            std::vector<Args...> argVector{args...};
            MixedDrink _drink = std::make_unique<MixedDrink>(DrinksBar::availableDrinks[argVector[1]], DrinksBar::availableDrinks[argVector[2]]);
            return _drink;
        };
        */

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
