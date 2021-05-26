//
// Created by Momme Sherif on 20/05/2021.
//

#ifndef FINAL_PROJECT_RESTAURANT_HPP
#define FINAL_PROJECT_RESTAURANT_HPP
#include <vector>
#include "Customer.hpp"
#include "item.hpp"

namespace RestLib
{
    class Restaurant {

    public:
        explicit Restaurant(const std::string , const std::string);
        void Customer_List ();
        Customer& FindCustomer (std::string);
        void PrintOrderHistoryForAll();
        void AddToCustomers(Customer &);
    protected:


    private:
        std::string Restaurant_name;
        std::vector<Customer> vCustomers;
        std::vector<item> Stock;
    };

}



#endif //FINAL_PROJECT_RESTAURANT_HPP
