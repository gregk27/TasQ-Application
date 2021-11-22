#include <widgets/schedulescreen.h>
#include "ui_schedulescreen.h"

ScheduleScreen::ScheduleScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScheduleScreen)
{
    ui->setupUi(this);
}

ScheduleScreen::~ScheduleScreen()
{
    delete ui;
}
