//
// Created by Adi Nachmani on 2021-11-20.
//

// You may need to build the project (run Qt uic code generator) to get "ui_AddRemoveClass.h" resolved

#include <widgets/addremoveclass.h>
#include "ui_AddRemoveClass.h"

#include <models/Course.h>
#include <utils.h>
#include <net/auth.h>
#include <net/schools.h>
#include <net/endpoints.h>
#include <QPushButton>
#include <ApplicationController.h>

AddRemoveClass::AddRemoveClass(QWidget *parent) :
        QDialog(parent), ui(new Ui::AddRemoveClass) {
    ui->setupUi(this);
    setWindowTitle("Add/Remove Classes");
    setModal(true);
    coursesChanged();

    QString schoolId = AuthController::instance()->getLocalUser()->getSchoolId();
    courses = net::schools::getCourses(schoolId);

//    connect(ui->addButton, SIGNAL(clicked()), this, SIGNAL(addCourse()));
    connect(this, &AddRemoveClass::removeCourse, ApplicationController::instance(), &ApplicationController::unsubscribe);
    connect(ApplicationController::instance(), &ApplicationController::coursesChanged, this, &AddRemoveClass::coursesChanged);
    showSearchResults("");
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
    for(auto [cId, c] : courses){
        QPushButton *btn;
        layout->addWidget(buildFrameForCourse(c, &btn));
        btn->setText("Remove");
        // Emit remove c signal when the button is pressed
        connect(btn, &QPushButton::clicked, [&, course=c]  {
            emit removeCourse(course);
        });
    }

    layout->addItem(new QSpacerItem(1, 1000));
}

void AddRemoveClass::showSearchResults(QString search){
    utils::clearLayout(ui->searchResults->layout());
    for(auto c : *courses){
        if(search == "" || c.getCode().toLower().startsWith(search.toLower()) || c.getName().toLower().startsWith(search.toLower())){
            // TODO: Hide if already subscribed
            QPushButton *btn;
            ui->searchResults->layout()->addWidget(buildFrameForCourse(&c, &btn));
            btn->setText("Subscribe");
        }
    }
    ui->searchResults->layout()->addItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));
}

QFrame *AddRemoveClass::buildFrameForCourse(Course *c, QPushButton **btn){
    auto *frame = new QFrame();
    auto layout = new QHBoxLayout();
    frame->setLayout(layout);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(25);

    auto *l = new QLabel(frame);
    l->setText(c->getCode());
    l->setFixedWidth(60);
    l->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    layout->addWidget(l);

    l = new QLabel(frame);
    l->setText(c->getName());
    layout->addWidget(l);
    l->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    l = new QLabel(frame);
    l->setText(c->getTerm().toString() + " " + QString::number(c->getYear()));
    layout->addWidget(l);
    l->setFixedWidth(70);
    l->setAlignment(Qt::AlignmentFlag::AlignRight);
    l->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);

    l = new QLabel(frame);
    // Todo optimize?
    auto oId = c->getOwnerId();
    l->setText(net::getUser(oId)->getName());
    layout->addWidget(l);
    l->setFixedWidth(100);
    l->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);

    *btn = new QPushButton(frame);
    (*btn)->setText("BUTTON");
    (*btn)->setGeometry(QRect(300, 0, 80, 20));
    frame->setMinimumHeight(20);
    layout->addWidget(*btn);

    return frame;
}

void AddRemoveClass::coursesChanged() {
    populateClasses(ApplicationController::instance()->getInstances<Course>());
}