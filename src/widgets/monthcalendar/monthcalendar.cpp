#include <widgets/monthcalendar.h>
#include <utils.h>
#include "ui_monthcalendar.h"

MonthCalendar::MonthCalendar(int month, QWidget* parent) :
    QWidget(parent),
    ui(new Ui::MonthCalendar)
{
    ui->setupUi(this);
    setMouseTracking(true);
    QDate* date = new QDate;
    date->setDate(QDate::currentDate().year(), month, 1);
    QLabel* title;
    int monthdays = 31;

    //Determine the name of and number of days in the month
    switch (month) {
    case 1:
        title = new QLabel("January");
        break;
    case 2:
        title = new QLabel("February");
        if (date->year() % 4 == 0) {
            monthdays = 29;
        }
        else {
            monthdays = 28;
        }
        break;
    case 3:
        title = new QLabel("March");
        break;
    case 4:
        title = new QLabel("April");
        monthdays = 30;
        break;
    case 5:
        title = new QLabel("May");
        break;
    case 6:
        title = new QLabel("June");
        monthdays = 30;
        break;
    case 7:
        title = new QLabel("July");
        break;
    case 8:
        title = new QLabel("August");
        break;
    case 9:
        title = new QLabel("September");
        monthdays = 30;
        break;
    case 10:
        title = new QLabel("October");
        break;
    case 11:
        title = new QLabel("November");
        monthdays = 30;
        break;
    case 12:
        title = new QLabel("December");
        break;
    default:
        break;
    }

    //Determine the day of the week that the month starts on
    int start = ((date->dayOfWeek())-1)%7;

    //Create a table to act as the calendar
    QTableWidget* cal = new QTableWidget((((monthdays + start)) / 7 + 1), 7);
    cal->verticalHeader()->hide();
    cal->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    cal->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    cal->setStyleSheet("QTableWidget::item { padding: 0px }");

    //Label the week days
    QStringList weekdays = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
    cal->setHorizontalHeaderLabels(weekdays);

    //Populate the table
    QWidget* cell[monthdays];       //Widget to contain layout
    QVBoxLayout* day[monthdays];    //Layout for cell
    QLabel* num[monthdays];         //Label for day number

    for (int i = 0; i < monthdays; i++) {
        cell[i] = new QWidget;
        day[i] = new QVBoxLayout;
        tdue[i] = new QHBoxLayout;
        mdue[i] = new QVBoxLayout;
        num[i] = new QLabel(QString::number(i + 1));
        day[i]->addWidget(num[i]);
        day[i]->addItem(new QSpacerItem(5, 5, QSizePolicy::Minimum, QSizePolicy::Expanding));
        day[i]->addLayout(mdue[i]);
        day[i]->addLayout(tdue[i]);
        cell[i]->setLayout(day[i]);
        cal->setCellWidget((((i + start) / 7)), ((i + start) % 7), cell[i]);
    }

    for (int i = 0; i <= ((monthdays + start) / 7); i++) {
        cal->setRowHeight(i, 50);
    }


    QVBoxLayout* lay = new QVBoxLayout;
    lay->addWidget(title);
    lay->addWidget(cal);

    setLayout(lay);




}

MonthCalendar::~MonthCalendar()
{
    delete ui;
}

// Purpose: Adds assignments to the calendar for month view
void MonthCalendar::AddMAssign(QString courseid, QString assign, QString type, QDateTime* due, QString colour) {
    QRadioButton* circle = new QRadioButton(assign);
    circle->setEnabled(false);
    circle->setStyleSheet("QRadioButton::indicator::unchecked{ border: 1px solid " + colour + "; border-radius: 6px; background-color: " + colour + "; width: 10px; height: 10px; margin-left: 5px;}");
    mdue[due->date().day()-1]->addWidget(circle);
    QString* description = new QString(courseid + "\n" + assign + "\n" + type + "\n" + due->toString());
    circle->setToolTip(*description);
}


// Purpose: Adds assignments to the calendar for term view
void MonthCalendar::AddTAssign(QString courseid, QString assign, QString type, QDateTime* due, QString colour) {
    QRadioButton* circle = new QRadioButton;
    circle->setEnabled(false);
    circle->setStyleSheet("QRadioButton::indicator::unchecked{ border: 1px solid " + colour + "; border-radius: 6px; background-color: " + colour + "; width: 10px; height: 10px; margin-left: 5px;}");
    tdue[due->date().day()-1]->addWidget(circle);
    QString* description = new QString(courseid + "\n" + assign + "\n" + type + "\n" + due->toString());
    circle->setToolTip(*description);
}

void MonthCalendar::clear() {
    for(auto layout : mdue){
        if(layout)
            utils::clearLayout(layout);
    }
    for(auto layout : tdue){
        if(layout)
            utils::clearLayout(layout);
    }
}