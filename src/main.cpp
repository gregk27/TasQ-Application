#include <QApplication>
#include <QPushButton>
#include <widgets/MainWindow.h>
#include <net/net.h>
#include <iostream>
#include <string>
#include <nlohmann/json.hpp>

#include <models/School.h>
#include <models/User.h>
#include <net/auth.h>
#include <net/schools.h>
#include <net/endpoints.h>
#include <net/subscriptions.h>

using namespace std;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow window(nullptr);
    QPushButton button("Hello world!", &window);
    window.show();

    net::init();
    bool netStat = net::getStatus();
    if(netStat && AuthController::instance()->hasSession()) {
        auto u = AuthController::instance()->getLocalUser();
        cout << "Authenticated as " << u->getName() << ", token: " << AuthController::instance()->getSessionToken() << endl;
    } else {
        cout << "API connection failed" << endl;
    }

    auto schools = net::schools::getSchools();
    for(auto &school : *schools){
        cout << school.getName() << " " << school.getId() << endl;
        auto courses = *net::schools::getCourses(school);
        for(auto &course : courses){
            cout << course.getCode() << ":" << course.getName() << endl;
        }
    }

    nlohmann::json courseJSON = {
            {"id", ""}, // ID will be generated by database
            {"name", "Testing Course"},
            {"code", "TEST123"},
            {"year", 2021},
            {"term", enums::Term::FALL.toDB()},
            {"prof", "Brown"},
            {"owner", ""}, // Owner will be filled by backend
            {"school", "5cd83d02-2dcf-11ec-a3fd-0023aea14009"},
            {"modified", 0}
    };

    cout << "Creating course" << endl;
    Course tmp(courseJSON);

    auto c = net::addModel<Course>(tmp);

    cout << c->getId() << endl;

    string newName = "New Test Name";
    c->setName(newName);

    cout << "Updating course" << endl;
    c = net::modifyModel<Course>(*c);

    nlohmann::json eventJSON = {
            {"id", ""},
            {"course", c->getId()},
            {"name", "Test Event 1"},
            {"type", enums::EventType::TEST.toDB()},
            {"weight", 50},
            {"datetime", 1635177676L},
            {"weekly", 0}
    };

    cout << "Creating event" << endl;

    Event tmpEvent(eventJSON);
    auto e = net::addModel<Event>(tmpEvent);

    cout << "Updating event" << endl;
    string s = "Test event 1.5";
    e->setName(s);
    e = net::modifyModel<Event>(*e);

    eventJSON["name"] = "Test event 2";
    eventJSON["type"] = enums::EventType::LAB.toDB();
    eventJSON["endDate"] = 1635178676L;

    cout << "Creating second event" << endl;
    tmpEvent = Event(eventJSON);
    auto e2 = net::addModel<Event>(tmpEvent);

    cout << "Removing second event" << endl;
    net::removeModel<Event>(*e2);

    cout << "Getting events" << endl;
    auto events = net::getEvents(*c);
    for(auto event : *events){
        cout << event.getName() << endl;
    }

    cout << "Subscribing to c" << endl;
    net::subscriptions::addSubscription(*c);

    cout << "Getting subscriptions" << endl;
    auto subscribed = net::subscriptions::getSubscriptions();
    cout << subscribed->size() << endl;
    for(auto subCourse : *subscribed){
        cout << subCourse.getName() << endl;
    }

    cout << "Unsubscribing" << endl;
    net::subscriptions::removeSubscription(*c);

    cout << "Deleting course" << endl;
    net::removeModel<Course>(*c);

    return QApplication::exec();
}
