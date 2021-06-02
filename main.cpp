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
#include <QApplication>
#include <QPushButton>
#include "ui_QtWin.h"
#include "qtwin.h"



using namespace std;
using namespace RestLib;

int main(int argc , char *argv[]) {


    //std::system("cls");

    QApplication b(argc, argv);
    QtWin Win1;
    Win1.show();
    return QApplication::exec();


    return 0;
}
