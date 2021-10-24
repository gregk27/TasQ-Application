//
// Created by Greg on 2021-10-23.
//
#define CATCH_CONFIG_FAST_LINKING
#include <string>
#include <catch2/catch.hpp>
#include <models/Reminder.h>
using namespace std;
using namespace models;
using json = nlohmann::json;

TEST_CASE("Reminder constructor works", "[course]"){
    json j = {
            {"id","dcd4201a-2e24-11ec-a3fd-0023aea14009"},
            {"event","339ea336-2e1f-11ec-a3fd-0023aea14009"},
    };
    Reminder r(j);
    REQUIRE(r.getId() == j["id"]);
    REQUIRE(r.getEventId() == j["event"]);
}