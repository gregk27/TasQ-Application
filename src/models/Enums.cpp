//
// Created by Greg on 2021-10-19.
//

#include <models/Enums.h>
#include <algorithm>

using namespace std;
using namespace models::enums;

EnumValueException::EnumValueException(QString str) {
    this->str = str;
}

const char *EnumValueException::what() const noexcept {
    return str.toLocal8Bit().data();
}

//--------
//  TERM
//--------
const QString Term::dbNames[] = {"WINT", "SPRI", "SUMM", "FALL"};
const QString Term::prettyNames[] = {"Winter", "Spring", "Summer", "Fall"};

const char Term::letters[] = {'W', 'S', 'S', 'F'};
const Term Term::WINTER = Term(0);
const Term Term::SPRING = Term(1);
const Term Term::SUMMER = Term(2);
const Term Term::FALL = Term(3);

Term Term::fromDB(QString s) {
    // Convert input string to uppercase
    s = s.toUpper();
    for (int i = 0; i < numTerms; i++) {
        if (s == dbNames[i])
            return Term(i);
    }
    throw EnumValueException("Invalid term name " + s);
}

QString Term::toDB() const {
    return dbNames[val];
}

QString Term::toString() const {
    return prettyNames[val];
}

char Term::toLetter() const {
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
const QString EventType::dbNames[] = {"LECTURE", "TUTORIAL", "LAB", "TEST", "QUIZ", "ASSIGNMENT"};
const QString EventType::prettyNames[] = {"Lecture", "Tutorial", "Lab", "Test", "Quiz", "Assignment"};

const EventType EventType::LECTURE(0);
const EventType EventType::TUTORIAL(1);
const EventType EventType::LAB(2);
const EventType EventType::TEST(3);
const EventType EventType::QUIZ(4);
const EventType EventType::ASSIGNMENT(5);

EventType EventType::fromDB(QString s) {
    // Convert input string to uppercase
    s = s.toUpper();
    for (int i = 0; i < numEventTypes; i++) {
        if (s == dbNames[i])
            return EventType(i);
    }
    throw EnumValueException("Invalid event type " + s);
}

QString EventType::toDB() const {
    return dbNames[val];
}

QString EventType::toString() const {
    return prettyNames[val];
}

bool EventType::operator==(EventType other) const {
    return val == other.val;
}

bool EventType::operator!=(EventType other) const {
    return !operator==(other);
}