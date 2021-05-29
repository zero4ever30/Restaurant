//
// Created by Momme Sherif on 20/05/2021.
//

#ifndef FINAL_PROJECT_RESTAURANT_HPP
#define FINAL_PROJECT_RESTAURANT_HPP
#include <vector>
#include "Customer.hpp"
#include "item.hpp"
#include "Kitchen.hpp"
#include "DrinksBar.hpp"
//#include "../qtwin.h"

namespace RestLib
{
    class Restaurant {

    public:
        explicit Restaurant(const std::string& restaurantName, const std::string& _filename);

        void Customer_List ();
        Customer& FindCustomer (std::string);
        void PrintOrderHistoryForAll();
        void AddToCustomers(Customer _newCustomer);

        void SaveHistory();

        friend class Customer;

        std::vector<Customer> vCustomers;


        void createNewOrder(const std::string& customerName, const std::string& dishName, const std::string& drinkName , const int dishIndex , const int drinkIndex);
    protected:


    private:
        std::string Restaurant_name;
        std::vector<item> Stock;
        std::string filename;

    };

}



#endif //FINAL_PROJECT_RESTAURANT_HPP
