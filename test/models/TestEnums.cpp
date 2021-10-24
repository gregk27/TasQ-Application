//
// Created by Greg on 2021-10-23.
//
#define CATCH_CONFIG_FAST_LINKING
#include <string>
#include <catch2/catch.hpp>
#include <models/Course.h>
using namespace std;
using namespace models::enums;
using json = nlohmann::json;

TEST_CASE("Winter term works", "[enums,term]") {
    Term t = Term::fromDB("Wint");
    REQUIRE(t.toDB() == "WINT");
    REQUIRE(t.toString() == "Winter");
    REQUIRE(t.toLetter() == 'W');
    REQUIRE(t == Term::WINTER);
}

TEST_CASE("Spring term works", "[enums,term]") {
    Term t = Term::fromDB("Spri");
    REQUIRE(t.toDB() == "SPRI");
    REQUIRE(t.toString() == "Spring");
    REQUIRE(t.toLetter() == 'S');
    REQUIRE(t == Term::SPRING);
}

TEST_CASE("Summer term works", "[enums,term]") {
    Term t = Term::fromDB("Summ");
    REQUIRE(t.toDB() == "SUMM");
    REQUIRE(t.toString() == "Summer");
    REQUIRE(t.toLetter() == 'S');
    REQUIRE(t == Term::SUMMER);
}

TEST_CASE("Fall term works", "[enums,term]") {
    Term t = Term::fromDB("Fall");
    REQUIRE(t.toDB() == "FALL");
    REQUIRE(t.toString() == "Fall");
    REQUIRE(t.toLetter() == 'F');
    REQUIRE(t == Term::FALL);
}

TEST_CASE("Lecture type works", "[enums,eventType]") {
    EventType e = EventType::fromDB("Lecture");
    REQUIRE(e.toDB() == "LECTURE");
    REQUIRE(e.toString() == "Lecture");
    REQUIRE(e == EventType::LECTURE);
}

TEST_CASE("Tutorial type works", "[enums,eventType]") {
    EventType e = EventType::fromDB("Tutorial");
    REQUIRE(e.toDB() == "TUTORIAL");
    REQUIRE(e.toString() == "Tutorial");
    REQUIRE(e == EventType::TUTORIAL);
}

TEST_CASE("Lab type works", "[enums,eventType]") {
    EventType e = EventType::fromDB("Lab");
    REQUIRE(e.toDB() == "LAB");
    REQUIRE(e.toString() == "Lab");
    REQUIRE(e == EventType::LAB);
}

TEST_CASE("Quiz type works", "[enums,eventType]") {
    EventType e = EventType::fromDB("Quiz");
    REQUIRE(e.toDB() == "QUIZ");
    REQUIRE(e.toString() == "Quiz");
    REQUIRE(e == EventType::QUIZ);
}

TEST_CASE("Assignment type works", "[enums,eventType]") {
    EventType e = EventType::fromDB("Assignment");
    REQUIRE(e.toDB() == "ASSIGNMENT");
    REQUIRE(e.toString() == "Assignment");
    REQUIRE(e == EventType::ASSIGNMENT);
}