//
// Created by Greg on 2021-10-17.
//

#include <models/User.h>

using namespace models;

User::User(json &json) {
    id = json["id"];
    name = json["name"];
    schoolId = json["school"];
}

uuid User::getId() {
    return id;
}

string User::getName() {
    return name;
}

void User::setName(string &newName) {
    // TODO: Add database changes
    name = newName;
}

uuid User::getSchoolId() {
    return schoolId;
}

void User::setSchoolId(uuid &newId) {
    // TODO: Add database changes
    schoolId = newId;
}