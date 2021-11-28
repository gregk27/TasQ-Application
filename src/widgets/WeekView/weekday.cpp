//
// Created by Greg on 2021-11-27.
//

// You may need to build the project (run Qt uic code generator) to get "ui_WeekDay.h" resolved

#include <widgets/weekday.h>
#include "ui_WeekDay.h"
#include <utils.h>
#include <QLabel>


WeekDay::WeekDay(QWidget *parent) :
        QFrame(parent), ui(new Ui::WeekDay) {
    ui->setupUi(this);
    setFrameShape(QFrame::Box);
    setFrameShadow(QFrame::Sunken);
    ui->events->setFixedHeight(blockHeight * (endTime-startTime)*blocksPerHour);
    clear();
}

WeekDay::~WeekDay() {
    delete ui;
}

void WeekDay::clear() {
    utils::clearLayout(ui->eventLayout);
    // Rebuild day structure
    for(int i=0; i<(endTime-startTime)*blocksPerHour; i++){
        ui->eventLayout->addItem(new QSpacerItem(10, blockHeight, QSizePolicy::Fixed, QSizePolicy::Fixed), i, 0);
    }
}

void WeekDay::addEvent(models::Event *e) {
    auto time = e->getQDatetime().time();
    int row = ((time.hour() - startTime) * blocksPerHour) + (int) (time.minute() * (blocksPerHour/60.0));
    int blocks = e->getEndDate().has_value() ? (e->getEndDate().value() - e->getDatetime()) * (blocksPerHour / 3600.0): 1;
    auto frame = new QFrame(ui->events);
    frame->setFrameStyle(QFrame::Box);
    frame->setFrameShadow(QFrame::Plain);
    frame->setFixedHeight(blocks*blockHeight);
    frame->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    frame->setStyleSheet(utils::getColourForCourse(e->getCourseId()));

    auto layout = new QHBoxLayout();
    frame->setLayout(layout);

    layout->addWidget(new QLabel(e->getName()));
    layout->addWidget(new QLabel(time.toString("h:mm AP")));
//    layout->addWidget(new QLabel(e->getCourse()->getCode()));

    frame->setToolTip(e->getCourse()->getCode() + "\n" + e->getName() + "\n" + e->getType().toString() + "\n" + e->getQDatetime().toString());

    ui->eventLayout->addWidget(frame, row, 0, blocks, 1);
}