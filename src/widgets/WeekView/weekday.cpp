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

    ui->events->setFixedHeight(blockHeight * (endTime-startTime)*blocksPerHour);
    clear();
}

WeekDay::~WeekDay() {
    delete ui;
}

void WeekDay::clear() {
    utils::clearLayout(ui->eventLayout);
    // Rebuild day structure
    for(int i=startTime; i<(endTime-startTime)*blocksPerHour; i++){
        ui->eventLayout->addItem(new QSpacerItem(10, blockHeight, QSizePolicy::Fixed, QSizePolicy::Fixed), i, 0);
    }
}

void WeekDay::addEvent(models::Event *e) {
    auto time = e->getQDatetime().time();
    int row = ((time.hour() - startTime) * blocksPerHour) + (int) (time.minute() * (blocksPerHour/60.0));
    auto frame = new QFrame();
    frame->setFrameStyle(QFrame::Box);
    frame->setFrameShadow(QFrame::Plain);
    frame->setFixedHeight(4*blockHeight);
    frame->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    auto colours = utils::getColourForCourse(e->getCourseId());
    frame->setStyleSheet(QString("background-color:rgb(%1,%2,%3)").arg(colours[0]).arg(colours[1]).arg(colours[2]));

    auto layout = new QHBoxLayout();
    frame->setLayout(layout);

    layout->addWidget(new QLabel(e->getName()));
    layout->addWidget(new QLabel(time.toString("h:mm AP")));
//    layout->addWidget(new QLabel(e->getCourse()->getCode()));

    ui->eventLayout->addWidget(frame, row, 0, 4, 1);
}