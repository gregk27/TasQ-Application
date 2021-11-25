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

    void generateUI(std::unordered_map<QString, models::Event*> events);
private:

    Ui::ScheduleListView *ui;
    QFrame *createFrameForDate(QDate date);
    QFrame *createFrameForEvent(models::Event *e);

public slots:
    void onEventsChanged();
};

#endif // SCHEDULELISTVIEW_H
