//
// Created by Adi Nachmani on 2021-11-20.
//

// You may need to build the project (run Qt uic code generator) to get "ui_AddRemoveClass.h" resolved

#include <include/widgets/coursemod/addremoveclass.h>
#include "ui_AddRemoveClass.h"

#include <models/Course.h>
#include <utils.h>
#include <include/widgets/coursemod/createcoursedialog.h>
#include <widgets/coursemod/editcoursedialog.h>
#include <net/auth.h>
#include <net/schools.h>
#include <net/endpoints.h>
#include <QPushButton>
#include <ApplicationController.h>

AddRemoveClass::AddRemoveClass(QWidget *parent) :
        QWidget(parent), ui(new Ui::AddRemoveClass) {
    ui->setupUi(this);
    setWindowTitle("Add/Remove Classes");

    connect(this, &AddRemoveClass::removeCourse, ApplicationController::instance(), &ApplicationController::unsubscribe);
    connect(this, &AddRemoveClass::addCourse, ApplicationController::instance(), &ApplicationController::subscribe);
    connect(ApplicationController::instance(), &ApplicationController::coursesChanged, this, &AddRemoveClass::coursesChanged);
    connect(AuthController::instance(), &AuthController::authStateChanged, this, &AddRemoveClass::authStateChanged);
}

AddRemoveClass::~AddRemoveClass() {
    delete ui;
}

void AddRemoveClass::populateClasses(std::unordered_map<QString, models::Course*> courses) {
    ui->classList->clearContent();
    for(auto [cId, c] : courses){
        QPushButton *btn;
        ui->classList->addWidget(buildFrameForCourse(c, &btn));
        if(c->getOwnerId() == AuthController::instance()->getLocalUID()){
            btn->setText("Edit");
            connect(btn, &QPushButton::clicked, [&, course=c] {
                auto ecd = new EditCourseDialog(course);
                ecd->show();
            });
        } else {
            btn->setText("Remove");
            // Emit remove c signal when the button is pressed
            connect(btn, &QPushButton::clicked, [&, course=c]  {
                emit removeCourse(course);
            });
        }
    }
}

void AddRemoveClass::showSearchResults(QString search){
    auto local = ApplicationController::instance()->getInstances<Course>();
    ui->search->clearContent();
    auto itr = courses->begin();
    for(; itr != courses->end(); itr++){
        auto c = *itr;
        // Don't show if it's already added locally
        if(local.count(c.getId())) continue;
        // Show if it matches the search criteria
        if(search == "" || c.getCode().toLower().startsWith(search.toLower()) || c.getName().toLower().startsWith(search.toLower())){
            QPushButton *btn;
            ui->search->addWidget(buildFrameForCourse(&c, &btn));
            btn->setText("Subscribe");
            // Emit add course signal when the button is pressed
            connect(btn, &QPushButton::clicked, [&, course=&(*itr)]  {
                emit addCourse(course);
            });
        }
    }
}

QFrame *AddRemoveClass::buildFrameForCourse(Course *c, QPushButton **btn){
    auto *frame = new QFrame();
    frame->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    frame->setFixedHeight(25);
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
    l->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
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
    layout->addWidget(*btn);

    return frame;
}

void AddRemoveClass::coursesChanged() {
    populateClasses(ApplicationController::instance()->getInstances<Course>());
    showSearchResults(ui->searchText->text());
}

void AddRemoveClass::authStateChanged(models::User *u) {
    if(!u) return;
    QString schoolId = u->getSchoolId();
    courses = net::schools::getCourses(schoolId);

    coursesChanged();
}

void AddRemoveClass::showCreateCourse(){
    auto ccd = new CreateCourseDialog();
    ccd->show();
}