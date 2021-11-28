//
// Created by Greg on 2021-11-26.
//

#ifndef TASQ_APPLICATION_EDITCOURSEDIALOG_H
#define TASQ_APPLICATION_EDITCOURSEDIALOG_H

#include <QDialog>
#include <models/course.h>


QT_BEGIN_NAMESPACE
namespace Ui { class EditCourseDialog; }
QT_END_NAMESPACE

class EditCourseDialog : public QDialog {
Q_OBJECT

public:
    explicit EditCourseDialog(models::Course *c, QWidget *parent = nullptr);

    ~EditCourseDialog() override;

private:
    Ui::EditCourseDialog *ui;
    models::Course *c;

public slots:
    void populateEvents();
    void createEvent();
};


#endif //TASQ_APPLICATION_EDITCOURSEDIALOG_H
