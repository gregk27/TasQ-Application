//
// Created by Greg on 2021-11-26.
//

// You may need to build the project (run Qt uic code generator) to get "ui_EditEventDialog.h" resolved

#include "include/widgets/coursemod/editeventdialog.h"
#include "ui_EditEventDialog.h"
#include <ApplicationController.h>

EditEventDialog::EditEventDialog(models::Course *c, models::Event *e, QWidget *parent) :
        QDialog(parent), ui(new Ui::EditEventDialog) {
    ui->setupUi(this);
    setModal(true);

    course = c;
    event = e;

    ui->typeInput->addItem(models::enums::EventType::LECTURE.toString(), models::enums::EventType::LECTURE.toDB());
    ui->typeInput->addItem(models::enums::EventType::TUTORIAL.toString(), models::enums::EventType::TUTORIAL.toDB());
    ui->typeInput->addItem(models::enums::EventType::LAB.toString(), models::enums::EventType::LAB.toDB());
    ui->typeInput->addItem(models::enums::EventType::ASSIGNMENT.toString(), models::enums::EventType::ASSIGNMENT.toDB());
    ui->typeInput->addItem(models::enums::EventType::QUIZ.toString(), models::enums::EventType::QUIZ.toDB());
    ui->typeInput->addItem(models::enums::EventType::TEST.toString(), models::enums::EventType::TEST.toDB());

    if(e != nullptr){
        ui->title->setText(c->getCode()+": "+e->getName());
        ui->nameInput->setText(e->getName());
        ui->weightInput->setValue(e->getWeight());
        ui->startInput->setDateTime(e->getQDatetime());
        ui->typeInput->setCurrentText(e->getType().toString());
        if(e->getEndDate().has_value()){
            ui->endInput->setDateTime(QDateTime::fromSecsSinceEpoch(e->getEndDate().value()));
        } else {
            ui->endInput->setDateTime(e->getQDatetime());
        }
        ui->weeklyInput->setChecked(e->getWeekly());
        ui->actionButton->setText("Update");
    } else {
        ui->title->setText(c->getCode()+": New Event");
    }

}

EditEventDialog::~EditEventDialog() {
    delete ui;
}

void EditEventDialog::saveEvent() {
    QJsonObject js;
    js["course"] = course->getId();
    js["name"] = ui->nameInput->text();
    js["type"] = ui->typeInput->currentData().toString();
    js["weight"] = ui->weightInput->value();
    js["datetime"] = ui->startInput->dateTime().toSecsSinceEpoch();
    if(ui->startInput->dateTime() != ui->endInput->dateTime()){
        js["endDate"] = ui->endInput->dateTime().toSecsSinceEpoch();
    }
    js["weekly"] = ui->weeklyInput->isChecked();
    if(event){
        js["id"] = event->getId();
        ApplicationController::instance()->modifyInstance<Event>(new Event(js));
    } else {
        ApplicationController::instance()->addInstance<Event>(new Event(js));
    }
    close();
}
