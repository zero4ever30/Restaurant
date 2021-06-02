/*
 PIC - Labor Versuch 3
 Created by Mohamed Mahmoud 930154 and Tobias Fricke 932874
 Last Edit: 01/06/2021
*/
#include "Kitchen.hpp"
#include "Dishes.hpp"
#include <iostream>


using namespace std;

namespace RestLib {
    DishType Kitchen::CreatDish(_DishType const dishType , std::vector<Ingredient>& _recipe) {

        DishType _dish {nullptr};
        switch (dishType) {
            case _DishType::PizzaMargherita:
                _dish = make_unique<RestLib::PizzaMargherita>("Pizza Margherita", _recipe);
                break;
            case _DishType::VegetableSoup:
                _dish = make_unique<RestLib::VegetableSoup>("Vegetable Soup", _recipe);
                break;
        }
        if (nullptr != _dish) {
            _dish->Prepare();
        }
        return _dish;
    }
}