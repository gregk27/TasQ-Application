//
// Created by Greg on 2021-11-27.
//

#ifndef TASQ_APPLICATION_WEEKDAY_H
#define TASQ_APPLICATION_WEEKDAY_H

#include <QFrame>
#include <models/Event.h>


QT_BEGIN_NAMESPACE
namespace Ui { class WeekDay; }
QT_END_NAMESPACE

class WeekDay : public QFrame {
Q_OBJECT

public:
    explicit WeekDay(QWidget *parent = nullptr);

    ~WeekDay() override;

    void clear();
    void addEvent(models::Event *e);

    bool event(QEvent *e) override;
private:
    Ui::WeekDay *ui;

    float startTime = 8.00;
    float endTime = 24.00;
    int blocksPerHour = 4;
    int blockHeight = 10;
};


#endif //TASQ_APPLICATION_WEEKDAY_H
