//
// Created by Adi Nachmani on 2021-11-20.
//

#ifndef TASQ_APPLICATION_ADDREMOVECLASS_H
#define TASQ_APPLICATION_ADDREMOVECLASS_H

#include <QDialog>
#include <QVBoxLayout>
#include <QFrame>


namespace models {
    class Course;
}

QT_BEGIN_NAMESPACE
namespace Ui { class AddRemoveClass; }
QT_END_NAMESPACE

class AddRemoveClass : public QDialog {
    Q_OBJECT

public:
    explicit AddRemoveClass(QWidget *parent = nullptr);

    ~AddRemoveClass() override;

    void populateClasses(std::vector<models::Course> *courses);
private:
    Ui::AddRemoveClass *ui;
};


#endif //TASQ_APPLICATION_ADDREMOVECLASS_H
