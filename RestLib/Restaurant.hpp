/*
 PIC - Labor Versuch 3
 Created by Mohamed Mahmoud 930154 and Tobias Fricke 932874
 Last Edit: 01/06/2021
*/

#ifndef FINAL_PROJECT_RESTAURANT_HPP
#define FINAL_PROJECT_RESTAURANT_HPP
#include <vector>
#include "Customer.hpp"
#include "item.hpp"
#include "Kitchen.hpp"
#include "DrinksBar.hpp"
#include <fstream>
#include <iostream>
#include <ctime>
#include <sstream>
#include "Ingredients.hpp"
#include "Finance.hpp"


namespace RestLib
{
    class Restaurant {

    public:
        explicit Restaurant(const std::string& restaurantName, const std::string& ownersName , const std::string& _filename);

        void Customer_List ();
        Customer& FindCustomer (std::string);
        void PrintOrderHistoryForAll();
        void AddToCustomers(Customer _newCustomer);
        void SaveHistory();
        friend class Customer;
        std::vector<Customer> vCustomers;
        std::vector<Ingredient> currentIngredients;
        void createNewOrder(const std::string& customerName, const int& dishIndex , const int& drinkIndex, const int& selectedMixIndex);



    protected:


    private:
        std::string Restaurant_name;
        std::string Owners_name;
        std::vector<item> Stock;
        std::string filename;
        RestLib::Finance financeStatistics {Restaurant_name , Owners_name };
        friend class QtWin;
    };
}

#endif //FINAL_PROJECT_RESTAURANT_HPP
