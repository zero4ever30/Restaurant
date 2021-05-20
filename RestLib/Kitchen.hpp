//
// Created by Momme Sherif on 19/05/2021.
//

#ifndef FINAL_PROJECT_KITCHEN_HPP
#define FINAL_PROJECT_KITCHEN_HPP


#include <memory>
#include "AbstractDish.hpp"
namespace RestLib {


    class Kitchen {


    public :
        enum class _DishType : int {
            PizzaMargherita, VegetableSoup
        };

        static RestLib::DishType CreatDish(_DishType const &dishType);

        Kitchen() = delete;
        ~Kitchen() = delete;
    protected:

    private:
    };
}



#endif //FINAL_PROJECT_KITCHEN_HPP
