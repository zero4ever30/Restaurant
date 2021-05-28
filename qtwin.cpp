//
// Created by Momme Sherif on 27/05/2021.
//

// You may need to build the project (run Qt uic code generator) to get "ui_QtWin.h" resolved

#include <iostream>
#include <string>
#include "qtwin.h"
#include "ui_QtWin.h"
#include "order.hpp"

using namespace std;

QtWin::QtWin(QWidget *parent) :
        QWidget(parent), ui(new Ui::QtWin) {
    ui->setupUi(this);
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

    }
}

// OrderTab
void QtWin::on_orderButton_clicked()
{
    std::string selectedCustomer {ui->customerComboBox->currentText().toStdString()};
    std::string selectedDish {ui->dishList->currentItem()->text().toStdString()};
    std::string selectedDrink {ui->drinkList->currentItem()->text().toStdString()};

    RestLib::order::createNewOrder(selectedCustomer, selectedDish, selectedDrink);

    updateOrderTab();
}

//Update the OrderTab
void QtWin::updateOrderTab() {
    // Clear all widgets
    ui->customerComboBox->clear();
    ui->dishList->clear();
    ui->drinkList->clear();

    // Add empty dishes and drinks
    ui->dishList->addItem("No Dish");
    ui->drinkList->addItem("No Drink");

    // Add avaiable drinks and dishes
    for(int i=1; i<6; i++) {
        ui->dishList->addItem("Dish" + QString::number(i));
        ui->drinkList->addItem("Drink" + QString::number(i));
    }

    // Select each first empty lines
    ui->dishList->setCurrentRow(0);
    ui->drinkList->setCurrentRow(0);

    // Get active customers and add them
    ui->customerComboBox->addItem("Max Mustermann");
    ui->customerComboBox->addItem("Sabine Mustermann");

    QWidget::update();
}
