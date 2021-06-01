//
// Created by Momme Sherif on 28/05/2021.
//

#ifndef MAIN_CPP_DRINK_HPP
#define MAIN_CPP_DRINK_HPP
#include "string"
#include "vector"
#include "memory"
namespace RestLib
{
    class Drink {
    public:
        explicit Drink(const std::string &_drinkName);

        ~Drink();
        Drink() = delete;

        std::string GetName() const;
        /*virtual std::vector<std::string> getIngredients() const = 0;
        virtual int getNumberIngredients() const = 0;
        virtual void AddIngredients(const std::string& _ingredient) = 0;*/
    private:
        std::string drinkName;
    };
    using DrinkType = std::unique_ptr<Drink>;
}



#endif //MAIN_CPP_DRINK_HPP
