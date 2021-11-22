#include <widgets/schedulefilter.h>
#include "ui_schedulefilter.h"

ScheduleFilter::ScheduleFilter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScheduleFilter)
{
    ui->setupUi(this);
}

ScheduleFilter::~ScheduleFilter()
{
    delete ui;
}
