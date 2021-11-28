//
// Created by Greg on 2021-11-27.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ScollView.h" resolved

#include <widgets/scrollwidget.h>
#include <utils.h>
#include "ui_ScrollWidget.h"


ScrollWidget::ScrollWidget(QWidget *parent) :
        QFrame(parent), ui(new Ui::ScrollWidget) {
    ui->setupUi(this);
}

ScrollWidget::~ScrollWidget() {
    delete ui;
}

void ScrollWidget::clearContent() {
    utils::clearLayout(ui->contentLayout);
    ui->contentLayout->addItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));
}

void ScrollWidget::addWidget(QWidget *widget){
    widget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    ui->contentLayout->insertWidget(ui->contentLayout->count()-1, widget);
}

bool ScrollWidget::event(QEvent *e) {
    if(e->type() == QEvent::DynamicPropertyChange){
        if(property("showScroll").isValid() && property("showScroll").toBool()){
            ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        } else {
//            ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        }
    }
    return QFrame::event(e);
}