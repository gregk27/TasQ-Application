//
// Created by Greg on 2021-11-26.
//

#ifndef TASQ_APPLICATION_EDITEVENTDIALOG_H
#define TASQ_APPLICATION_EDITEVENTDIALOG_H

#include <QDialog>
#include <models/Event.h>
#include <models/Course.h>


QT_BEGIN_NAMESPACE
namespace Ui { class EditEventDialog; }
QT_END_NAMESPACE

class EditEventDialog : public QDialog {
Q_OBJECT

public:
    explicit EditEventDialog(models::Course *c, models::Event *e = nullptr, QWidget *parent = nullptr);

    ~EditEventDialog() override;

private:
    Ui::EditEventDialog *ui;
    models::Event *event;
    models::Course *course;

public slots:
    void saveEvent();
    void startChanged(QTime t);
    void endChanged(QTime t);
};


#endif //TASQ_APPLICATION_EDITEVENTDIALOG_H
