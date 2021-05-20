//
// Created by Momme Sherif on 20/05/2021.
//

#include "Dishes.hpp"
#include <iostream>

using namespace std;

namespace RestLib
{

    void PizzaMargherita::Prepare() {
        cout << "Preparation steps for " << PizzaMargherita::GetDishName() << endl;


        unsigned int step {1};
        for(const auto &ingredient: vIngredients){
            cout << step << ". Step: Add " << ingredient << "." << endl;
            PizzaMargherita::AddIngredients(ingredient);
            step++;
        }
    }


    void VegetableSoup::Prepare() {
        cout << "Preparation steps for " << VegetableSoup::GetDishName() << endl;


        unsigned int step {1};
        for(const auto &ingredient: vIngredients){
            cout << step << ". Step: Add " << ingredient << "." << endl;
            VegetableSoup::AddIngredients(ingredient);
            step++;
        }
    }

}