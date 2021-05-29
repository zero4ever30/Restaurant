//
// Created by Momme Sherif on 20/05/2021.
//

#ifndef FINAL_PROJECT_DISHES_HPP
#define FINAL_PROJECT_DISHES_HPP

#include "AbstractDish.hpp"
#include <string>

namespace RestLib {

    class PizzaMargherita : public AbstractDish {
    public:
        using AbstractDish::AbstractDish;

        void Prepare() override;

    protected:

    private:
        //std::vector<std::string> vIngredients {};//{"Pizza Dough", "Tomato Sauce", "Mozzarella", "Basil", "Cheese"};
    };


    class VegetableSoup : public AbstractDish {
    public:
        using AbstractDish::AbstractDish;

        void Prepare() override;

    protected:

    private:
        //std::vector<std::string> vIngredients {};//{"Onions", "Carrots", "Mushrooms", "Water", "Broth", "Processed Cheese"};
    };

}


#endif //FINAL_PROJECT_DISHES_HPP
