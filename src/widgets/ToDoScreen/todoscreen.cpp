#include <widgets/todoscreen.h>
#include "ui_todoscreen.h"

ToDoScreen::ToDoScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ToDoScreen)
{
    ui->setupUi(this);
}

ToDoScreen::~ToDoScreen()
{
    delete ui;
}
