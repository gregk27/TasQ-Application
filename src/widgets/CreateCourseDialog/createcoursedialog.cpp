//
// Created by Greg on 2021-11-26.
//

// You may need to build the project (run Qt uic code generator) to get "ui_CreateClassDialog.h" resolved

#include <widgets/createcoursedialog.h>
#include "ui_CreateCourseDialog.h"


CreateCourseDialog::CreateCourseDialog(QWidget *parent) :
        QDialog(parent), ui(new Ui::CreateCourseDialog) {
    ui->setupUi(this);
    setModal(true);
}

CreateCourseDialog::~CreateCourseDialog() {
    delete ui;
}


