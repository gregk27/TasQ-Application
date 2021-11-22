#ifndef SCHEDULEFILTER_H
#define SCHEDULEFILTER_H

#include <QWidget>

namespace Ui {
class ScheduleFilter;
}

class ScheduleFilter : public QWidget
{
    Q_OBJECT

public:
    explicit ScheduleFilter(QWidget *parent = nullptr);
    ~ScheduleFilter();

private:
    Ui::ScheduleFilter *ui;
};

#endif // SCHEDULEFILTER_H
