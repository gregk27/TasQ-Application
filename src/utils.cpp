//
// Created by Greg on 2021-11-21.
//

#include <utils.h>
#include <QCryptographicHash>
#include <QWidget>
#include <QSpacerItem>
#include <vector>
#include <models/Event.h>

using namespace std;
using namespace models;

int *utils::getColourForCourse(QString courseID) {
    auto hash = QCryptographicHash::hash(courseID.toLocal8Bit(), QCryptographicHash::Md5);
    return new int[3] {hash[0]+127, hash[1]+127, hash[2]+127};
}

// Implementation from SO: https://stackoverflow.com/questions/4857188/clearing-a-layout-in-qt
void utils::clearLayout(QLayout *layout){
    QLayoutItem *item;
    while((item = layout->takeAt(0))) {
        if (item->layout()) {
            clearLayout(item->layout());
            delete item->layout();
        }
        if(item->widget())
            delete item->widget();
        delete item;
    }
}

shared_ptr<vector<Event>> utils::computeWeekly(Event *baseEvent, QDate endDate){
    auto endDT = QDateTime(endDate, QTime(11, 59, 59));
    auto out = make_shared<vector<Event>>();
    if(!baseEvent->getWeekly()) {
        out->push_back(*baseEvent);
        return out;
    };
    QDateTime dt = baseEvent->getQDatetime();
    while(dt < endDT){
        // Create a new event with new timestamp
        Event e(*baseEvent);
        unsigned long long timestamp = dt.toSecsSinceEpoch();
        e.setDatetime(timestamp);
        out->push_back(e);
        // Update to next week
        dt = dt.addDays(7);
    }
    return out;
}