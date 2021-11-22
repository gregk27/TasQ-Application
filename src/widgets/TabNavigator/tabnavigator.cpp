#include <widgets/tabnavigator.h>
#include "ui_tabnavigator.h"

TabNavigator::TabNavigator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TabNavigator)
{
    ui->setupUi(this);
}

TabNavigator::~TabNavigator()
{
    delete ui;
}
