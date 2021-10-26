//
// Created by Greg on 2021-10-26.
//

#include <net/net.h>
#include <net/auth.h>
#include <net/users.h>
#include <iostream>

using namespace net;

bool users::addSubscription(Course &course) {
    map <string, string> body {
            {"course", course.getId()}
    };
    // Just execute, since there's no useful data to handle
    postAPI(BASE_URL+"/users/"+auth::localUser->getId()+"/subscriptions/add", body);
    return true;
}

bool users::removeSubscription(string &courseID) {
    // API is post endpoint, but body can be empty
    map<string, string> body = {};
    postAPI(BASE_URL+"/users/"+auth::localUser->getId()+"/subscriptions/"+courseID+"/remove", body);
    return true;
}

shared_ptr<vector<Course>> users::updateSubscriptions(unsigned long long lastModified) {
    string url = BASE_URL+"/users/"+auth::localUser->getId()+"/subscriptions";
    // If lastModified is non-zero, add the filter to request
    if(lastModified){
        url += "?since="+to_string(lastModified);
    }
    auto js = getAPI(url);

    auto out = make_shared<vector<Course>>();

    for(auto c : js["courses"]){
        out->push_back(Course(c));
    }

    return out;
}

shared_ptr<Todo> users::addTodo(string &name){
    map<string, string> body {
            {"name", name}
    };

    auto js = postAPI(BASE_URL+"/users/"+auth::localUser->getId()+"/todos/add", body);

    return make_shared<Todo>(js["todo"]);
}

shared_ptr<Todo> modifyTodo(Todo &t){
    map<string, string> body {
            {"name", t.getName()},
            {"completed", to_string(t.getCompleted())}
    };

    auto js = postAPI(BASE_URL+"/users/"+auth::localUser->getId()+"/todos/"+t.getId()+"/modify", body);

    return make_shared<Todo>(js["todo"]);
}

bool deleteTodo(string &todoID){
    // API is post endpoint, but body can be empty
    map<string, string> body = {};
    postAPI(BASE_URL+"/users/"+auth::localUser->getId()+"/todos/"+todoID+"/remove", body);
    return true;
}

shared_ptr<vector<Todo>> users::getTodos(){
    auto js = getAPI(BASE_URL+"/users/"+auth::localUser->getId()+"/todos");

    auto out = make_shared<vector<Todo>>();

    for(auto t : js["todos"]){
        out->push_back(Todo(t));
    }

    return out;
}

shared_ptr<Reminder> users::addReminder(Reminder &reminder){
    map<string, string> body {
            {"event", reminder.getEventId()}
    };

    auto js = postAPI(BASE_URL+"/users/"+auth::localUser->getId()+"/reminders/add", body);

    return make_shared<Reminder>(js["reminder"]);
}

bool deleteReminder(string &reminderID){
    // API is post endpoint, but body can be empty
    map<string, string> body = {};
    postAPI(BASE_URL+"/users/"+auth::localUser->getId()+"/reminders/"+reminderID+"/remove", body);
    return true;
}

shared_ptr<vector<Reminder>> users::getReminders(){
    auto js = getAPI(BASE_URL+"/users/"+auth::localUser->getId()+"/reminders");

    auto out = make_shared<vector<Reminder>>();

    for(auto t : js["reminders"]){
        out->push_back(Reminder(t));
    }

    return out;
}