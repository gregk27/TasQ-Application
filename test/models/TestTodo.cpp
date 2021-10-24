//
// Created by Greg on 2021-10-23.
//
#define CATCH_CONFIG_FAST_LINKING
#include <string>
#include <catch2/catch.hpp>
#include <models/Todo.h>
using namespace std;
using namespace models;
using json = nlohmann::json;

TEST_CASE("Todo constructor works", "[course]"){
    json j = {
            {"id","e3cb598d-2de8-11ec-a3fd-0023aea14009"},
            {"name","Testing"},
            {"user","71e04118-2dd7-11ec-a3fd-0023aea14009"},
            {"completed", true}
    };
    Todo t(j);
    REQUIRE(t.getId() == j["id"]);
    REQUIRE(t.getName() == j["name"]);
    REQUIRE(t.getCompleted() == j["completed"]);
}