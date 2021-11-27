//
// Created by Adi Nachmani on 2021-11-20.
//

#ifndef TASQ_APPLICATION_ADDREMOVECLASS_H
#define TASQ_APPLICATION_ADDREMOVECLASS_H

#include "../../../../../../../../../Qt/6.2.0/mingw81_64/include/QtWidgets/QDialog"
#include "../../../../../../../../../Qt/6.2.0/mingw81_64/include/QtWidgets/QVBoxLayout"
#include "../../../../../../../../../Qt/6.2.0/mingw81_64/include/QtWidgets/QFrame"

#include "../../models/Course.h"

QT_BEGIN_NAMESPACE
namespace Ui { class AddRemoveClass; }
QT_END_NAMESPACE

class AddRemoveClass : public QDialog {
    Q_OBJECT

public:
    explicit AddRemoveClass(QWidget *parent = nullptr);

    ~AddRemoveClass() override;

private:
    Ui::AddRemoveClass *ui;
    void populateClasses(std::unordered_map<QString, models::Course*> courses);
    QFrame *buildFrameForCourse(models::Course *c, QPushButton **btn);

    std::shared_ptr<std::vector<models::Course>> courses;

public slots:
    void coursesChanged();
    void showSearchResults(QString search);
    void showCreateCourse();

signals:
    void removeCourse(models::Course *c);
    void addCourse(models::Course *c);
};


#endif //TASQ_APPLICATION_ADDREMOVECLASS_H
