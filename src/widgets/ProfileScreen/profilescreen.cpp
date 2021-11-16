#include <widgets/profilescreen.h>
#include "ui_profilescreen.h"

ProfileScreen::ProfileScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProfileScreen)
{
    ui->setupUi(this);
}

ProfileScreen::~ProfileScreen()
{
    delete ui;
}
