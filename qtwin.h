/*
 PIC - Labor Versuch 3
 Created by Mohamed Mahmoud 930154 and Tobias Fricke 932874
 Last Edit: 01/06/2021
*/

#ifndef MAIN_CPP_QTWIN_H
#define MAIN_CPP_QTWIN_H

#include <QWidget>
#include "Restaurant.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class QtWin; }
QT_END_NAMESPACE

class QtWin : public QWidget {
Q_OBJECT

public:
    explicit QtWin(QWidget *parent = nullptr);

    ~QtWin() override;

    enum tabNames {
        TABRESTAURANT,
        TABORDER,
        TABCH
    };



private slots:
    void on_tabOrder_currentChanged(int index);
    void on_orderButton_clicked();
    void on_pushButton_save_clicked();
    void on_SelectedCustomerComboBox_currentIndexChanged();
    void on_dishList_clicked();
    void on_ingredientsList_clicked();
    void on_lastNameText_returnPressed();
    void on_deleteCustomerButton_clicked();
    void on_payButton_clicked();
    void on_addIngredientcomboBox_activated();
    void updateRestaurantTable();

private:
    Ui::QtWin *ui;
    RestLib::Restaurant restaurant{"Hello world" , "Max Mustermann", "Database.txt"};

    void updateOrderTab();
    void updateCostumerHistoryTab();
    void updateCurrentDishFullPrice();
    void updateDueAmount();
    void updateSelectedCustomerComboBox();
    void updateIngterientsList();


};


#endif //MAIN_CPP_QTWIN_H
