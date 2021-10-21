//
// Created by Greg on 2021-10-19.
//
#include <models/Event.h>

using namespace models;

Event::Event(json &json):
        type(enums::EventType::fromDB(json["type"])) {
    id = json["id"];
    courseID = json["course"];
    name = json["name"];
    weight = json["weight"];
    datetime = json["datetime"];
    endDate = json["endDate"];
    weekly = json["weekly"];
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
    return getEndDate();
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