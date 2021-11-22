#include <widgets/scheduleweekview.h>
#include "ui_scheduleweekview.h"

ScheduleWeekView::ScheduleWeekView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScheduleWeekView)
{
    ui->setupUi(this);
}

ScheduleWeekView::~ScheduleWeekView()
{
    delete ui;
}
