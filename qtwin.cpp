/*
 PIC - Labor Versuch 3
 Created by Mohamed Mahmoud 930154 and Tobias Fricke 932874
 Last Edit: 01/06/2021
*/

// You may need to build the project (run Qt uic code generator) to get "ui_QtWin.h" resolved

#include <iostream>
#include <string>
#include <QMessageBox>
#include "qtwin.h"
#include "ui_QtWin.h"
#include "Restaurant.hpp"
#include "Customer.hpp"
#include <vector>
#include "Ingredients.hpp"

using namespace std;
using namespace RestLib;

QtWin::QtWin(QWidget *parent) :
        QWidget(parent), ui(new Ui::QtWin) {
    ui->setupUi(this);

    //restaurant.PrintOrderHistoryForAll();
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

//SaveButton
void QtWin::on_pushButton_save_clicked() {
    restaurant.SaveHistory();
}
void QtWin::updateDueAmount(){

    for (Customer& _customer : restaurant.vCustomers)
    {
        if (ui->SelectedCustomerComboBox->currentText().toStdString()==_customer.getName())
        {

            ui->amountdueText->setText("Amount Due: " + QString::number(_customer.getDueAmount(), 'f', 2));

        }
    }

}

// OrderTab
void QtWin::on_orderButton_clicked()
{
    if (ui->SelectedCustomerComboBox->currentIndex() != -1){
        if (ui->dishList->currentRow() == 0 && ui->drinkList->currentRow()== 0)
            QMessageBox::warning(this , "Warning!!" , "No dish or drink has been chosen!\nNo order has been made!");
        else {
            string selectedCustomer{ui->SelectedCustomerComboBox->currentText().toStdString()};

            int selectedDishIndex{ui->dishList->currentRow() - 1};
            int selectedDrinkIndex{ui->drinkList->currentRow() - 1};
            int selectedMixIndex{ui->mixDrinksList->currentRow() - 1};

            cout << "selectedDishIndex: " << selectedDishIndex << endl;
            cout << "selectedDrinkIndex: " << selectedDrinkIndex << endl;
            cout << "selectedMixIndex: " << selectedMixIndex << endl;

            restaurant.createNewOrder(selectedCustomer, selectedDishIndex, selectedDrinkIndex, selectedMixIndex);
            updateOrderTab();
            updateDueAmount();
        }
    }
    else{
        QMessageBox::critical(this , "Error!!" , "The customer must be selected before hand");
    }


}

//Update the OrderTab
void QtWin::updateOrderTab() {
    // Clear all widgets
    ui->dishList->clear();
    ui->drinkList->clear();
    ui->ingredientsList -> clear();
    ui->mixDrinksList->clear();

    // Add empty dishes and drinks
    ui->dishList->addItem("No Dish");
    ui->drinkList->addItem("No Drink");
    ui->mixDrinksList->addItem("Don't mix");

    // Add avaiable drinks and dishes
    for (const auto& dish : Kitchen::availableDishes)
    {
        ui->dishList->addItem(QString::fromStdString(dish));
    }
    for (const auto& drink : DrinksBar::availableDrinks)
    {
        Ingredient localI = Ingredients::GetIngredientByName(drink);

        ostringstream stringStream;
        if (localI.GetName() == drink) {
            stringStream << drink << ": " << localI.GetSellPrice() << " €";
        } else {
            stringStream << drink << ": ?? €";
        }

        ui->drinkList->addItem(QString::fromStdString(stringStream.str()));
    }
    for (const auto& drink : DrinksBar::availableDrinks)
    {
        Ingredient localI = Ingredients::GetIngredientByName(drink);

        ostringstream stringStream;
        if (localI.GetName() == drink) {
            stringStream << drink << ": " << localI.GetSellPrice() << " €";
        } else {
            stringStream << drink << ": ?? €";
        }
        ui->mixDrinksList->addItem(QString::fromStdString(stringStream.str()));
    }

    // Select each first empty lines
    ui->dishList->setCurrentRow(0);
    ui->drinkList->setCurrentRow(0);
    ui->mixDrinksList->setCurrentRow(0);

    QWidget::update();
}

void QtWin::updateCostumerHistoryTab(){
    // clear all
    ui->CHTable->clear();

    // init
    ui->CHTable->setColumnCount(2);
    for (Customer& _customer : restaurant.vCustomers)
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
    for (Customer& _customer : restaurant.vCustomers) {
        ui->SelectedCustomerComboBox->addItem(QString::fromStdString(_customer.getName()));
    }
}

void QtWin::on_SelectedCustomerComboBox_currentIndexChanged() {
    updateCostumerHistoryTab();
    updateDueAmount();
}

// operator overloading
std::string & operator - (std::string & os, const std::string& s0)
{
    try {
        std::size_t index {os.find(s0)};
        os.erase(index , s0.size());
    }catch (...){}

    return os;
}

std::string & operator * (std::string & os, const std::string& s0)
{
        try {
            std::size_t index {os.find(s0)};
            os.erase(index , os.size());
        }catch (...){}



    return os;
}


void QtWin::on_dishList_clicked(){

    // Clear vector and widget
    ui->ingredientsList->clear();
    restaurant.currentIngredients.clear();
    ui->addIngredientcomboBox->clear();
    ui->addIngredientcomboBox->addItem("No Extras");

    // get ingredients

    if(ui->dishList->currentRow()!=0){
        ui->ingredientsList->addItem("Default");

        for (const auto& ingredientName : Kitchen::Recipes[ui->dishList->currentRow()-1])
        {
            Ingredient localI = Ingredients::GetIngredientByName(ingredientName);

            ostringstream stringStream;
            if (localI.IsModifieable()) {
                stringStream << "+/- ";
            } else {
                stringStream << "    ";
            }
            if (localI.GetName() == ingredientName) {
                stringStream << ingredientName << ": " << localI.GetSellPrice() << " €";
                if(localI.IsModifieable())
                {
                    string s1 = stringStream.str();
                    ui->addIngredientcomboBox->addItem(QString::fromStdString((s1 - "+/- ")));
                }
            } else {
                stringStream << ingredientName << ": ?? €";
            }
            ui->ingredientsList->addItem(QString::fromStdString(stringStream.str()));
            restaurant.currentIngredients.push_back(localI);
        }
        updateCurrentDishFullPrice();
    }

}

void QtWin::updateCurrentDishFullPrice() {
    ui->ingredientsList->takeItem(ui->ingredientsList->count());
    ostringstream stringStream;
    stringStream << "\t\tPrice: " << Ingredients::CalculateIngredientsSellPrice(restaurant.currentIngredients) << " €";
    ui->ingredientsList->addItem(QString::fromStdString(stringStream.str()));
}

void QtWin::on_ingredientsList_clicked(){

    if (ui->ingredientsList->currentRow() == 0){
        on_dishList_clicked();
    } else {
        string name = ui->ingredientsList->currentItem()->text().toStdString();

        if (name.find("+/-") != -1) {
            restaurant.currentIngredients.erase(restaurant.currentIngredients.begin() + (ui->ingredientsList->currentRow()-1));
            ui->ingredientsList->takeItem(ui->ingredientsList->currentRow());
            ui->ingredientsList->takeItem(ui->ingredientsList->count()-1); // delete the price
            restaurant.currentIngredients.shrink_to_fit();
            updateIngterientsList();
        }
    }
}



void QtWin::on_lastNameText_returnPressed() {
    QMessageBox msgBox(QMessageBox::Warning , "Warning!" , "");
    msgBox.setText("Are you sure you want to add a new customer?");
    msgBox.setInformativeText("Please double check the given data.");
    QPushButton *connectButton = msgBox.addButton(tr("Add"), QMessageBox::YesRole);
    QPushButton *abortButton = msgBox.addButton(QMessageBox::Abort);

    msgBox.exec();

    if (msgBox.clickedButton() == connectButton) {

        restaurant.AddToCustomers(Customer(
                ui->firstNameText->text().toStdString(),
                ui->lastNameText->text().toStdString()));
        ui->firstNameText->clear();
        ui->lastNameText->clear();
        updateSelectedCustomerComboBox();
        ui->SelectedCustomerComboBox->setCurrentIndex(ui->SelectedCustomerComboBox->count()-1);
    } else if (msgBox.clickedButton() == abortButton) {
        // abort
    }


}

void QtWin::on_deleteCustomerButton_clicked() {

    QMessageBox msgBox(QMessageBox::Warning , "Warning!" , "");
    msgBox.setText("Are you sure you want to remove the following customer?");
    msgBox.setInformativeText("<FONT COLOR='#ff0000'>" + ui->SelectedCustomerComboBox->currentText() + "</FONT>");
    QPushButton *delete_customer_yes = msgBox.addButton(tr("REMOVE"), QMessageBox::YesRole);
    QPushButton *abortButton = msgBox.addButton(QMessageBox::Abort);

    msgBox.exec();

    if (msgBox.clickedButton() == delete_customer_yes) {
        for (int i {0}; i<restaurant.vCustomers.size(); i++)
        {
            if (restaurant.vCustomers[i].getName() == ui->SelectedCustomerComboBox->currentText().toStdString())
            {
                restaurant.vCustomers.erase(restaurant.vCustomers.begin() + i);
            }
        }
        updateSelectedCustomerComboBox();
    } else if (msgBox.clickedButton() == abortButton) {
        // abort
    }

}

void QtWin::on_payButton_clicked() {
    for (Customer& _customer : restaurant.vCustomers)
    {
        if (ui->SelectedCustomerComboBox->currentText().toStdString()==_customer.getName())
        {
            if (_customer.getDueAmount() != 0)
           _customer.Pay();
        }
    }
    updateDueAmount();
}

void QtWin::updateIngterientsList() {



    // Clear vector and widget
    ui->ingredientsList->clear();

    // get ingredients

    if(ui->dishList->currentRow()!=0){
        ui->ingredientsList->addItem("Default");

        for (const Ingredient& ingredient : restaurant.currentIngredients)
        {


            ostringstream stringStream;
            if (ingredient.IsModifieable()) {
                stringStream << "+/- ";
            } else {
                stringStream << "    ";
            }
            stringStream << ingredient.GetName() << ": " << ingredient.GetSellPrice() << " €";
            ui->ingredientsList->addItem(QString::fromStdString(stringStream.str()));
        }
        updateCurrentDishFullPrice();
    }

}

void QtWin::on_addIngredientcomboBox_activated() {

    if (ui->addIngredientcomboBox->currentIndex() != 0)
    {
        ui->ingredientsList->addItem("+/- " + ui->addIngredientcomboBox->currentText());
        string buff = ui->addIngredientcomboBox->currentText().toStdString();
        string currentIngredient = buff * ":";
        Ingredient localI = Ingredients::GetIngredientByName(currentIngredient);
        cout << localI.GetName() << localI.GetSellPrice() ;
        restaurant.currentIngredients.push_back(localI);

        updateIngterientsList();
    }


}
