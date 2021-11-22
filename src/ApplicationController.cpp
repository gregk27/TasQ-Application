//
// Created by Greg on 2021-11-22.
//

#include <ApplicationController.h>
#include <net/schools.h>
#include <net/auth.h>
#include <models/Models.h>
#include <models/School.h>
#include <models/Course.h>

ApplicationController *ApplicationController::_instance = nullptr;

using namespace std;

ApplicationController::ApplicationController() {
    // Get the first school
    school = new School(net::schools::getSchools()->operator[](0));
    uuid sid = school->getId();
    auto cs = net::schools::getCourses(sid);
    // Populate with courses from school
    for(auto c : *cs){
        if(courses.count(c.getId())){
            *courses[c.getId()] = c;
        } else {
            courses.insert({c.getId(), new Course(c)});
        }
    }
}

ApplicationController::~ApplicationController(){
    delete school;
    courses.clear();
    events.clear();
}

ApplicationController *ApplicationController::instance() {
    if(_instance == nullptr)
        _instance = new ApplicationController();
    return _instance;
}

School *ApplicationController::getSchool() {
    return school;
}
