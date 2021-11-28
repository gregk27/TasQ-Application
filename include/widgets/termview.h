#ifndef TERMVIEW_H
#define TERMVIEW_H

#include <QWidget>
#include <QGridLayout>
#include <QDate>
#include "monthcalendar.h"
#include <models/Event.h>
#include <widgets/monthcalendar.h>

namespace Ui {
    class TermView;
}

class TermView : public QWidget
{
    Q_OBJECT

public:
    explicit TermView(QWidget* parent = nullptr);
    ~TermView();

    void addAssignment(QString classid, QString assign, QString type, QDateTime* due, QString colour);
    void clear();

private:
    Ui::TermView* ui;

    QDate *date1;
    MonthCalendar* month1;
    QDate *date2;
    MonthCalendar* month2;
    QDate *date3;
    MonthCalendar* month3;
    QDate *date4;
    MonthCalendar* month4;
};

#endif // TERMVIEW_H
