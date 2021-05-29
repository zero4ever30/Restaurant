//
// Created by Momme Sherif on 28/05/2021.
//

#ifndef MAIN_CPP_MIXEDDRINK_HPP
#define MAIN_CPP_MIXEDDRINK_HPP
#include "Drink.hpp"
namespace RestLib{

    class MixedDrink  : public  Drink {
    public:
        MixedDrink() = delete;
        MixedDrink(const std::string &_drinkname1, const std::string &_drinkname2);
        std::vector<std::string> getIngredients() const;// override;
        int getNumberIngredients() const;// override;
        void AddIngredients(const std::string &_ingredient);// override;
    private:
        std::vector<std::string> vIngredients;


    };
}



#endif //MAIN_CPP_MIXEDDRINK_HPP
