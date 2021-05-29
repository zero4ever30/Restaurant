//
// Created by Momme Sherif on 19/05/2021.
//

#include "Kitchen.hpp"
#include "Dishes.hpp"
#include <iostream>


using namespace std;

namespace RestLib {
    DishType Kitchen::CreatDish(_DishType const dishType , std::vector<std::string> _recipe) {

        DishType _dish {nullptr};
        switch (dishType) {
            case _DishType::PizzaMargherita:
                _dish = make_unique<RestLib::PizzaMargherita>("Pizza Margherita" , _recipe);
                break;
            case _DishType::VegetableSoup:
                _dish = make_unique<RestLib::VegetableSoup>("Vegetable Soup" , _recipe);
                break;
        }
        if (nullptr != _dish) {
            _dish->Prepare();
        }
        return _dish;
    }
}