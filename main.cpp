/*
 PIC - Labor Versuch 3
 Created by Mohamed Mahmoud 930154 and Tobias Fricke 932874
 Last Edit: 19/05/2021
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include "Customer.hpp"
#include "Kitchen.hpp"
#include "Restaurant.hpp"
#include <cstdlib>
#include "GUI.hpp"

using namespace std;
using namespace RestLib;

int main() {

    Restaurant a ("Hello world" , "Database.txt");

    a.AddToCustomers(Customer("dhsajkda","asghdjkasd"));

    a.PrintOrderHistoryForAll();
    //std::system("cls");

    MainMenu();

    return 0;
}
