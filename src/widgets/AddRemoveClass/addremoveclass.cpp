//
// Created by Adi Nachmani on 2021-11-20.
//

// You may need to build the project (run Qt uic code generator) to get "ui_AddRemoveClass.h" resolved

#include "../../../include/widgets/addremoveclass.h"
#include "ui_AddRemoveClass.h"


AddRemoveClass::AddRemoveClass(QWidget *parent) :
        QWidget(parent), ui(new Ui::AddRemoveClass) {
    ui->setupUi(this);
}

AddRemoveClass::~AddRemoveClass() {
    delete ui;
}

