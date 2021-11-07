//
// Created by Greg on 2021-10-24.
//

#include <net/api.h>
#include <net/auth.h>
#include <net/endpoints.h>

using namespace std;
using namespace models;

shared_ptr<vector<Event>> net::getEvents(string &courseId) {
    auto req = APIRequest("/courses/"+courseId+"/events/get");
    req.execute();
    auto events = req.getResponse()->getPayload("events");

    auto out = make_shared<vector<Event>>();
    for(auto event : events){
        out->push_back(Event(event));
    }

    return out;
}

shared_ptr<vector<Todo>> net::getTodos(){
    auto req = APIRequest("/users/todos/get");
    req.execute();
    auto todos = req.getResponse()->getPayload("todos");

    auto out = make_shared<vector<Todo>>();

    for(auto t : todos){
        out->push_back(Todo(t));
    }

    return out;
}

shared_ptr<vector<Reminder>> net::getReminders(){
    auto req = APIRequest("/users/reminders/get");
    req.execute();
    auto reminders = req.getResponse()->getPayload("reminders");

    auto out = make_shared<vector<Reminder>>();

    for(auto t : reminders){
        out->push_back(Reminder(t));
    }

    return out;
}