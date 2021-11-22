//
// Created by Greg on 2021-10-19.
//

#include <models/Todo.h>
#include <models/User.h>
using namespace std;
using namespace models;


Todo::Todo(QJsonValue &json) {
    id = json["id"].toString();
    name = json["name"].toString();
    completed = json["completed"].toBool();
}

uuid Todo::getId() {
    return id;
}

QString Todo::getName() {
    return name;
}

void Todo::setName(QString &newName) {
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

QString Todo::getURL(Action a) {
    switch(a){
        case NetModel::ADD:
            return "/users/todos/add";
        case NetModel::MODIFY:
            return "/users/todos/"+id+"/modify";
        case NetModel::REMOVE:
            return "/users/todos/"+id+"/remove";
    }
    throw ActionException("none", "todo");
}

map<QString, QString> *Todo::getBody(Action a) {
    return new map<QString, QString>{
            {"name", name},
            {"completed0", QString::fromStdString(to_string(completed))}
    };
}