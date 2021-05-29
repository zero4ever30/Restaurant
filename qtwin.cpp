//
// Created by Momme Sherif on 27/05/2021.
//

// You may need to build the project (run Qt uic code generator) to get "ui_QtWin.h" resolved

#include <iostream>
#include <string>
#include "qtwin.h"
#include "ui_QtWin.h"
#include "order.hpp"
#include "Restaurant.hpp"
#include "Customer.hpp"

using namespace std;

QtWin::QtWin(QWidget *parent) :
        QWidget(parent), ui(new Ui::QtWin) {
    ui->setupUi(this);

    restaurant.PrintOrderHistoryForAll();
    // All updates must be here too!!!!!!!!
    updateSelectedCustomerComboBox();
    updateOrderTab();
}

QtWin::~QtWin() {
    delete ui;
}

// Update selected tab on selection change event
void QtWin::on_tabOrder_currentChanged(int index)
{
    if (index == TABRESTAURANT) {

    } else if (index == TABORDER) {
        updateOrderTab();
    } else if (index == TABCH) {
        updateCostumerHistoryTab();
    }
}

// OrderTab
void QtWin::on_orderButton_clicked()
{
    std::string selectedCustomer {ui->SelectedCustomerComboBox->currentText().toStdString()};
    std::string selectedDish {ui->dishList->currentItem()->text().toStdString()};
    std::string selectedDrink {ui->drinkList->currentItem()->text().toStdString()};
    int selectedDishIndex {ui->dishList->currentRow()-1};
    int selectedDrinkIndex {ui->drinkList->currentRow()-1};
    restaurant.createNewOrder(selectedCustomer, selectedDish, selectedDrink,selectedDishIndex,selectedDrinkIndex);

    updateOrderTab();
}

//Update the OrderTab
void QtWin::updateOrderTab() {
    // Clear all widgets

    ui->dishList->clear();
    ui->drinkList->clear();

    // Add empty dishes and drinks
    ui->dishList->addItem("No Dish");
    ui->drinkList->addItem("No Drink");

    // Add avaiable drinks and dishes
    for (auto dish : RestLib::Kitchen::availableDishes)
    {
        ui->dishList->addItem(QString::fromStdString(dish));
    }
    for (auto drink : RestLib::DrinksBar::availableDrinks)
    {
        ui->drinkList->addItem(QString::fromStdString(drink));
    }

    // Select each first empty lines
    ui->dishList->setCurrentRow(0);
    ui->drinkList->setCurrentRow(0);


       // cout << "ODERS: " << endl;
       // _customer.printOrders();

    QWidget::update();
}

void QtWin::updateCostumerHistoryTab(){
    // clear all
    ui->CHTable->clear();

    // init
    ui->CHTable->setColumnCount(2);
    for (RestLib::Customer& _customer : restaurant.vCustomers)
    {
        if (ui->SelectedCustomerComboBox->currentText().toStdString()==_customer.getName())
        {
            ui->CHTable->setRowCount(_customer.getNumberOfOrdersFromHistory());
            for (int i{0}; i < ui->CHTable->rowCount(); i++)
            {
                QTableWidgetItem *orderdate;
                QTableWidgetItem *ordername;
                ordername = new QTableWidgetItem;
                orderdate = new QTableWidgetItem;
                orderdate->setText(QString::fromStdString(_customer.getcustomerOrderHistory()[i].getOrderDate()));
                ordername->setText(QString::fromStdString(_customer.getcustomerOrderHistory()[i].getOrderName()));
                ui->CHTable->setItem(i,0,orderdate);
                ui->CHTable->setItem(i,1,ordername);
            }
        }
    }

    //headers
    QStringList hLabels;
    hLabels << "Date" << "Order" ;
    ui->CHTable->setHorizontalHeaderLabels(hLabels);
    ui->CHTable->setAlternatingRowColors(true);


    QWidget::update();
}

void QtWin::updateSelectedCustomerComboBox(){
    ui->SelectedCustomerComboBox->clear();
    // Get active customers and add them
    for (RestLib::Customer& _customer : restaurant.vCustomers) {
        ui->SelectedCustomerComboBox->addItem(QString::fromStdString(_customer.getName()));
    }
}

void QtWin::on_SelectedCustomerComboBox_currentIndexChanged() {
    updateCostumerHistoryTab();
}
