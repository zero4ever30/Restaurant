/*
 PIC - Labor Versuch 3
 Created by Mohamed Mahmoud 930154 and Tobias Fricke 932874
 Last Edit: 01/06/2021
*/


#include "Ingredient.hpp"
#include <iostream>

using namespace std;
using namespace RestLib;

Ingredient::Ingredient(const string &_name, const double &_price, const double &_priceToSell, const bool &_modifieable)
{
    name = _name;
    price = _price;
    priceToSell = _priceToSell;
    modifieable = _modifieable;
}

std::string Ingredient::GetName() const {
    return name;
}

double Ingredient::GetPrice() const {
    return price;
}

double Ingredient::GetSellPrice() const {
    return priceToSell;
}

bool Ingredient::IsModifieable() const {
    return modifieable;
}