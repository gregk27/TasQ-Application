#include <widgets/schedulelistview.h>
#include "ui_schedulelistview.h"

ScheduleListView::ScheduleListView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScheduleListView)
{
    ui->setupUi(this);
}

ScheduleListView::~ScheduleListView()
{
    delete ui;
}
