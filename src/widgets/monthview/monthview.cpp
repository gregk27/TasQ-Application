#include <widgets/monthview.h>
#include <utils.h>
#include "ui_monthview.h"

MonthView::MonthView(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::MonthView)
{
    ui->setupUi(this);

    // Create a single month calendar
    cal = new MonthCalendar(QDate::currentDate().month());

    /*
    *  Example for adding assignments
    *  Will change when connected to database
    */
    QDate* duedate = new QDate(2021, 11, 21);
    QTime* duetime = new QTime(19, 0, 0, 0);
    QDateTime* due = new QDateTime;
    due->setDate(*duedate);
    due->setTime(*duetime);
    cal->AddTAssign("ABCD 123", "Assignment 1", "Assignment", due, "pink");

    QVBoxLayout* lay = new QVBoxLayout;
    lay->addWidget(cal);
    setLayout(lay);
}

MonthView::~MonthView()
{
    delete ui;
}
