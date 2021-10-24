//
// Created by Greg on 2021-10-23.
//
#define CATCH_CONFIG_FAST_LINKING
#include <string>
#include <catch2/catch.hpp>
#include <models/School.h>
using namespace std;
using namespace models;
using json = nlohmann::json;

TEST_CASE("School constructor works", "[course]"){
    json j = {
            {"id","5cd83d02-2dcf-11ec-a3fd-0023aea14009"},
            {"name","Queen's"},
    };
    School s(j);
    REQUIRE(s.getId() == j["id"]);
    REQUIRE(s.getName() == j["name"]);
}