//
// Created by Greg on 2021-10-24.
//

#include <QJsonArray>
#include <net/api.h>
#include <net/auth.h>
#include <net/endpoints.h>

using namespace std;
using namespace models;

shared_ptr<vector<Event>> net::getEvents(QString &courseId) {
    auto req = APIRequest("/courses/"+courseId+"/events/get");
    req.execute();
    auto events = req.getResponse()->getPayload("events").toArray();

    auto out = make_shared<vector<Event>>();
    for(auto event : events){
        QJsonObject o = event.toObject();
        out->push_back(Event(o));
    }

    return out;
}

shared_ptr<vector<Todo>> net::getTodos(){
    auto req = APIRequest("/users/todos/get");
    req.execute();
    auto todos = req.getResponse()->getPayload("todos").toArray();

    auto out = make_shared<vector<Todo>>();

    for(auto t : todos){
        QJsonObject o = t.toObject();
        out->push_back(Todo(o));
    }

    return out;
}

shared_ptr<vector<Reminder>> net::getReminders(){
    auto req = APIRequest("/users/reminders/get");
    req.execute();
    auto reminders = req.getResponse()->getPayload("reminders").toArray();

    auto out = make_shared<vector<Reminder>>();

    for(auto r : reminders){
        QJsonObject o = r.toObject();
        out->push_back(Reminder(o));
    }

    return out;
}