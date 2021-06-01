//
// Created by Momme Sherif on 20/05/2021.
//

#include "Restaurant.hpp"

using namespace std;

namespace RestLib
{
    Restaurant::Restaurant(const string& restaurantName, const string& _filename) : Restaurant_name{restaurantName} {
        ifstream Datai;                                                // new in stream object
        filename = _filename;

        try {
            Datai.open(filename,ifstream::in);                        // open the file with the name (address) 'filename'
            Datai.exceptions(ifstream::failbit | ifstream::badbit);        // possible exceptions
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
                    tempCustomer.customerOrderHistory.push_back(move(tempOrder));
                }
                vCustomers.push_back(move(tempCustomer));
                if (!Datai.eof() && Datai.peek()=='\n') Datai.ignore(1); // deletes the \n)
            }
            Datai.close();                                                // file must be closed again
        } catch (const system_error& e) {                           // exception handling
            cerr << "Error File could not be Found: " << filename << endl
                      << "Please Enter a file name ending with .txt .. Exting with error # : " << e.code().message() << "\n" << flush;
        }

        Ingredients::LoadIngredientsFromFile("IngredientList.txt");
    }

    void Restaurant::SaveHistory() {
        ofstream Savefile;

        try {
            Savefile.open(filename, ofstream::out);                        // open the file with the name (address) 'filename'
            Savefile.exceptions(ofstream::failbit | ofstream::badbit);        // possible exceptions
            bool firstLine {false};
            for (const auto &_customer : vCustomers) {
                if (!firstLine) {
                    Savefile << _customer.getSaveName() << ";";
                    firstLine = true;
                } else {
                    Savefile << endl << _customer.getSaveName() << ";";
                }

                for (const auto &_orderHis : _customer.customerOrderHistory) {
                    Savefile << _orderHis.orderdate << ";" << _orderHis.ordername << ";";
                }
            }
            Savefile.close();

        } catch (const system_error& e) {                           // exception handling
            cerr << "Error File could not be Found. " << endl
                 << "Please Enter a file name ending with .txt .. Exting with error # : " << e.code().message() << "\n" << flush;
        }
    }

    Customer& Restaurant::FindCustomer(string _customerLastName) {
        /*for (auto &_Customer : vCustomers) {
            if (_Customer.getName() == _customerLastName)
                return _Customer;
            else
            {cerr << "User is not Fround" << endl;
                Customer a ("","");
                return a;                           ////////Falsch
            }
        }*/
    }

    void Restaurant::Customer_List() {
        for (auto const &_customer : vCustomers)
        {
            cout<<_customer.getName()<<endl;
        }
    }

    void Restaurant::PrintOrderHistoryForAll() {
        for ( RestLib::Customer &costumer : vCustomers)
        {
            costumer.printOrders();
        }
    }

    void Restaurant::AddToCustomers(Customer _newCustomer) {
        vCustomers.push_back(move(_newCustomer));
    }

    void Restaurant::createNewOrder(const string& customerName, const int& dishIndex , const int& drinkIndex, const int& selectedMixIndex) {
        //cout << "createNewOrder " << "dishIndex[" << dishIndex << "]" << "drinkIndex[" << drinkIndex << "]" << "selectedMixIndex[" << selectedMixIndex << "]" << endl;

        for (Customer& _customer : this->vCustomers) {
            if (_customer.getName() == customerName) {

                // Get current date
                time_t t = time(0);
                tm* now = localtime(&t);
                ostringstream stringStream;
                stringStream << now->tm_mday << "." << (now->tm_mon + 1) << "." << (now->tm_year + 1900);
                string orderDate = stringStream.str();

                // Create new dish order
                if (0 <= dishIndex) {
                    DishType dish = Kitchen::CreatDish((Kitchen::_DishType) dishIndex , this->currentIngredients);
                    order newDishOrder(orderDate, dish->GetDishName());

                    _customer.ServeDish(dish);
                    _customer.EatDish();

                    cout << "Customer: " << customerName << " ordered Dish: " << newDishOrder.getOrderName() << " [" << newDishOrder.getOrderDate() << "]" << endl;
                    _customer.customerOrderHistory.push_back(newDishOrder);
                }

                // Create new drink order
                if (0 <= drinkIndex) {
                    string drinkName;
                    if (0 <= selectedMixIndex){
                        DrinkType drink = DrinksBar::PrepareDrink((DrinksBar::_DrinkType)drinkIndex , (DrinksBar::_DrinkType) selectedMixIndex);
                        drinkName = drink->GetName();
                        _customer.ServeDrink(drink);
                    } else {
                        DrinkType drink = DrinksBar::PrepareDrink((DrinksBar::_DrinkType)drinkIndex);
                        drinkName = drink->GetName();
                        _customer.ServeDrink(drink);
                    }

                    _customer.DrinkDrink();
                    order newDrinkOrder(orderDate, drinkName);

                    cout << "Customer: " << customerName << " ordered Drink: " << newDrinkOrder.getOrderName() << " [" << newDrinkOrder.getOrderDate() << "]" << endl;
                    _customer.customerOrderHistory.push_back(newDrinkOrder);
                }
                break;
            }
        }
    }



}
