//
// Created by Momme Sherif on 27/05/2021.
//

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

    void updateOrderTab();
    void updateCostumerHistoryTab();

    void updateCurrentDishFullPrice();

private slots:
    void on_tabOrder_currentChanged(int index);
    void on_orderButton_clicked();
    void on_pushButton_save_clicked();
    void on_SelectedCustomerComboBox_currentIndexChanged();
    void on_dishList_clicked();
    void on_ingredientsList_clicked();
    void on_addIngredientText_returnPressed();
    void on_lastNameText_returnPressed();
    void on_deleteCustomerButton_clicked();

private:
    Ui::QtWin *ui;
    RestLib::Restaurant restaurant{"Hello world" , "Database.txt"};


    void updateSelectedCustomerComboBox();



};


#endif //MAIN_CPP_QTWIN_H
