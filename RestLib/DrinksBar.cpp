/*
 PIC - Labor Versuch 3
 Created by Mohamed Mahmoud 930154 and Tobias Fricke 932874
 Last Edit: 19/05/2021
*/

#include "DrinksBar.hpp"
#include "AbstractDish.hpp"

namespace RestLib {
    DishType DrinksBar::OrderDrink(const DrinkType &dishType) {
        DishType _dish {nullptr};

        switch (dishType) {
            case DrinkType::Cola:
                //_dish = make_unique<Cola>("Cola");
                break;
            case DrinkType::Fanta:
                //_dish = make_unique<Fanta>("Fanta");
                break;
            case DrinkType::ColaLight:
                break;
            case DrinkType::Sprite:
                break;
            case DrinkType::Water:
                break;
            case DrinkType::Beer:
                break;
            case DrinkType::Sparklingwater:
                break;
            case DrinkType::Redwine:
                break;
            case DrinkType::Whitewine:
                break;
        }

        if (nullptr != _dish) {
            _dish->Prepare();
        }
        return _dish;
    }
}
