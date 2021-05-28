//
// Created by Momme Sherif on 27/05/2021.
//

#ifndef MAIN_CPP_QTWIN_H
#define MAIN_CPP_QTWIN_H

#include <QWidget>


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
private slots:
    void on_tabOrder_currentChanged(int index);
    void on_orderButton_clicked();

private:
    Ui::QtWin *ui;
};


#endif //MAIN_CPP_QTWIN_H
