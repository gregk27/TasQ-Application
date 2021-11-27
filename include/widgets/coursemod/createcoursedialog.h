//
// Created by Greg on 2021-11-26.
//

#ifndef TASQ_APPLICATION_CREATECOURSEDIALOG_H
#define TASQ_APPLICATION_CREATECOURSEDIALOG_H

#include "../../../../../../../../../Qt/6.2.0/mingw81_64/include/QtWidgets/QDialog"
#include "../../models/Models.h"


QT_BEGIN_NAMESPACE
namespace Ui { class CreateCourseDialog; }
QT_END_NAMESPACE

class CreateCourseDialog : public QDialog {
    Q_OBJECT

public:
    explicit CreateCourseDialog(QWidget *parent = nullptr);

    ~CreateCourseDialog() override;

private:
    Ui::CreateCourseDialog *ui;

signals:
    void createCourse(models::Course *c);

public slots:
    void createCourse();
};


#endif //TASQ_APPLICATION_CREATECOURSEDIALOG_H
