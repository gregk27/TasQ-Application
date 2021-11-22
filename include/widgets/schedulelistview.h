#ifndef SCHEDULELISTVIEW_H
#define SCHEDULELISTVIEW_H

#include <QWidget>

namespace Ui {
class ScheduleListView;
}

class ScheduleListView : public QWidget
{
    Q_OBJECT

public:
    explicit ScheduleListView(QWidget *parent = nullptr);
    ~ScheduleListView();

private:
    Ui::ScheduleListView *ui;

    void generateUI();
};

#endif // SCHEDULELISTVIEW_H
