
// Created by Tobia on 19.05.2021.
//

#include "AbstractDish.hpp"

#include <utility>

using namespace std;

namespace RestLib {

    AbstractDish::AbstractDish(const std::string &&_dishName , std::vector<Ingredient> _recipe)
            : dishName{_dishName}, vRecipe{move(_recipe)} {}

    AbstractDish::~AbstractDish() = default;

    string AbstractDish::GetDishName() const {
        return dishName;
    }

    vector<Ingredient> AbstractDish::GetIngredients() const {
        return vIngredients;
    }

    int AbstractDish::GetNumberIngredients() const {
        return vIngredients.size();
    }

    void AbstractDish::AddIngredients(const Ingredient& _ingredient) {
        vIngredients.push_back(_ingredient);
    }
}