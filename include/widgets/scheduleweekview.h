#ifndef SCHEDULEWEEKVIEW_H
#define SCHEDULEWEEKVIEW_H

#include <QWidget>

namespace Ui {
class ScheduleWeekView;
}

class ScheduleWeekView : public QWidget
{
    Q_OBJECT

public:
    explicit ScheduleWeekView(QWidget *parent = nullptr);
    ~ScheduleWeekView();

private:
    Ui::ScheduleWeekView *ui;
};

#endif // SCHEDULEWEEKVIEW_H
