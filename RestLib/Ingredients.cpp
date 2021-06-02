/*
 PIC - Labor Versuch 3
 Created by Mohamed Mahmoud 930154 and Tobias Fricke 932874
 Last Edit: 01/06/2021
*/

#include "Ingredients.hpp"

using namespace std;
using namespace RestLib;

void Ingredients::LoadIngredientsFromFile(const string& _filename) {
    //filename = _filename;

    // Create new filestream object
    ifstream ingredientsFile;

    try {
        // try to open ingredientsFile for reading
        ingredientsFile.open(_filename, ifstream::in);
        // possible exceptions
        ingredientsFile.exceptions(ifstream::failbit | ifstream::badbit);

        // as long as the file is open, readable and not finished keep reading
        while (!ingredientsFile.eof() && ingredientsFile.good()) {

            string nameI;
            string priceI;
            string priceISell;
            string modifieableI;
            getline(ingredientsFile, nameI, ',');
            if (ingredientsFile.peek() == ' ') {
                ingredientsFile.ignore(1);
            }
            getline(ingredientsFile, priceI, ',');
            if (ingredientsFile.peek() == ' ') {
                ingredientsFile.ignore(1);
            }
            getline(ingredientsFile, priceISell, ',');
            if (ingredientsFile.peek() == ' ') {
                ingredientsFile.ignore(1);
            }
            getline(ingredientsFile, modifieableI, ';');

            if (!nameI.empty() && !priceI.empty() && !priceISell.empty() && !modifieableI.empty()) {
                Ingredient NewIngredient(nameI, stod(priceI), stod(priceISell), (modifieableI == "1"));

                // adding ingredient to ingredient vector
                allIngredients.push_back(NewIngredient);
                allIngredientsByName.push_back(nameI);

                if (ingredientsFile.peek() == '\n') {
                    // Ignoring last char in ifstream
                    ingredientsFile.ignore(1);
                }
            }
        }
        // close ingredientsFile
        ingredientsFile.close();
    } catch (const system_error &e) {
        // exception handling
        cerr << "Error File could not be Found. " << _filename << endl
             << "Please Enter a file name ending with .txt .. Exting with error # : " << e.code().message() << endl
             << flush;
    }
}

Ingredient Ingredients::GetIngredientByName(const string &_name) {
    Ingredient foundIngredient("unknown", 0.0, 0.0, false);
    auto ret {find(allIngredientsByName.begin(), allIngredientsByName.end(), _name)};
    if(ret != allIngredientsByName.end()){
        foundIngredient = allIngredients[ret - allIngredientsByName.begin()];
    }
    return foundIngredient;
}

double Ingredients::CalculateIngredientsSellPrice(const vector<Ingredient>& vIngredients) {
    double retPrice {0};
    for (auto &ingredient : vIngredients) {
        retPrice = retPrice + ingredient.GetSellPrice();
    }
    return retPrice;
}

double Ingredients::CalculateIngredientsPrice(const vector<Ingredient>& vIngredients) {
    double retPrice {0};
    for (auto &ingredient : vIngredients) {
        retPrice = retPrice + ingredient.GetPrice();
    }
    return retPrice;
}
