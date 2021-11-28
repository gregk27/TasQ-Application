//
// Created by Greg on 2021-11-27.
//

#ifndef TASQ_APPLICATION_WEEKVIEW_H
#define TASQ_APPLICATION_WEEKVIEW_H

#include <QWidget>
#include <widgets/weekday.h>


QT_BEGIN_NAMESPACE
namespace Ui { class WeekView; }
QT_END_NAMESPACE

class WeekView : public QWidget {
    Q_OBJECT

public:
    explicit WeekView(QWidget *parent = nullptr);

    ~WeekView() override;

    void clear();
    void addEvent(models::Event *e);

private:
    Ui::WeekView *ui;

    WeekDay *days[7];
};


#endif //TASQ_APPLICATION_WEEKVIEW_H
