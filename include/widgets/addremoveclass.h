//
// Created by Adi Nachmani on 2021-11-20.
//

#ifndef TASQ_APPLICATION_ADDREMOVECLASS_H
#define TASQ_APPLICATION_ADDREMOVECLASS_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class AddRemoveClass; }
QT_END_NAMESPACE

class AddRemoveClass : public QWidget {
    Q_OBJECT

public:
    explicit AddRemoveClass(QWidget *parent = nullptr);

    ~AddRemoveClass() override;

private:
    Ui::AddRemoveClass *ui;
};


#endif //TASQ_APPLICATION_ADDREMOVECLASS_H
