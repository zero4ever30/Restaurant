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
#include "AbstractDish.hpp"

namespace RestLib {

    class DrinksBar {
    public:
        enum class DrinkType : int {
            Cola, ColaLight, Fanta, Sprite, Water, Beer, Sparklingwater, Redwine, Whitewine
        };
        static Dishtype OrderDrink(DrinkType const &drinkType);
    protected:

    private:

    };
}
#endif //MAIN_CPP_DRINKSBAR_HPP
