/********************************************************************************
** Form generated from reading UI file 'qtwin.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTWIN_H
#define UI_QTWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtWin
{
public:
    QTabWidget *tabOrder;
    QWidget *TabRest;
    QPushButton *RefillButton;
    QWidget *TabOrder;
    QListWidget *dishList;
    QListWidget *drinkList;
    QPushButton *orderButton;
    QLabel *drinkLabel;
    QLabel *dishLabel;
    QWidget *TabCH;
    QTableWidget *CHTable;
    QPushButton *pushButton_close;
    QPushButton *pushButton_save;
    QComboBox *SelectedCustomerComboBox;

    void setupUi(QWidget *QtWin)
    {
        if (QtWin->objectName().isEmpty())
            QtWin->setObjectName(QString::fromUtf8("QtWin"));
        QtWin->resize(1154, 778);
        tabOrder = new QTabWidget(QtWin);
        tabOrder->setObjectName(QString::fromUtf8("tabOrder"));
        tabOrder->setGeometry(QRect(0, 390, 901, 391));
        tabOrder->setToolTipDuration(-10);
        tabOrder->setLayoutDirection(Qt::LeftToRight);
        tabOrder->setElideMode(Qt::ElideMiddle);
        TabRest = new QWidget();
        TabRest->setObjectName(QString::fromUtf8("TabRest"));
        RefillButton = new QPushButton(TabRest);
        RefillButton->setObjectName(QString::fromUtf8("RefillButton"));
        RefillButton->setGeometry(QRect(100, 250, 80, 21));
        tabOrder->addTab(TabRest, QString());
        TabOrder = new QWidget();
        TabOrder->setObjectName(QString::fromUtf8("TabOrder"));
        dishList = new QListWidget(TabOrder);
        dishList->setObjectName(QString::fromUtf8("dishList"));
        dishList->setGeometry(QRect(10, 130, 256, 192));
        drinkList = new QListWidget(TabOrder);
        drinkList->setObjectName(QString::fromUtf8("drinkList"));
        drinkList->setGeometry(QRect(290, 130, 256, 192));
        orderButton = new QPushButton(TabOrder);
        orderButton->setObjectName(QString::fromUtf8("orderButton"));
        orderButton->setGeometry(QRect(240, 330, 80, 21));
        drinkLabel = new QLabel(TabOrder);
        drinkLabel->setObjectName(QString::fromUtf8("drinkLabel"));
        drinkLabel->setGeometry(QRect(290, 110, 47, 13));
        dishLabel = new QLabel(TabOrder);
        dishLabel->setObjectName(QString::fromUtf8("dishLabel"));
        dishLabel->setGeometry(QRect(10, 110, 47, 13));
        tabOrder->addTab(TabOrder, QString());
        TabCH = new QWidget();
        TabCH->setObjectName(QString::fromUtf8("TabCH"));
        CHTable = new QTableWidget(TabCH);
        CHTable->setObjectName(QString::fromUtf8("CHTable"));
        CHTable->setGeometry(QRect(10, 80, 331, 241));
        tabOrder->addTab(TabCH, QString());
        pushButton_close = new QPushButton(QtWin);
        pushButton_close->setObjectName(QString::fromUtf8("pushButton_close"));
        pushButton_close->setGeometry(QRect(1050, 740, 80, 21));
        pushButton_close->setContextMenuPolicy(Qt::NoContextMenu);
        pushButton_close->setToolTipDuration(-4);
        pushButton_save = new QPushButton(QtWin);
        pushButton_save->setObjectName(QString::fromUtf8("pushButton_save"));
        pushButton_save->setGeometry(QRect(950, 740, 80, 21));
        pushButton_save->setToolTipDuration(0);
        SelectedCustomerComboBox = new QComboBox(QtWin);
        SelectedCustomerComboBox->setObjectName(QString::fromUtf8("SelectedCustomerComboBox"));
        SelectedCustomerComboBox->setGeometry(QRect(10, 340, 561, 22));

        retranslateUi(QtWin);
        QObject::connect(pushButton_close, &QPushButton::clicked, QtWin, qOverload<>(&QWidget::close));

        tabOrder->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(QtWin);
    } // setupUi

    void retranslateUi(QWidget *QtWin)
    {
        QtWin->setWindowTitle(QCoreApplication::translate("QtWin", "QtWin", nullptr));
#if QT_CONFIG(tooltip)
        tabOrder->setToolTip(QCoreApplication::translate("QtWin", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        RefillButton->setText(QCoreApplication::translate("QtWin", "Refill Button", nullptr));
        tabOrder->setTabText(tabOrder->indexOf(TabRest), QCoreApplication::translate("QtWin", "Restaurant", nullptr));
        orderButton->setText(QCoreApplication::translate("QtWin", "Order", nullptr));
        drinkLabel->setText(QCoreApplication::translate("QtWin", "Drinks", nullptr));
        dishLabel->setText(QCoreApplication::translate("QtWin", "Dishes", nullptr));
        tabOrder->setTabText(tabOrder->indexOf(TabOrder), QCoreApplication::translate("QtWin", "Order", nullptr));
        tabOrder->setTabText(tabOrder->indexOf(TabCH), QCoreApplication::translate("QtWin", "Customer History", nullptr));
        pushButton_close->setText(QCoreApplication::translate("QtWin", "Close", nullptr));
        pushButton_save->setText(QCoreApplication::translate("QtWin", "Save", nullptr));
        SelectedCustomerComboBox->setPlaceholderText(QCoreApplication::translate("QtWin", "Select a customer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtWin: public Ui_QtWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTWIN_H
