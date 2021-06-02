/*
 PIC - Labor Versuch 3
 Created by Mohamed Mahmoud 930154 and Tobias Fricke 932874
 Last Edit: 19/05/2021
*/

#include "DrinksBar.hpp"

namespace RestLib {
    DrinkType DrinksBar::PrepareDrink(_DrinkType const &drinkType) {
        DrinkType _drink = std::make_unique<Drink>(DrinksBar::availableDrinks[drinkType]);
        return _drink;
    }
    DrinkType DrinksBar::PrepareDrink(const _DrinkType &drinkType1, const _DrinkType &drinkType2) {
        DrinkType _drink = std::make_unique<MixedDrink>(DrinksBar::availableDrinks[drinkType1] , DrinksBar::availableDrinks[drinkType2]);
        return _drink;
    }
}
