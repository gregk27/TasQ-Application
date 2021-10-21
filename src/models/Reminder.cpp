//
// Created by Greg on 2021-10-19.
//

#include <models/Reminder.h>
using namespace models;

Reminder::Reminder(json &json) {
    id = json["id"];
    eventId = json["event"];
}

uuid Reminder::getId() {
    return id;
}

uuid Reminder::getEventId() {
    return eventId;
}