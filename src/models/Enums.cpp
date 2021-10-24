//
// Created by Greg on 2021-10-19.
//

#include <models/Enums.h>
#include <algorithm>

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
    // Convert input string to uppercase
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    for (int i = 0; i < numTerms; i++) {
        if (s == dbNames[i])
            return Term(i);
    }
    throw EnumValueException("Invalid term name " + s);
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

bool Term::operator==(Term other) const {
    return val == other.val;
}

bool Term::operator!=(Term other) const {
    return !operator==(other);
}

//-------------
//  Event Type
//--------------
const string EventType::dbNames[] = {"LECTURE", "TUTORIAL", "LAB", "TEST", "QUIZ", "ASSIGNMENT"};
const string EventType::prettyNames[] = {"Lecture", "Tutorial", "Lab", "Test", "Quiz", "Assignment"};

const EventType EventType::LECTURE(0);
const EventType EventType::TUTORIAL(1);
const EventType EventType::LAB(2);
const EventType EventType::TEST(3);
const EventType EventType::QUIZ(4);
const EventType EventType::ASSIGNMENT(5);

EventType EventType::fromDB(string s) {
    // Convert input string to uppercase
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    for (int i = 0; i < numEventTypes; i++) {
        if (s == dbNames[i])
            return EventType(i);
    }
    throw EnumValueException("Invalid event type " + s);
}

string EventType::toDB() {
    return dbNames[val];
}

string EventType::toString() {
    return prettyNames[val];
}

bool EventType::operator==(EventType other) const {
    return val == other.val;
}

bool EventType::operator!=(EventType other) const {
    return !operator==(other);
}