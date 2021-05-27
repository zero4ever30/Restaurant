//
// Created by Momme Sherif on 27/05/2021.
//

// You may need to build the project (run Qt uic code generator) to get "ui_QtWin.h" resolved

#include "qtwin.h"
#include "ui_QtWin.h"


QtWin::QtWin(QWidget *parent) :
        QWidget(parent), ui(new Ui::QtWin) {
    ui->setupUi(this);
}

QtWin::~QtWin() {
    delete ui;
}

