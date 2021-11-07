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
#include <net/api.h>

using namespace net;

shared_ptr<vector<School>> schools::getSchools() {
    auto req = APIRequest("/schools/get");
    req.execute();
    auto schools = req.getResponse()->getPayload("schools");

    auto *out = new vector<School>;
    for(auto school : schools){
        out->push_back(School(school));
    }

    return shared_ptr<vector<School>>(out);
}

shared_ptr<vector<Course>> schools::getCourses(string &schoolId){
    auto req = APIRequest("/schools/" + schoolId + "/courses/get");
    req.execute();
    auto courses = req.getResponse()->getPayload("courses");

    auto *out = new vector<Course>;
    for(auto course : courses){
        out->push_back(Course(course));
    }

    return shared_ptr<vector<Course>>(out);
}