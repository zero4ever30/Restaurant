//
// Created by Momme Sherif on 19/05/2021.
//

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
        static RestLib::DishType CreatDish(_DishType const dishType);

        Kitchen() = delete;
        ~Kitchen() = delete;
    protected:

    private:
    };
}



#endif //FINAL_PROJECT_KITCHEN_HPP
