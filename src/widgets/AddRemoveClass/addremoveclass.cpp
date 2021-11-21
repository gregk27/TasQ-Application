//
// Created by Adi Nachmani on 2021-11-20.
//

// You may need to build the project (run Qt uic code generator) to get "ui_AddRemoveClass.h" resolved

#include "../../../include/widgets/addremoveclass.h"
#include "ui_AddRemoveClass.h"

#include <models/Course.h>

AddRemoveClass::AddRemoveClass(std::vector<models::Course> *courses, QWidget *parent) :
        QDialog(parent), ui(new Ui::AddRemoveClass) {
    ui->setupUi(this);
    populateClasses(courses);
}

AddRemoveClass::~AddRemoveClass() {
    delete ui;
}

void AddRemoveClass::populateClasses(std::vector<models::Course> *courses) {
    QVBoxLayout *layout;
    if(ui->classes->layout()){
        layout = (QVBoxLayout*) ui->classes->layout();
        QLayoutItem *child;
        while ((child = layout->takeAt(0)) != 0) {
            delete child;
        }
    } else {
        layout = new QVBoxLayout(this);
        ui->classes->setLayout(layout);
    }
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
}

void AddRemoveClass::coursesChanged(std::vector<models::Course> *courses) {
    populateClasses(courses);
}