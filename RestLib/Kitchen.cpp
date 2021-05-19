//
// Created by Momme Sherif on 19/05/2021.
//

#include "Kitchen.hpp"
#include <iostream>


using namespace std;

namespace RestLib {
    DishType Kitchen::CreatDish(DishType const &dishType) {

        DishType _dish {nullptr};
        switch (dishType) {
            case DishType::PizzaMargherita:
                _dish = make_unique<PizzaMargherita>("Pizza Margherita");
                break;
            case DishType::VegetableSoup:
                _dish = make_unique<VegetableSoup>("Vegetable Soup");
                break;
        }
        if (nullptr != _dish) {
            _dish->Prepare();
        }
        return _dish;
    }
}