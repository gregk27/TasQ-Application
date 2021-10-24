//
// Created by Greg on 2021-10-23.
//
#include <string>
#include <catch2/catch.hpp>
#include <models/Event.h>
#include <iostream>

using namespace std;
using namespace models;
using json = nlohmann::json;

TEST_CASE("Event constructor works", "[event]"){
    // Basic json to use
    json j = {
        {"id","339ea336-2e1f-11ec-a3fd-0023aea14009"},
        {"name","Assignment 1"},
        {"type","ASSIGNMENT"},
        {"course","16c6bddb-2de2-11ec-a3fd-0023aea14009"},
        {"weight",15},
        {"datetime",1635044502},
        {"endDate",1635045502},
        {"weekly",false}
    };
    Event *c;

    SECTION("End date is set"){
        c = new Event(j);
    }
    SECTION("End date not set"){
        j["endDate"] = nullptr;
        c = new Event(j);
    }

    // Validate values
    REQUIRE(c->getId() == j["id"]);
    REQUIRE(c->getName() == j["name"]);
    REQUIRE(c->getType() == enums::EventType::fromDB(j["type"]));
    REQUIRE(c->getCourseID() == j["course"]);
    REQUIRE(c->getWeight() == j["weight"]);
    REQUIRE(c->getDatetime() == j["datetime"]);
    if(j["endDate"].is_null()){
        REQUIRE(!c->getEndDate().has_value());
    } else {
        REQUIRE(c->getEndDate().value() == j["endDate"]);
    }
    REQUIRE(c->getWeekly() == j["weekly"]);

    delete c;
}