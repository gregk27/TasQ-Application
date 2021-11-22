#ifndef SCHEDULELISTVIEW_H
#define SCHEDULELISTVIEW_H

#include <QWidget>
#include <QFrame>

namespace models {
    class Event;
}

namespace Ui {
class ScheduleListView;
}

class ScheduleListView : public QWidget
{
    Q_OBJECT

public:
    explicit ScheduleListView(QWidget *parent = nullptr);
    ~ScheduleListView();

    void generateUI(std::vector<models::Event> *events);
private:

    Ui::ScheduleListView *ui;
    QFrame *createFrameForDate(QDate date);
    QFrame *createFrameForEvent(models::Event *e);
};

#endif // SCHEDULELISTVIEW_H
