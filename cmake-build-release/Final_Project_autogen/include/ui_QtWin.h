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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtWin
{
public:
    QTabWidget *tabOrder;
    QWidget *TabOrder;
    QWidget *TabCH;
    QTableWidget *tableWidget;
    QComboBox *comboBox;
    QPushButton *pushButton_close;
    QPushButton *pushButton_save;

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
        TabOrder = new QWidget();
        TabOrder->setObjectName(QString::fromUtf8("TabOrder"));
        tabOrder->addTab(TabOrder, QString());
        TabCH = new QWidget();
        TabCH->setObjectName(QString::fromUtf8("TabCH"));
        tableWidget = new QTableWidget(TabCH);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 80, 331, 241));
        comboBox = new QComboBox(TabCH);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(400, 80, 72, 22));
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
        tabOrder->setTabText(tabOrder->indexOf(TabOrder), QCoreApplication::translate("QtWin", "Order", nullptr));
        tabOrder->setTabText(tabOrder->indexOf(TabCH), QCoreApplication::translate("QtWin", "Customer History", nullptr));
        pushButton_close->setText(QCoreApplication::translate("QtWin", "Close", nullptr));
        pushButton_save->setText(QCoreApplication::translate("QtWin", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtWin: public Ui_QtWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTWIN_H
