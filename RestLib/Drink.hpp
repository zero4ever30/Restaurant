/*
 PIC - Labor Versuch 3
 Created by Mohamed Mahmoud 930154 and Tobias Fricke 932874
 Last Edit: 01/06/2021
*/

#ifndef MAIN_CPP_DRINK_HPP
#define MAIN_CPP_DRINK_HPP
#include "string"
#include "vector"
#include "memory"
#include "vector"
#include "Ingredients.hpp"

namespace RestLib
{
    class Drink {
    public:
        explicit Drink(const std::string &_drinkName);

        ~Drink();
        Drink() = delete;

        std::string GetName() const;
        virtual std::vector<Ingredient> GetIngredients();

        /*virtual int GetNumberIngredients() const = 0;
        virtual void AddIngredients(const std::string& _ingredient) = 0;*/
    private:
        std::string drinkName;
        std::vector<Ingredient> vIngredients;
    };
    using DrinkType = std::unique_ptr<Drink>;
}



#endif //MAIN_CPP_DRINK_HPP
