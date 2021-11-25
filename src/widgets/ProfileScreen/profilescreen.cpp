#include <widgets/profilescreen.h>
#include <QSpacerItem>
#include <net/auth.h>
#include <models/Course.h>
#include <utils.h>
#include <ApplicationController.h>
#include <widgets/addremoveclass.h>
#include "ui_profilescreen.h"

ProfileScreen::ProfileScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProfileScreen)
{
    ui->setupUi(this);
    connect(AuthController::instance(), &AuthController::authStateChanged, this, &ProfileScreen::onAuthStateChanged);
    connect(ApplicationController::instance(), &ApplicationController::coursesChanged, this, &ProfileScreen::onCoursesChanged);
}

ProfileScreen::~ProfileScreen()
{
    delete ui;
}

void ProfileScreen::onAuthStateChanged(models::User* localUser) {
    if(localUser == nullptr)
        ui->label_2->setText("");
    else
        ui->label_2->setText(localUser->getName());
}

void ProfileScreen::onCoursesChanged(){
    auto layout = (QVBoxLayout*) ui->classes->layout();
    utils::clearLayout(layout);

    auto courses = ApplicationController::instance()->getInstances<models::Course>();
    for(auto [cId, c] : courses){
        auto widget = new QCheckBox(ui->classes);
        widget->setChecked(true);
        widget->setText(c->getCode() + " - " + c->getName());
        layout->addWidget(widget);
    }
    layout->addItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));
}

void ProfileScreen::onAddRemoveButtonPressed() {
    AddRemoveClass *arc = new AddRemoveClass(this);
    arc->show();
}