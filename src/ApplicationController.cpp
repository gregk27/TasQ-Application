//
// Created by Greg on 2021-11-22.
//

#include <thread>
#include <QTimer>
#include <ApplicationController.h>
#include <net/schools.h>
#include <net/auth.h>
#include <models/Models.h>
#include <models/School.h>
#include <models/Course.h>
#include <net/endpoints.h>
#include <net/subscriptions.h>

ApplicationController *ApplicationController::_instance = nullptr;

// Update the data every 15 minutes
const unsigned long long ApplicationController::UPDATE_INTERVAL = 15*60*1000;

using namespace std;

ApplicationController::ApplicationController() {
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &ApplicationController::update);
    timer->start(UPDATE_INTERVAL);

    // Update events and users whenever courses change
    connect(this, &ApplicationController::coursesChanged, [=] {
        std::thread t([=]{
            for(auto [cId, c] : courses){
                // Pull events for the user's courses
                auto es = *net::getEvents(*c);
                for(const auto &e : es){
                    insertOrUpdate<Event>( new Event(e));
                }
                // Get owners of the courses
                auto oId = c->getOwnerId();
                auto user = net::getUser(oId);
                // Create a new user instance since the shared_ptr will delete it
                insertOrUpdate<User>(new User(*user));
            }
            emitChange<Event>();
            emitChange<User>();
        });
        t.detach();
    });
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

bool ApplicationController::pullData(bool async) {
    // Can't pull data if the user isn't registered
    if(AuthController::instance()->getLocalUser() == nullptr || !APIController::instance()->getStatus()){
        return false;
    }
    std::thread t([=] {
        // Pull the user's courses
        auto subs = net::subscriptions::getSubscriptions();
        for(const auto& c : *subs){
            insertOrUpdate<Course>(new Course(c));
        }
        emit coursesChanged();

        // Pull user's reminders
        auto rs = *net::getReminders();
        for (const auto &r: rs) {
            insertOrUpdate<Reminder>(new Reminder(r));
        }
        // Pull user's to-dos
        auto ts = *net::getTodos();
        for(const auto &t : ts){
            insertOrUpdate<Todo>(new Todo(t));
        }

        emit remindersChanged();
        emit todosChanged();
    });

    if(!async) t.join();
    else t.detach();
    return true;
}

School *ApplicationController::getSchool() {
    return school;
}

void ApplicationController::subscribe(Course *c) {
    cout << c->getId().toStdString() << endl;
    net::subscriptions::addSubscription(*c);
    courses.insert(make_pair(c->getId(), c));
    emitChange<Course>();
    //TODO: Update local storage
}

void ApplicationController::unsubscribe(Course *c) {
    net::subscriptions::removeSubscription(*c);
    auto es = c->getEvents();
    for(auto e : es){
        events.erase(e->getId());
    }
    courses.erase(c->getId());
    emitChange<Course>();
    emitChange<Event>();
    //TODO: Update local storage
}
