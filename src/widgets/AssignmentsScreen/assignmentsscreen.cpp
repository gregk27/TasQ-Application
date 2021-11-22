#include <widgets/assignmentsscreen.h>
#include "ui_assignmentsscreen.h"

AssignmentsScreen::AssignmentsScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AssignmentsScreen)
{
    ui->setupUi(this);
}

AssignmentsScreen::~AssignmentsScreen()
{
    delete ui;
}
