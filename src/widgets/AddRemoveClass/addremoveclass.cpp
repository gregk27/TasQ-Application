//
// Created by Adi Nachmani on 2021-11-20.
//

// You may need to build the project (run Qt uic code generator) to get "ui_AddRemoveClass.h" resolved

#include <widgets/addremoveclass.h>
#include "ui_AddRemoveClass.h"

#include <models/Course.h>
#include <utils.h>
#include <ApplicationController.h>

AddRemoveClass::AddRemoveClass(QWidget *parent) :
        QDialog(parent), ui(new Ui::AddRemoveClass) {
    ui->setupUi(this);
    setWindowTitle("Add/Remove Classes");
    setModal(true);
    coursesChanged();

    connect(ui->addButton, SIGNAL(clicked()), this, SIGNAL(addCourse()));
    connect(this, &AddRemoveClass::removeCourse, ApplicationController::instance(), &ApplicationController::unsubscribe);
    connect(ApplicationController::instance(), &ApplicationController::coursesChanged, this, &AddRemoveClass::coursesChanged);
}

AddRemoveClass::~AddRemoveClass() {
    delete ui;
}

void AddRemoveClass::populateClasses(std::unordered_map<QString, models::Course*> courses) {
    QVBoxLayout *layout;
    if(ui->classes->layout()){
        layout = (QVBoxLayout*) ui->classes->layout();
        utils::clearLayout(layout);
    } else {
        layout = new QVBoxLayout(this);
        ui->classes->setLayout(layout);
    }
    for(auto [cId, course] : courses){
        auto *c = new QFrame();

        auto *l = new QLabel(c);
        l->setText(course->getCode());
        l->setGeometry(QRect(0, 0, 60, 20));

        l = new QLabel(c);
        l->setText(course->getName());
        l->setGeometry(QRect(60, 0, 250, 20));

        auto *btn = new QPushButton(c);
        btn->setText("Remove");
        btn->setGeometry(QRect(300, 0, 80, 20));
        c->setMinimumHeight(20);
        // Emit remove course signal when the button is pressed
        connect(btn, &QPushButton::clicked, [&, course=course]  {
            emit removeCourse(course);
        });

        layout->addWidget(c);
    }

    layout->addItem(new QSpacerItem(1, 1000));
}

void AddRemoveClass::coursesChanged() {
    populateClasses(ApplicationController::instance()->getInstances<Course>());
}