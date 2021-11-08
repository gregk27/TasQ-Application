//
// Created by Greg on 2021-10-19.
//

#include <models/School.h>
using namespace models;

QString School::getId() {
    return id;
}

QString School::getName() {
    return name;
}

School::School(QJsonValue &json) {
    id = json["id"].toString();
    name = json["name"].toString();
}
