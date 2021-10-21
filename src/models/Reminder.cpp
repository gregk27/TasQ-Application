//
// Created by Greg on 2021-10-19.
//

#include <models/Reminder.h>
using namespace models;

uuid Reminder::getId() {
    return id;
}

uuid Reminder::getEventId() {
    return eventId;
}