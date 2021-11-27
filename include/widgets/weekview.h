//
// Created by Greg on 2021-11-27.
//

#ifndef TASQ_APPLICATION_WEEKVIEW_H
#define TASQ_APPLICATION_WEEKVIEW_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class WeekView; }
QT_END_NAMESPACE

class WeekView : public QWidget {
    Q_OBJECT

public:
    explicit WeekView(QWidget *parent = nullptr);

    ~WeekView() override;

private:
    Ui::WeekView *ui;
};


#endif //TASQ_APPLICATION_WEEKVIEW_H
