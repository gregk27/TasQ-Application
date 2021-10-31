//
// Created by Greg on 2021-10-19.
//
#include <optional>
#include <models/Event.h>
#include <models/User.h>

using namespace models;

// Forward declare localUID since cannot import auth
namespace net::auth {
    extern optional<string> localUID;
}

Event::Event(json &json):
        type(enums::EventType::fromDB(json["type"])) {
    id = json["id"];
    courseID = json["course"];
    name = json["name"];
    weight = json["weight"];
    datetime = json["datetime"];
    if(json["endDate"].is_null()){
        endDate = {};
    } else {
        endDate = json["endDate"];
    }
    weekly = (int) json["weekly"];
}

uuid Event::getId() {
    return id;
}

uuid Event::getCourseID() {
    return courseID;
}

void Event::setCourseID(uuid &newCourseID) {
    // TODO: Add database changes
    courseID = newCourseID;
}

string Event::getName() {
    return name;
}

void Event::setName(string &newName) {
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
    weekly = weekly;
}

string Event::getURL(Action a)  {
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

map<string, string> *Event::getBody(Action a) {
    return new map<string, string>{
            {"id", id},
            {"course", courseID},
            {"name", name},
            {"type", type.toDB()},
            {"weight", to_string(weight)},
            {"datetime", to_string(datetime)},
            {"weekly", to_string(weekly)},
    };
}