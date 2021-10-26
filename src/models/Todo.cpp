//
// Created by Greg on 2021-10-19.
//

#include <models/Todo.h>
#include <models/User.h>
using namespace models;

// Forward declare localUser since cannot import auth
namespace net::auth {
    extern shared_ptr<User> localUser;
}

Todo::Todo(json &json) {
    id = json["id"];
    name = json["name"];
    completed = json["completed"];
}

uuid Todo::getId() {
    return id;
}

string Todo::getName() {
    return name;
}

void Todo::setName(string &newName) {
    // TODO: Add database changes
    name = newName;
}

bool Todo::getCompleted() {
    return completed;
}

void Todo::setCompleted(bool newCompleted) {
    // TODO: Add database changes
    completed = newCompleted;
}

string Todo::getURL(Action a) {
    switch(a){
        case NetModel::ADD:
            return "/users/"+net::auth::localUser->getId()+"/todos/add";
        case NetModel::MODIFY:
            return "/users/"+net::auth::localUser->getId()+"/todos/"+id+"/modify";
        case NetModel::REMOVE:
            return "/users/"+net::auth::localUser->getId()+"/todos/"+id+"/remove";
    }
    throw ActionException("none", "todo");
}

map<string, string> *Todo::getBody(Action a) {
    return new map<string, string>{
            {"name", name},
            {"completed", to_string(completed)}
    };
}