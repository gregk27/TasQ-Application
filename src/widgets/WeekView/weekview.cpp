//
// Created by Greg on 2021-11-27.
//

// You may need to build the project (run Qt uic code generator) to get "ui_WeekView.h" resolved

#include <widgets/weekview.h>
#include <QGridLayout>
#include <QLabel>
#include <QFont>
#include "ui_WeekView.h"


WeekView::WeekView(QWidget *parent) :
        QWidget(parent), ui(new Ui::WeekView) {
    ui->setupUi(this);

    QString names[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    auto font = QFont();
    font.setPointSize(12);
    int i=0;
    for(auto n : names){
        auto header = new QLabel(n);
        header->setFrameShape(QFrame::StyledPanel);
        header->setFrameShadow(QFrame::Raised);
        header->setFont(font);
        header->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        header->setMinimumWidth(150);
        header->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        ui->headerLayout->addWidget(header);
        days[i] = new WeekDay();
        days[i]->setMinimumWidth(150);
        ui->dayLayout->addWidget(days[i]);
        i++;
    }
    ui->headerLayout->addSpacerItem(new QSpacerItem(17, 0, QSizePolicy::Fixed, QSizePolicy::Fixed));
}

WeekView::~WeekView() {
    delete ui;
}

void WeekView::clear(){
    for(int i=0; i<7; i++){
        days[i]->clear();
    }
}

void WeekView::addEvent(models::Event *e) {
    days[e->getQDatetime().date().dayOfWeek()-1]->addEvent(e);
}