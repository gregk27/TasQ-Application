//
// Created by Greg on 2021-10-19.
//

#include <models/School.h>
using namespace models;

string School::getName() {
    return name;
}

School::School(json &json) {
    id = json["id"];
    name = json["name"];
}
