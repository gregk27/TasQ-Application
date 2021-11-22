//
// Created by Greg on 2021-10-19.
//
#include <optional>
#include <net/auth.h>
#include <models/Event.h>
#include <models/User.h>

using namespace std;
using namespace models;

// Forward declare localUID since cannot import auth
namespace net::auth {
    extern optional<string> localUID;
}

Event::Event(QJsonValue json):
        NetModel(json["id"].toString()), type(enums::EventType::fromDB(json["type"].toString())) {
    courseID = json["course"].toString();
    name = json["name"].toString();
    weight = json["weight"].toInt();
    datetime = json["datetime"].toInteger();
    if(json["endDate"].isNull()){
        endDate = {};
    } else {
        endDate = json["endDate"].toInteger();
    }
    weekly = json["weekly"].toBool();
}

uuid Event::getCourseId() {
    return courseID;
}

void Event::setCourseID(uuid &newCourseID) {
    // TODO: Add database changes
    courseID = newCourseID;
}

QString Event::getName() {
    return name;
}

void Event::setName(QString &newName) {
    // TODO: Add database changes
    name = newName;
}

enums::EventType Event::getType() {
    return type;
}

void Event::setType(enums::EventType &newType) {
    // TODO: Add database changes
    type = newType;
}

int Event::getWeight() {
    return weight;
}

void Event::setWeight(int newWeight) {
    weight = newWeight;
}

unsigned long long Event::getDatetime() {
    return datetime;
}

void Event::setDatetime(unsigned long long &newDatetime) {
    datetime = newDatetime;
}

optional<unsigned long long> Event::getEndDate() {
    return endDate;
}

void Event::setEndDate(optional<unsigned long long> &newEndDate) {
    endDate = newEndDate;
}

bool Event::getWeekly() {
    return weekly;
}

void Event::setWeekly(bool newWeekly) {
    weekly = newWeekly;
}

QString Event::getURL(Action a)  {
    switch(a){
        case NetModel::ADD:
            return "/courses/"+courseID+"/events/add";
        case NetModel::MODIFY:
            return "/courses/"+courseID+"/events/"+id+"/modify";
        case NetModel::REMOVE:
            return "/courses/"+courseID+"/events/"+id+"/remove";
    }
    throw ActionException("none", "event");
}

map<QString, QString> *Event::getBody(Action a) {
    return new map<QString, QString>{
            {"id", id},
            {"course", courseID},
            {"name", name},
            {"type", type.toDB()},
            {"weight", QString::fromStdString(to_string(weight))},
            {"datetime", QString::fromStdString(to_string(datetime))},
            {"weekly", QString::fromStdString(to_string(weekly))},
            {"user", AuthController::instance()->getLocalUIDOptional().value_or("")}
    };
}