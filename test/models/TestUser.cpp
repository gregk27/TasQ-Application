//
// Created by Greg on 2021-10-21.
//
#define CATCH_CONFIG_MAIN
#include <string>
#include <catch2/catch.hpp>
#include <models/User.h>

using namespace std;
using namespace models;
using json = nlohmann::json;

TEST_CASE("User constructor works", "[user]"){
    json j = {
            {"id","71e04118-2dd7-11ec-a3fd-0023aea14009"},
            {"name","Test user"},
            {"email","test@example.com"},
            {"school","5cd83d02-2dcf-11ec-a3fd-0023aea14009"}
    };
    User u(j);
    REQUIRE(u.getId() == j["id"]);
    REQUIRE(u.getName() == j["name"]);
    REQUIRE(u.getEmail() == j["email"]);
    REQUIRE(u.getSchoolId() == j["school"]);
}
