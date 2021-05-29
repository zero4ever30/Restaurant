
// Created by Tobia on 19.05.2021.
//

#include "AbstractDish.hpp"

using namespace std;

namespace RestLib {

    AbstractDish::AbstractDish(const std::string &&_dishName , const std::vector<std::string> _recipe )
            : dishName{_dishName} , vIngredients{_recipe} {}

    AbstractDish::~AbstractDish() = default;

    string AbstractDish::GetDishName() const {
        return dishName;
    }

    vector<std::string> AbstractDish::GetIngredients() const {
        return vIngredients;
    }

    int AbstractDish::GetNumberIngredients() const {
        return Used_Ingredients.size();
    }

    void AbstractDish::AddIngredients(const std::string& _ingredient) {
        Used_Ingredients.push_back(_ingredient);
    }
}