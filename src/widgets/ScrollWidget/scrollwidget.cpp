//
// Created by Greg on 2021-11-27.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ScollView.h" resolved

#include <widgets/scrollwidget.h>
#include <utils.h>
#include "ui_ScrollWidget.h"


ScrollWidget::ScrollWidget(QWidget *parent) :
        QScrollArea(parent), ui(new Ui::ScrollWidget) {
    ui->setupUi(this);
}

ScrollWidget::~ScrollWidget() {
    delete ui;
}

void ScrollWidget::clearContent() {
    utils::clearLayout(ui->contentLayout);
}

void ScrollWidget::addWidget(QWidget *widget){
    widget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    ui->contentLayout->addWidget(widget);
}
