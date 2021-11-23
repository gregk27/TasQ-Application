//
// Created by Greg on 2021-11-22.
//

#include <ApplicationController.h>
#include <net/schools.h>
#include <net/auth.h>
#include <models/Models.h>
#include <models/School.h>
#include <models/Course.h>
#include <net/endpoints.h>
#include <net/subscriptions.h>

ApplicationController *ApplicationController::_instance = nullptr;

using namespace std;

ApplicationController::ApplicationController() {
}

ApplicationController::~ApplicationController(){
    delete school;
    courses.clear();
    events.clear();
}

ApplicationController *ApplicationController::instance() {
    if(_instance == nullptr)
        _instance = new ApplicationController();
    return _instance;
}

void ApplicationController::pullData() {
    // Can't pull data if the user isn't registered
    if(AuthController::instance()->getLocalUser() == nullptr){
        return;
    }
    // Pull the user's courses
    auto subs = net::subscriptions::getSubscriptions();
    for(const auto& c : *subs){
        courses.insert({c.getId(), new Course(c)});
    }
    // Pull events for the user's courses
    for(auto [cId, c] : courses){
        for(const auto &e : *net::getEvents(*c)){
            events.insert({e.getId(), new Event(e)});
        }
    }
    // Pull user's reminders
    for(const auto &r : *net::getReminders()){
        reminders.insert({r.getId(), new Reminder(r)});
    }
    // Pull user's to-dos
    for(const auto &t : *net::getTodos()){
        todos.insert({t.getId(), new Todo(t)});
    }
}

School *ApplicationController::getSchool() {
    return school;
}

void ApplicationController::unsubscribe(Course *c) {
    courses.insert(make_pair(c->getId(), c));
    emitChange<Course>();
    net::subscriptions::removeSubscription(*c);
    //TODO: Update local storage
}

void ApplicationController::subscribe(Course *c) {
    courses.erase(c->getId());
    emitChange<Course>();
    net::subscriptions::addSubscription(*c);
    //TODO: Update local storage
}