//
// Created by Greg on 2021-11-27.
//

// You may need to build the project (run Qt uic code generator) to get "ui_WeekView.h" resolved

#include <widgets/weekview.h>
#include <QGridLayout>
#include "ui_WeekView.h"


WeekView::WeekView(QWidget *parent) :
        QWidget(parent), ui(new Ui::WeekView) {
    ui->setupUi(this);

    auto layout = new QHBoxLayout();

}

WeekView::~WeekView() {
    delete ui;
}

