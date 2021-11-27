//
// Created by Greg on 2021-11-26.
//

// You may need to build the project (run Qt uic code generator) to get "ui_EditCourseDialog.h" resolved

#include <widgets/coursemod/editcoursedialog.h>
#include <widgets/coursemod/editeventdialog.h>
#include "ui_EditCourseDialog.h"
#include <utils.h>
#include <models/Event.h>
#include <ApplicationController.h>


EditCourseDialog::EditCourseDialog(models::Course *c, QWidget *parent) :
        QDialog(parent), ui(new Ui::EditCourseDialog) {
    ui->setupUi(this);
    setModal(true);
    this->c = c;

    ui->couseLabel->setText(c->getCode());
    connect(ApplicationController::instance(), &ApplicationController::eventsChanged, this, &EditCourseDialog::populateEvents);
    populateEvents();
}

EditCourseDialog::~EditCourseDialog() {
    delete ui;
}

void EditCourseDialog::populateEvents(){
    utils::clearLayout(ui->eventLayout);
    auto events = c->getEvents();
    ui->eventLayout->setSpacing(0);
    for(auto e : events){
        QFrame *frame = new QFrame(ui->scrollArea);
        frame->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        frame->setFixedHeight(25);
        auto layout = new QHBoxLayout();
        frame->setLayout(layout);
        layout->setContentsMargins(0, 0, 0, 0);
        layout->setSpacing(5);

        auto l = new QLabel(frame);
        l->setText(e->getName());
        l->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        layout->addWidget(l);

        layout->addSpacerItem(new QSpacerItem(25, 0, QSizePolicy::Fixed));

        l = new QLabel(frame);
        if(e->getWeekly()){
            l->setText(e->getQDatetime().toString("dddd's' h:mm ap"));
        } else {
            l->setText(e->getQDatetime().toString());
        }
        l->setFixedWidth(150);
        l->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        layout->addWidget(l);

        auto btn = new QPushButton(frame);
        btn->setText("Edit");
        btn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        connect(btn, &QPushButton::clicked, [&, course=c, event=e] {
            (new EditEventDialog(course, event))->show();
        });
        layout->addWidget(btn);

        btn = new QPushButton(frame);
        btn->setText("Delete");
        btn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        connect(btn, &QPushButton::clicked, [&, event=e] {
            ApplicationController::instance()->removeInstance<Event>(event);
        });
        layout->addWidget(btn);

        ui->eventLayout->addWidget(frame);
    }
    ui->eventLayout->addItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));
}

void EditCourseDialog::createEvent(){
    (new EditEventDialog(c))->show();
}