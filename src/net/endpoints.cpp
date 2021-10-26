//
// Created by Greg on 2021-10-24.
//

#include <net/auth.h>
#include <net/endpoints.h>

using namespace std;
using namespace models;

shared_ptr<vector<Event>> net::getEvents(string &courseId) {
    auto js = getAPI(BASE_URL+"/courses/"+courseId+"/events");

    auto out = make_shared<vector<Event>>();
    for(auto event : js["events"]){
        out->push_back(Event(event));
    }

    return out;
}

shared_ptr<vector<Todo>> net::getTodos(){
    auto js = getAPI(BASE_URL+"/users/"+auth::localUser->getId()+"/todos");

    auto out = make_shared<vector<Todo>>();

    for(auto t : js["todos"]){
        out->push_back(Todo(t));
    }

    return out;
}

shared_ptr<vector<Reminder>> net::getReminders(){
    auto js = getAPI(BASE_URL+"/users/"+auth::localUser->getId()+"/reminders");

    auto out = make_shared<vector<Reminder>>();

    for(auto t : js["reminders"]){
        out->push_back(Reminder(t));
    }

    return out;
}