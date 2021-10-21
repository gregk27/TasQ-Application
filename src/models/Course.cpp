//
// Created by Greg on 2021-10-19.
//

#include <models/Course.h>
using namespace models;

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