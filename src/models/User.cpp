//
// Created by Greg on 2021-10-17.
//

#include <models/User.h>

using namespace std;
using namespace models;

User::User(QJsonValue &json) {
    id = json["id"].toString();
    name = json["name"].toString();
    schoolId = json["school"].toString();
}

uuid User::getId() {
    return id;
}

QString User::getName() {
    return name;
}

void User::setName(QString &newName) {
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