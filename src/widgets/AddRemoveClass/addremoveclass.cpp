//
// Created by Adi Nachmani on 2021-11-20.
//

// You may need to build the project (run Qt uic code generator) to get "ui_AddRemoveClass.h" resolved

#include "../../../include/widgets/addremoveclass.h"
#include "ui_AddRemoveClass.h"

#include <models/Course.h>

AddRemoveClass::AddRemoveClass(QWidget *parent) :
        QDialog(parent), ui(new Ui::AddRemoveClass) {
    ui->setupUi(this);

}

AddRemoveClass::~AddRemoveClass() {
    delete ui;
}

void AddRemoveClass::populateClasses(std::vector<models::Course> *courses) {
    auto layout = new QVBoxLayout(this);

    for(auto course : *courses){
        auto *c = new QFrame();

        auto *l = new QLabel(c);
        l->setText(course.getCode());
        l->setGeometry(QRect(0, 0, 60, 20));

        l = new QLabel(c);
        l->setText(course.getName());
        l->setGeometry(QRect(60, 0, 250, 20));

        auto *btn = new QPushButton(c);
        btn->setText("Remove");
        btn->setGeometry(QRect(300, 0, 80, 20));
        c->setMinimumHeight(20);

        layout->addWidget(c);
    }

    layout->addItem(new QSpacerItem(1, 1000));
    ui->classes->setLayout(layout);
}

