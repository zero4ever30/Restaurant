/*
 PIC - Labor Versuch 3
 Created by Mohamed Mahmoud 930154 and Tobias Fricke 932874
 Last Edit: 01/06/2021
*/

#include "Dishes.hpp"
#include <iostream>

using namespace std;

namespace RestLib
{
    void PizzaMargherita::Prepare() {
        cout << "Preparation steps for " << PizzaMargherita::GetDishName() << endl;

        unsigned int step {1};
        for(const auto &ingredient: vRecipe){
            cout << step << ". Step: Add " << ingredient.GetName() << "." << endl;
            PizzaMargherita::AddIngredients(ingredient);
            step++;
        }
    }

    void VegetableSoup::Prepare() {
        cout << "Preparation steps for " << VegetableSoup::GetDishName() << endl;

        unsigned int step {1};
        for(const auto &ingredient: vRecipe){
            cout << step << ". Step: Add " << ingredient.GetName() << "." << endl;
            VegetableSoup::AddIngredients(ingredient);
            step++;
        }
    }
}