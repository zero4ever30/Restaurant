//
// Created by Momme Sherif on 20/05/2021.
//

#include "Restaurant.hpp"
#include <fstream>
#include <iostream>
#include <ctime>
#include <sstream>

namespace RestLib
{

    Restaurant::Restaurant(std::string _Restaurant_name , std::string FileName) : Restaurant_name{_Restaurant_name} {

        std::ifstream Datai;                                                // new in stream object


        try {
            Datai.open(FileName,std::ifstream::in);                        // open the file with the name (address) 'Filename'
            Datai.exceptions(std::ifstream::failbit | std::ifstream::badbit);        // possible exceptions
            while (!Datai.eof()&Datai.good()) {                           // as long as the file is open, readable and not finished keep reading

                string tempV {};
                string tempN {};
                getline(Datai,tempV,',');
                getline(Datai,tempN, ';');
                Customer tempCustomer(tempV, tempN);
                while (Datai.peek() != '\n' && !Datai.eof())
                {   order tempOrder("","");
                    getline(Datai,tempOrder.orderdate,';');
                    getline(Datai,tempOrder.ordername,';');
                    tempCustomer.customerOrderHistory.push_back(std::move(tempOrder));
                }
                vCustomers.push_back(std::move(tempCustomer));
                if (!Datai.eof() && Datai.peek()=='\n') Datai.ignore(1); // deletes the \n)
            }
            Datai.close();                                                // file must be closed again
        } catch (const std::system_error& e) {                           // exception handling
            std::cerr << "Error File could not be Found. " << std::endl
                      << "Please Enter a file name ending with .txt .. Exting with error # : " << e.code().message() << "\n" << std::flush;
        }
    }

    Customer& Restaurant::FindCustomer(std::string _customerLastName) {
        for (auto &_Customer : vCustomers) {
            if (_Customer.getName() == _customerLastName)
                return _Customer;
            else
            {std::cerr << "User is not Fround" << std::endl;
                Customer a ("","");
                return a;                           ////////Falsch
            }
        }
    }

    void Restaurant::Customer_List() {
        for (auto const &_customer : vCustomers)
        {
            std::cout<<_customer.getName()<<std::endl;
        }
    }

    void Restaurant::PrintOrderHistoryForAll() {
        for ( RestLib::Customer &costumer : vCustomers)
        {
            costumer.printOrders();
        }
    }

    void Restaurant::AddToCustomers(Customer _newCustomer) {
        vCustomers.push_back(std::move(_newCustomer));
    }

    void Restaurant::createNewOrder(const std::string& customerName, const std::string& dishName, const std::string& drinkName , const int dishIndex , const int drinkIndex) {
        for (Customer& _customer : this->vCustomers) {
            if (_customer.getName() == customerName) {
                // Get current date
                time_t t = time(0);
                tm* now = localtime(&t);
                ostringstream stringStream;
                stringStream << now->tm_mday << "." << (now->tm_mon + 1) << "." << (now->tm_year + 1900);
                string orderDate = stringStream.str();

                // Create new dish order
                if ("No Dish" != dishName) {
                    DishType dish = Kitchen::CreatDish((Kitchen::_DishType) dishIndex);
                    _customer.ServeDish(dish);
                    _customer.EatDish();
                    order newDish(orderDate, dishName);
                    cout << "Customer: " << customerName << " ordered Dish: " << newDish.getOrderName() << " [" << newDish.getOrderDate() << "]" << endl;

                    //_customer.ServeDish();
                    _customer.customerOrderHistory.push_back(newDish);
                }
                // Create new drink order
                if ("No Drink" != drinkName) {
                    DrinkType drink = DrinksBar::PrepareDrink((DrinksBar::_DrinkType)drinkIndex);
                    _customer.ServeDrink(drink);
                    _customer.DrinkDrink();
                    order newDrink(orderDate, drinkName);
                    cout << "Customer: " << customerName << " ordered Drink: " << newDrink.getOrderName() << " [" << newDrink.getOrderDate() << "]" << endl;
                    _customer.customerOrderHistory.push_back(newDrink);
                }
                break;
            }
        }

    }

}
