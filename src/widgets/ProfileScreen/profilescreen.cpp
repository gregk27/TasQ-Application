#include <widgets/profilescreen.h>
#include <QSpacerItem>
#include <net/auth.h>
#include <models/Course.h>
#include <utils.h>
#include <ApplicationController.h>
#include <include/widgets/coursemod/addremoveclass.h>
#include "ui_profilescreen.h"

ProfileScreen::ProfileScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProfileScreen)
{
    ui->setupUi(this);
    connect(AuthController::instance(), &AuthController::authStateChanged, this, &ProfileScreen::onAuthStateChanged);
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