//
// Created by Greg on 2021-10-19.
//

#include <net/auth.h>
#include <optional>
#include <models/Course.h>
#include <models/User.h>
using namespace std;
using namespace models;

Course::Course(QJsonValue json):
        term(enums::Term::fromDB(json["term"].toString())) {
    id = json["id"].toString();
    name = json["name"].toString();
    code = json["code"].toString();
    year = json["year"].toInt();
    prof = json["prof"].toString();
    owner = json["owner"].toString();
    schoolId = json["school"].toString();
    modified = json["modified"].toInteger();
}

uuid Course::getId() {
    return id;
}

QString Course::getName() {
    return name;
}

void Course::setName(QString &newName) {
    // TODO: Add database changes
    name = newName;
}

QString Course::getCode() {
    return code;
}

void Course::setCode(QString &newCode) {
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

QString Course::getProf() {
    return prof;
}

void Course::setProf(QString &newProf) {
    // TODO: Add database changes
    prof = newProf;
}

QString Course::getOwner() {
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

QString Course::getURL(Action a) {
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

map<QString, QString> *Course::getBody(Action a) {
    return new map<QString, QString> {
            {"name", name},
            {"code", code},
            {"year", QString::fromStdString(to_string(year))},
            {"term", term.toDB()},
            {"prof", prof},
            {"owner", AuthController::instance()->getLocalUIDOptional().value_or("")},
            {"school", schoolId}
    };
}