//
// Created by Greg on 2021-10-24.
//

//
// Created by Greg on 2021-10-24.
//

#include <string>
#include <iostream>
#include <net/net.h>
#include <net/schools.h>

using namespace net;

shared_ptr<vector<School>> schools::getSchools() {
    auto js = getAPI(BASE_URL+"/schools/get");

    auto *out = new vector<School>;
    for(auto school : js["schools"]){
        out->push_back(School(school));
    }

    return shared_ptr<vector<School>>(out);
}

shared_ptr<vector<Course>> schools::getCourses(string &schoolId){
    auto js = getAPI(BASE_URL + "/schools/" + schoolId + "/courses");

    auto *out = new vector<Course>;
    for(auto course : js["courses"]){
        out->push_back(Course(course));
    }

    return shared_ptr<vector<Course>>(out);
}