/********************************************************************************
** Form generated from reading UI file 'qtwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTWINDOW_H
#define UI_QTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>

QT_BEGIN_NAMESPACE

class Ui_QtWindow
{
public:

    void setupUi(QMainWindow *QtWindow)
    {
        if (QtWindow->objectName().isEmpty())
            QtWindow->setObjectName(QString::fromUtf8("QtWindow"));
        QtWindow->resize(400, 300);

        retranslateUi(QtWindow);

        QMetaObject::connectSlotsByName(QtWindow);
    } // setupUi

    void retranslateUi(QMainWindow *QtWindow)
    {
        QtWindow->setWindowTitle(QCoreApplication::translate("QtWindow", "QtWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtWindow: public Ui_QtWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTWINDOW_H
