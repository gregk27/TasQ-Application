#ifndef MONTHVIEW_H
#define MONTHVIEW_H

#include <QWidget>
#include "monthcalendar.h"

namespace Ui {
    class MonthView;
}

class MonthView : public QWidget
{
    Q_OBJECT

public:
    explicit MonthView(QWidget* parent = nullptr);
    ~MonthView();

private:
    Ui::MonthView* ui;
};

#endif // MONTHVIEW_H
