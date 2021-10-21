//
// Created by Greg on 2021-10-19.
//

#include <models/Enums.h>

using namespace models::enums;

EnumValueException::EnumValueException(string str) {
    this->str = str;
}

const char *EnumValueException::what() const noexcept {
    return str.c_str();
}

//--------
//  TERM
//--------
const string Term::dbNames[] = {"WINT", "SPRI", "SUMM", "FALL"};
const string Term::prettyNames[] = {"Winter", "Spring", "Summer", "Fall"};

const char Term::letters[] = {'W', 'S', 'S', 'F'};
const Term Term::WINTER = Term(0);
const Term Term::SPRING = Term(1);
const Term Term::SUMMER = Term(2);


const Term Term::FALL = Term(3);

Term Term::fromDB(string s) {
    for (int i = 0; i < numTerms; i++) {
        if (s == dbNames[i])
            return Term(i);
    }
    throw new EnumValueException("Invalid term name " + s);
}

string Term::toDB() {
    return dbNames[val];
}

string Term::toString() {
    return prettyNames[val];
}

char Term::toLetter() {
    return letters[val];
}

//-------------
//  Event Type
//--------------
const string EventType::dbNames[] = {"LECTURE", "TUTORIAL", "LAB", "TEST", "QUIZ", "ASSIGNMENT"};
const string EventType::prettyNames[] = {"Lecture", "Tutorial", "Lab", "Test", "Quiz", "Assignment"};

EventType EventType::fromDB(string s) {
    for (int i = 0; i < numEventTypes; i++) {
        if (s == dbNames[i])
            return EventType(i);
    }
    throw new EnumValueException("Invalid event type " + s);
}

string EventType::toDB() {
    return dbNames[val];
}

string EventType::toString() {
    return prettyNames[val];
}

