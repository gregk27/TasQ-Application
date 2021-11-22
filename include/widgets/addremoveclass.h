//
// Created by Adi Nachmani on 2021-11-20.
//

#ifndef TASQ_APPLICATION_ADDREMOVECLASS_H
#define TASQ_APPLICATION_ADDREMOVECLASS_H

#include <QDialog>
#include <QVBoxLayout>
#include <QFrame>

#include <models/Course.h>

Q_DECLARE_METATYPE(models::Course)

QT_BEGIN_NAMESPACE
namespace Ui { class AddRemoveClass; }
QT_END_NAMESPACE

class AddRemoveClass : public QDialog {
    Q_OBJECT

public:
    explicit AddRemoveClass(std::vector<models::Course> *courses, QWidget *parent = nullptr);

    ~AddRemoveClass() override;

private:
    Ui::AddRemoveClass *ui;
    void populateClasses(std::vector<models::Course> *courses);

public slots:
    void coursesChanged(std::vector<models::Course> *courses);

signals:
    void removeCourse(const models::Course *c);
    void addCourse();
};


#endif //TASQ_APPLICATION_ADDREMOVECLASS_H
