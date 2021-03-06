#ifndef SCHEDULESCREEN_H
#define SCHEDULESCREEN_H

#include <QWidget>

namespace Ui {
class ScheduleScreen;
}

class ScheduleScreen : public QWidget
{
    Q_OBJECT

public:
    explicit ScheduleScreen(QWidget *parent = nullptr);
    ~ScheduleScreen();

private:
    Ui::ScheduleScreen *ui;

public slots:
    void onEventsChanged();
};

#endif // SCHEDULESCREEN_H
