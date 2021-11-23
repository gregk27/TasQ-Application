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
        insertOrUpdate<Course>(new Course(c));
    }
    // Pull events for the user's courses
    for(auto [cId, c] : courses){
        auto es = *net::getEvents(*c);
        for(const auto &e : es){
            insertOrUpdate<Event>( new Event(e));
        }
        auto oId = c->getOwnerId();
        auto user = net::getUser(oId);
        // Create a new user instance since the shared_ptr will delete it
        insertOrUpdate<User>(new User(*user));
    }
    // Pull user's reminders
    auto rs = *net::getReminders();
    for(const auto &r : rs){
        insertOrUpdate<Reminder>(new Reminder(r));
    }
    // Pull user's to-dos
    auto ts = *net::getTodos();
    for(const auto &t : ts){
        insertOrUpdate<Todo>(new Todo(t));
    }

    emit coursesChanged();
    emit eventsChanged();
    emit remindersChanged();
    emit todosChanged();
    emit usersChanged();
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