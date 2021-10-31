//
// Created by Greg on 2021-10-19.
//

#include <net/auth.h>
#include <optional>
#include <models/Course.h>
#include <models/User.h>
using namespace models;

Course::Course(json &json):
        term(enums::Term::fromDB(json["term"])) {
    id = json["id"];
    name = json["name"];
    code = json["code"];
    year = json["year"];
    prof = json["prof"];
    owner = json["owner"];
    schoolId = json["school"];
    modified = json["modified"];
}

uuid Course::getId() {
    return id;
}

string Course::getName() {
    return name;
}

void Course::setName(string &newName) {
    // TODO: Add database changes
    name = newName;
}

string Course::getCode() {
    return code;
}

void Course::setCode(string &newCode) {
    // TODO: Add database changes
    code = newCode;
}

unsigned short Course::getYear() {
    return year;
}

void Course::setYear(unsigned short &newYear) {
    // TODO: Add database changes
    year = newYear;
}

enums::Term Course::getTerm() {
    return term;
}

void Course::setTerm(enums::Term &newTerm) {
    // TODO: Add database changes
    term = newTerm;
}

string Course::getProf() {
    return prof;
}

void Course::setProf(string &newProf) {
    // TODO: Add database changes
    prof = newProf;
}

string Course::getOwner() {
    return owner;
}

uuid Course::getSchoolId() {
    return schoolId;
}

void Course::setSchoolId(uuid &newSchoolId) {
    // TODO: Add database changes
    schoolId = newSchoolId;
}

unsigned long long Course::getModified() {
    return modified;
}

string Course::getURL(Action a) {
    switch(a){
        case NetModel::ADD:
            return "/courses/add";
        case NetModel::MODIFY:
            return "/courses/"+id+"/modify";
        case NetModel::REMOVE:
            return "/courses/"+id+"/remove";
    }
    throw ActionException("none", "course");
}

map<string, string> *Course::getBody(Action a) {
    return new map<string, string> {
            {"name", name},
            {"code", code},
            {"year", to_string(year)},
            {"term", term.toDB()},
            {"prof", prof},
            {"owner", AuthController::instance()->getLocalUIDOptional().value_or("")},
            {"school", schoolId}
    };
}