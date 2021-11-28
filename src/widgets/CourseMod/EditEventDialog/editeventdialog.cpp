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
        auto dateTime = e->getQDatetime();
        ui->title->setText(c->getCode()+": "+e->getName());
        ui->nameInput->setText(e->getName());
        ui->weightInput->setValue(e->getWeight());
        ui->startInput->setTime(dateTime.time());
        ui->typeInput->setCurrentText(e->getType().toString());
        if(e->getEndDate().has_value()){
            ui->endInput->setTime(QDateTime::fromSecsSinceEpoch(e->getEndDate().value()).time());
        } else {
            ui->endInput->setTime(dateTime.time());
        }
        ui->dateInput->setSelectedDate(dateTime.date());
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
    js["datetime"] = QDateTime(ui->dateInput->selectedDate(), ui->startInput->time()).toSecsSinceEpoch();
    if(ui->startInput->time() != ui->endInput->time()){
        js["endDate"] = QDateTime(ui->dateInput->selectedDate(), ui->endInput->time()).toSecsSinceEpoch();
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

void EditEventDialog::startChanged(QTime t) {
    if(ui->endInput->property("delta").isValid()){
        ui->endInput->setTime(t.addMSecs(ui->endInput->property("delta").toInt()));
    } else {
        ui->endInput->setTime(t);
    }
}

void EditEventDialog::endChanged(QTime t) {
    if(t < ui->startInput->time()){
        ui->endInput->setTime(ui->startInput->time());
        ui->endInput->setProperty("delta", 0);
        return;
    }
    ui->endInput->setProperty("delta", t.msecsSinceStartOfDay() - ui->startInput->time().msecsSinceStartOfDay());
}