//
// Created by Greg on 2021-10-23.
//
#define CATCH_CONFIG_FAST_LINKING
#include <string>
#include <catch2/catch.hpp>
#include <models/Course.h>
using namespace std;
using namespace models;
using json = nlohmann::json;

TEST_CASE("Course constructor works", "[course]"){
    json j = {
            {"id","16c6bddb-2de2-11ec-a3fd-0023aea14009"},
            {"name","Software Dev"},
            {"code","cmpe320"},
            {"year",2021},
            {"term","Fall"},
            {"prof","El Mezouar"},
            {"owner","71e04118-2dd7-11ec-a3fd-0023aea14009"},
            {"school","5cd83d02-2dcf-11ec-a3fd-0023aea14009"},
            {"modified", 1635044502}
    };
    Course c(j);
    REQUIRE(c.getId() == j["id"]);
    REQUIRE(c.getName() == j["name"]);
    REQUIRE(c.getCode() == j["code"]);
    REQUIRE(c.getYear() == j["year"]);
    REQUIRE(c.getTerm() == enums::Term::fromDB(j["term"]));
    REQUIRE(c.getProf() == j["prof"]);
    REQUIRE(c.getOwner() == j["owner"]);
    REQUIRE(c.getSchoolId() == j["school"]);
    REQUIRE(c.getModified() == j["modified"]);
}