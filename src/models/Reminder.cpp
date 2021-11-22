//
// Created by Greg on 2021-10-19.
//

#include <models/Reminder.h>
#include <models/User.h>

using namespace std;
using namespace models;


Reminder::Reminder(QJsonValue &json):
    NetModel(json["id"].toString()) {
    eventId = json["event"].toString();
}

uuid Reminder::getEventId() {
    return eventId;
}

QString Reminder::getURL(Action a) {
    switch(a){
        case NetModel::ADD:
            return "/users/reminders/add";
        case NetModel::MODIFY:
            throw ActionException("modify", "reminder");
        case NetModel::REMOVE:
            return "/users/reminders/"+id+"/remove";
    }
    throw ActionException("none", "reminder");
}

std::map<QString, QString> *Reminder::getBody(Action a) {
    if(a == Action::MODIFY)
        throw ActionException("modify", "reminder");
    return new map<QString, QString> {{"event", eventId}};
}