/*
 PIC - Labor Versuch 3
 Created by Mohamed Mahmoud 930154 and Tobias Fricke 932874
 Last Edit: 01/06/2021
*/

#ifndef FINAL_PROJECT_KITCHEN_HPP
#define FINAL_PROJECT_KITCHEN_HPP


#include <memory>
#include "AbstractDish.hpp"
#include "string"
namespace RestLib {


    class Kitchen {


    public :
        enum  _DishType : int {
            PizzaMargherita = 0, VegetableSoup = 1
        };
        static inline std::vector<std::string> availableDishes {"Pizza Margherita" , "Vegetable Soup"};
        static inline const std::vector<std::vector<std::string>> Recipes {{"Pizza Dough", "Tomato Sauce", "Mozzarella", "Basil", "Cheese"},{"Onions", "Carrots", "Mushrooms", "Water", "Broth", "Processed Cheese"}}; // one can use _DishType too


        static RestLib::DishType CreatDish(_DishType const dishType , std::vector<Ingredient>& _recipe);

        Kitchen() = delete;
        ~Kitchen() = delete;
    protected:

    private:
    };
}



#endif //FINAL_PROJECT_KITCHEN_HPP
