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
        explicit Restaurant(const std::string , const std::string);
        void Customer_List ();
        Customer& FindCustomer (std::string);
        void PrintOrderHistoryForAll();
        void AddToCustomers(Customer _newCustomer);
        friend class Customer;
        friend class QtWin;

        std::vector<Customer> vCustomers;


        void createNewOrder(const std::string& customerName, const std::string& dishName, const std::string& drinkName , const int dishIndex , const int drinkIndex);
    protected:


    private:
        std::string Restaurant_name;
        std::vector<item> Stock;


    };

}



#endif //FINAL_PROJECT_RESTAURANT_HPP
