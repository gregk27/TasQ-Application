#include <widgets/schedulescreen.h>
#include <ApplicationController.h>
#include <models/Enums.h>
#include <models/Event.h>
#include "ui_schedulescreen.h"

ScheduleScreen::ScheduleScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScheduleScreen)
{
    ui->setupUi(this);
}

ScheduleScreen::~ScheduleScreen()
{
    delete ui;
}

void ScheduleScreen::onEventsChanged() {
    auto events = ApplicationController::instance()->getInstances<Event>();
    ui->list_view->clear();
    auto currDate = QDate::currentDate();
    for(auto [eId, e] : events){
        // Don't show assignment/quiz/test
        if(e->getType() == models::enums::EventType::ASSIGNMENT ||
           e->getType() == models::enums::EventType::QUIZ ||
           e->getType() == models::enums::EventType::TEST) continue;
        auto dateTime = e->getQDatetime();

        ui->list_view->addEvent(e);
    }
}