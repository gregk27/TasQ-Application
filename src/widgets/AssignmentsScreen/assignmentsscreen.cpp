#include <widgets/assignmentsscreen.h>
#include <ApplicationController.h>
#include <utils.h>
#include <models/Event.h>
#include <models/Course.h>
#include <models/enums.h>
#include "ui_assignmentsscreen.h"

AssignmentsScreen::AssignmentsScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AssignmentsScreen)
{
    ui->setupUi(this);
    connect(ApplicationController::instance(), &ApplicationController::eventsChanged, this, &AssignmentsScreen::onEventsChange);
}

AssignmentsScreen::~AssignmentsScreen()
{
    delete ui;
}

void AssignmentsScreen::onEventsChange(){
    auto events = ApplicationController::instance()->getInstances<Event>();
    ui->monthView->cal->clear();
    ui->termView->clear();
    ui->listView->clear();
    auto currDatetime = QDateTime::currentDateTime();
    auto currDate = currDatetime.date();
    auto termStartDate = QDate(2021, 9, 7);
    auto termEndDate = QDate(2021, 12, 3);
    for(auto [eId, e] : events){
        // Don't show lect/lab/tut
        if(e->getType() == models::enums::EventType::LECTURE ||
            e->getType() == models::enums::EventType::TUTORIAL ||
            e->getType() == models::enums::EventType::LAB) continue;
        auto colour = utils::getColourForCourse(e->getCourse()->getId());

        auto colourString = QString("rgb(%1,%2,%3)").arg(colour[0]).arg(colour[1]).arg(colour[2]);

        // Compute the weekly occurrences for the event
        auto weekly = utils::computeWeekly(e, termEndDate);
        for(auto we : *weekly){
            auto dateTime = we.getQDatetime();
            auto date = dateTime.date();
            if(date.month() == currDate.month() && date.year() == currDate.year()){
                ui->monthView->cal->AddMAssign(we.getCourse()->getCode(), we.getName(), we.getType().toString(), &dateTime, colourString);
            }

            if(date > termStartDate && date < termEndDate){
                ui->termView->addAssignment(we.getCourse()->getCode(), we.getName(), we.getType().toString(), &dateTime, colourString);
            }

            // Don't show past events in list
            if(dateTime > currDatetime)
                ui->listView->addEvent(&we);
        }
    }
}
