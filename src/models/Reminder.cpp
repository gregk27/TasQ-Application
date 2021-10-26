//
// Created by Greg on 2021-10-19.
//

#include <models/Reminder.h>
#include <models/User.h>

using namespace models;

// Forward declare localUser since cannot import auth
namespace net::auth {
    extern shared_ptr<User> localUser;
}

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

string Reminder::getURL(Action a) {
    switch(a){
        case NetModel::ADD:
            return "/users/"+net::auth::localUser->getId()+"/reminders/add";
        case NetModel::MODIFY:
            throw ActionException("modify", "reminder");
        case NetModel::REMOVE:
            return "/users/"+net::auth::localUser->getId()+"/reminders/"+id+"/remove";
    }
    throw ActionException("none", "reminder");
}

map<string, string> *Reminder::getBody(Action a) {
    if(a == Action::MODIFY)
        throw ActionException("modify", "reminder");
    return new map<string, string> {{"event", eventId}};
}