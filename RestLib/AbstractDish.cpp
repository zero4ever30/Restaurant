//
// Created by Tobia on 19.05.2021.
//

#include "AbstractDish.hpp"

using namespace std;

namespace RestLib {

    AbstractDish::AbstractDish(const string && _dishName)
            : dishName{_dishName} {}

    AbstractDish::~AbstractDish() = default;

    string AbstractDish::GetDishName() const {
        return dishName;
    }

    vector<std::string> AbstractDish::GetIngredients() const {
        return vIngredients;
    }

    int AbstractDish::GetNumberIngredients() const {
        return vIngredients.size();
    }

    void AbstractDish::AddIngredients(const std::string& _ingredient) {
        vIngredients.push_back(_ingredient);
    }
}