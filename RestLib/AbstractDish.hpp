/*
 PIC - Labor Versuch 3
 Created by Mohamed Mahmoud 930154 and Tobias Fricke 932874
 Last Edit: 01/06/2021
*/
#ifndef MAIN_CPP_ABSTRACTDISH_HPP
#define MAIN_CPP_ABSTRACTDISH_HPP


#include <string>
#include <vector>
#include <memory>
#include <string>
#include "Ingredient.hpp"

namespace RestLib {

    class AbstractDish {
    public:
        //AbstractDish() = default;

        explicit AbstractDish(const std::string &&_dishName , std::vector<Ingredient> _recipe);

        virtual ~AbstractDish();

    public:
        virtual void Prepare() = 0;

        std::string GetDishName() const;

        std::vector<Ingredient> GetIngredients() const;

        int GetNumberIngredients() const;

    protected:
        void AddIngredients(const Ingredient& _ingredient);

        std::vector<Ingredient> vIngredients;
        std::vector<Ingredient> vRecipe;
    private:
        std::string dishName;

    };
    using  DishType = std::unique_ptr<AbstractDish>;
}

#endif //MAIN_CPP_ABSTRACTDISH_HPP
