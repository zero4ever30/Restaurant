/*
 PIC - Labor Versuch 3
 Created by Mohamed Mahmoud 930154 and Tobias Fricke 932874
 Last Edit: 01/06/2021
*/

#ifndef MAIN_CPP_INGREDIENTS_HPP
#define MAIN_CPP_INGREDIENTS_HPP

#include <vector>
#include <string>
#include "Ingredient.hpp"
#include <fstream>
#include <iostream>
#include <algorithm>

namespace RestLib {
    class Ingredients {
    public:
        static void LoadIngredientsFromFile(const std::string& _filename);
        static Ingredient GetIngredientByName(const std::string& _name);

        static double CalculateIngredientsSellPrice(const std::vector<Ingredient>& vIngredients);
        static double CalculateIngredientsPrice(const std::vector<Ingredient>& vIngredients);

        Ingredients() = delete;
        ~Ingredients() = delete;

        static std::string filename;
    private:
        static inline std::vector<Ingredient> allIngredients;
        static inline std::vector<std::string> allIngredientsByName;
    };
}

#endif //MAIN_CPP_INGREDIENTS_HPP
