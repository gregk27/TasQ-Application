//
// Created by Greg on 2021-10-19.
//

#include "Todo.h"
using namespace models;

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