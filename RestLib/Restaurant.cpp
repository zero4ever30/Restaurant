/*
 PIC - Labor Versuch 3
 Created by Mohamed Mahmoud 930154 and Tobias Fricke 932874
 Last Edit: 01/06/2021
*/

#include "Restaurant.hpp"

using namespace std;

namespace RestLib
{
    Restaurant::Restaurant(const std::string& restaurantName, const std::string& ownersName , const std::string& _filename) : Restaurant_name{restaurantName}, Owners_name{ownersName} {
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
                {   order tempOrder("","" , 0);
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

        // Initialize Ingredients
        Ingredients::LoadIngredientsFromFile("IngredientList.txt");

        // Load FinanceClass
        this->financeStatistics.LoadFinanceClass("FinanceStatistics.txt");
    }

    void Restaurant::SaveHistory() {
        ofstream Savefile;

        try {
            Savefile.open(filename, ofstream::out);                        // open the file with the name (address) 'filename'
            Savefile.exceptions(ofstream::failbit | ofstream::badbit);        // possible exceptions
            bool firstLine {true};
            for (const auto &_customer : vCustomers) {
                if (firstLine) {
                    Savefile << _customer.getSaveName() << ";";
                    firstLine = false;
                } else {
                    Savefile << endl << _customer.getSaveName() << ";";
                }

                for (const auto &_orderHis : _customer.customerOrderHistory) {
                    Savefile << _orderHis.orderdate << ";" << _orderHis.ordername << ";";
                }
            }
            Savefile.close();

        } catch (const system_error& e) {                           // exception handling
            cerr << "Error File could not be Found. " << filename << endl
                 << "Please Enter a file name ending with .txt .. Exting with error # : " << e.code().message() << "\n" << flush;
        }

        this->financeStatistics.SaveFinanceClass("FinanceStatistics.txt");
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

                double sellPrice{0};
                double price{0};

                // Create new dish order
                if (0 <= dishIndex) {
                    DishType dish = Kitchen::CreatDish((Kitchen::_DishType) dishIndex , this->currentIngredients);

                    sellPrice = Ingredients::CalculateIngredientsSellPrice(this->currentIngredients);
                    this->financeStatistics.AddMoneyInput(Finance::FINANCE_SELL_DISHES, sellPrice);
                    this->financeStatistics.AddMoneyInput(Finance::FINANCE_PURCHASE_DISHES, Ingredients::CalculateIngredientsPrice(this->currentIngredients));


                    order newDishOrder(orderDate, dish->GetDishName() ,sellPrice);

                    _customer.ServeDish(dish);
                    _customer.EatDish();

                    cout << "Customer: " << customerName << " ordered Dish: " << newDishOrder.getOrderName() << " [" << newDishOrder.getOrderDate() << "]" << endl;
                    _customer.addToOpenOrders(newDishOrder);
                }

                // Create new drink order
                if (0 <= drinkIndex) {
                    string drinkName;
                    if (0 <= selectedMixIndex){
                        // Create mixed drink
                        DrinkType newMixedDrink = DrinksBar::PrepareDrink((DrinksBar::_DrinkType)drinkIndex , (DrinksBar::_DrinkType) selectedMixIndex);
                        drinkName = newMixedDrink->GetName();
                        newMixedDrink->GetIngredients();
                        sellPrice = Ingredients::CalculateIngredientsSellPrice(newMixedDrink->GetIngredients());
                        price = Ingredients::CalculateIngredientsSellPrice(newMixedDrink->GetIngredients());
                        _customer.ServeDrink(newMixedDrink);
                    } else {
                        // Create simple single Drink

                        DrinkType newDrink = DrinksBar::PrepareDrink((DrinksBar::_DrinkType)drinkIndex);
                        drinkName = newDrink->GetName();
                        _customer.ServeDrink(newDrink);

                        Ingredient localI {Ingredients::GetIngredientByName(drinkName)};
                        sellPrice = localI.GetSellPrice();
                        price = localI.GetPrice();
                    }

                    this->financeStatistics.AddMoneyInput(Finance::FINANCE_SELL_DRINKS, sellPrice);
                    this->financeStatistics.AddMoneyInput(Finance::FINANCE_PURCHASE_DRINKS, price);

                    _customer.DrinkDrink();
                    order newDrinkOrder(orderDate, drinkName , sellPrice);
                    cout << "Customer: " << customerName << " ordered Drink: " << newDrinkOrder.getOrderName() << " [" << newDrinkOrder.getOrderDate() << "]" << endl;
                    _customer.addToOpenOrders(newDrinkOrder);
                }
                break;
            }
        }
    }

    Finance Restaurant::GetRestaurantStatistics() {
        return this->financeStatistics;
    }


}
