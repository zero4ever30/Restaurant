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
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtWin
{
public:
    QTabWidget *tabOrder;
    QWidget *TabCH;
    QWidget *TabOrder;

    void setupUi(QWidget *QtWin)
    {
        if (QtWin->objectName().isEmpty())
            QtWin->setObjectName(QString::fromUtf8("QtWin"));
        QtWin->resize(897, 570);
        tabOrder = new QTabWidget(QtWin);
        tabOrder->setObjectName(QString::fromUtf8("tabOrder"));
        tabOrder->setGeometry(QRect(0, 0, 901, 571));
        TabCH = new QWidget();
        TabCH->setObjectName(QString::fromUtf8("TabCH"));
        tabOrder->addTab(TabCH, QString());
        TabOrder = new QWidget();
        TabOrder->setObjectName(QString::fromUtf8("TabOrder"));
        tabOrder->addTab(TabOrder, QString());

        retranslateUi(QtWin);

        tabOrder->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(QtWin);
    } // setupUi

    void retranslateUi(QWidget *QtWin)
    {
        QtWin->setWindowTitle(QCoreApplication::translate("QtWin", "QtWin", nullptr));
#if QT_CONFIG(tooltip)
        tabOrder->setToolTip(QCoreApplication::translate("QtWin", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tabOrder->setTabText(tabOrder->indexOf(TabCH), QCoreApplication::translate("QtWin", "Tab 1", nullptr));
        tabOrder->setTabText(tabOrder->indexOf(TabOrder), QCoreApplication::translate("QtWin", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtWin: public Ui_QtWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTWIN_H
