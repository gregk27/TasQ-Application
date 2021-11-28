//
// Created by Greg on 2021-10-19.
//

#include <models/School.h>
using namespace std;
using namespace models;

QString School::getName() {
    return name;
}

School::School(QJsonValue &json)
    : ModelBase(json["id"].toString()){
    name = json["name"].toString();
}
