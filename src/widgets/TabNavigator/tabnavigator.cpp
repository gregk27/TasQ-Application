#include <widgets/tabnavigator.h>
#include "ui_tabnavigator.h"

TabNavigator::TabNavigator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TabNavigator)
{
    ui->setupUi(this);
    ui->date->setText(QDate::currentDate().toString());
}

TabNavigator::~TabNavigator()
{
    delete ui;
}
