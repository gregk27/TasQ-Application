#ifndef MONTHVIEW_H
#define MONTHVIEW_H

#include <QWidget>
#include "monthcalendar.h"
#include <models/Event.h>
#include <widgets/monthcalendar.h>

namespace Ui {
    class MonthView;
}

class MonthView : public QWidget
{
    Q_OBJECT

public:
    explicit MonthView(QWidget* parent = nullptr);
    ~MonthView();

    MonthCalendar *cal;

private:
    Ui::MonthView* ui;
};

#endif // MONTHVIEW_H
