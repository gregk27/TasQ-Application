//
// Created by Greg on 2021-10-19.
//

#include "Term.h"

using namespace models;

const string Term::dbNames[] = {"WINT", "SPRI", "SUMM", "FALL"};
const string Term::prettyNames[] = {"Winter", "Spring", "Summer", "Fall"};
const char Term::letters[] = {'W', 'S', 'S', 'F'};

const Term Term::WINTER = Term(0);
const Term Term::SPRING = Term(1);
const Term Term::SUMMER = Term(2);
const Term Term::FALL = Term(3);

Term Term::fromDB(string &s) {
    for (int i = 0; i < numTerms; i++) {
        if (s == dbNames[i])
            return Term(i);
    }
    throw new InvalidTermException("Invalid term name "+s);
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

InvalidTermException::InvalidTermException(string str) {
    this->str = str;
}

const char *InvalidTermException::what() const noexcept {
    return str.c_str();
}