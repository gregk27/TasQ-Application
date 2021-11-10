#include "termview.h"
#include "ui_termview.h"

TermView::TermView(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::TermView)
{
    ui->setupUi(this);

    QDate* date = new QDate;
    date->setDate(QDate::currentDate().year(), QDate::currentDate().month(), 1);
    int mon1, mon2, mon3, mon4 = 0;


    // Determining the current term
    if (date->month() <= 4) {
        mon1 = 1;
        mon2 = 2;
        mon3 = 3;
        mon4 = 4;
    }
    else if (date->month() <= 8) {
        mon1 = 5;
        mon2 = 6;
        mon3 = 7;
        mon4 = 8;
    }
    else {
        mon1 = 9;
        mon2 = 10;
        mon3 = 11;
        mon4 = 12;
    }


    //Creating four calendars, one for each month in the term

    QDate* date1 = new QDate;
    date1->setDate(QDate::currentDate().year(), mon1, 1);
    MonthCalendar* month1 = new MonthCalendar(date1->month());

    QDate* date2 = new QDate;
    date2->setDate(QDate::currentDate().year(), mon2, 1);
    MonthCalendar* month2 = new MonthCalendar(date2->month());

    QDate* date3 = new QDate;
    date3->setDate(QDate::currentDate().year(), mon3, 1);
    MonthCalendar* month3 = new MonthCalendar(date3->month());

    QDate* date4 = new QDate;
    date4->setDate(QDate::currentDate().year(), mon4, 1);
    MonthCalendar* month4 = new MonthCalendar(date4->month());

    QGridLayout* termlay = new QGridLayout;

    termlay->addWidget(month1, 0, 0);
    termlay->addWidget(month2, 0, 1);
    termlay->addWidget(month3, 1, 0);
    termlay->addWidget(month4, 1, 1);


    /*
    *  Example for adding assignments
    *  Will change when connected to database
    */

    QDateTime* due[2];

    QDate* duedate = new QDate(2021, 12, 21);
    QTime* duetime = new QTime(19, 0, 0, 0);
    due[0] = new QDateTime;
    due[0]->setDate(*duedate);
    due[0]->setTime(*duetime);
    delete(duedate);
    delete(duetime);

    QDate* duedate2 = new QDate(2021, 11, 11);
    QTime* duetime2 = new QTime(23, 59, 0, 0);
    due[1] = new QDateTime;
    due[1]->setDate(*duedate2);
    due[1]->setTime(*duetime2);
    delete(duedate2);
    delete(duetime2);

    int length = sizeof(due) / sizeof(due[0]);

    for (int i = 0; i < length; i++) {

        if (due[i]->date().month() % 4 == 1) {
            month1->AddTAssign("ABCD 123", "Assignment 1", "Assignment", due[i], "pink");
        }
        else if (due[i]->date().month() % 4 == 2) {
            month2->AddTAssign("ABCD 123", "Assignment 1", "Assignment", due[i], "pink");
        }
        else if (due[i]->date().month() % 4 == 3) {
            month3->AddTAssign("ABCD 123", "Assignment 1", "Assignment", due[i], "pink");
        }
        else {
            month4->AddTAssign("ABCD 123", "Assignment 1", "Assignment", due[i], "pink");
        }
    }

    setLayout(termlay);

}

TermView::~TermView()
{
    delete ui;
}
