//
// Created by Greg on 2021-10-24.
//

#include <map>
#include <net/courses.h>
#include <net/auth.h>
#include <iostream>

using namespace std;
using namespace net;

shared_ptr<Course> courses::add(Course &course) {
    if(auth::localUser == nullptr) throw auth::AuthException("create a course");
    map<string, string> body {
            {"name", course.getName()},
            {"code", course.getCode()},
            {"year", to_string(course.getYear())},
            {"term", course.getTerm().toDB()},
            {"prof", course.getProf()},
            {"owner", auth::localUser->getId()},
            {"school", course.getSchoolId()}
    };

    auto js = postAPI(BASE_URL+"/courses/add", body);

    return std::make_shared<Course>(js["course"]);;
}

shared_ptr<Course> courses::modify(Course &course) {
    if(auth::localUser == nullptr) throw auth::AuthException("create a course");
    map<string, string> body {
            {"name", course.getName()},
            {"code", course.getCode()},
            {"year", to_string(course.getYear())},
            {"term", course.getTerm().toDB()},
            {"prof", course.getProf()},
            {"owner", auth::localUser->getId()},
            {"school", course.getSchoolId()}
    };

    auto js = postAPI(BASE_URL+"/courses/"+course.getId()+"/modify", body);

    return std::make_shared<Course>(js["course"]);
}

bool courses::remove(string &courseId) {
    if(auth::localUser == nullptr) throw auth::AuthException("create a course");
    map<string, string> body {
            {"owner", auth::localUser->getId()},
    };

    auto js = postAPI(BASE_URL+"/courses/"+courseId+"/remove", body);

    return js["success"];
}

shared_ptr<vector<Event>> courses::getEvents(string &courseId) {
    auto js = getAPI(BASE_URL+"/courses/"+courseId+"/events");

    auto out = make_shared<vector<Event>>();
    for(auto event : js["events"]){
        out->push_back(Event(event));
    }

    return out;
}

shared_ptr<Event> courses::addEvent(Event &event) {
    map<string, string> body {
            {"id", event.getId()},
            {"course", event.getCourseID()},
            {"name", event.getName()},
            {"type", event.getType().toDB()},
            {"weight", to_string(event.getWeight())},
            {"datetime", to_string(event.getDatetime())},
            {"weekly", to_string(event.getWeekly())},
            {"user", auth::localUser->getId()}
    };

    if(event.getEndDate().has_value()){
        cout << "End date " << event.getEndDate().value() << endl;
        body.insert({"endDate", to_string(event.getEndDate().value())});
    }

    auto js = postAPI(BASE_URL+"/courses/"+event.getCourseID()+"/events/add", body);

    return make_shared<Event>(js["event"]);
}

shared_ptr<Event> courses::modifyEvent(Event &event) {
    map<string, string> body {
            {"course", event.getCourseID()},
            {"name", event.getName()},
            {"type", event.getType().toDB()},
            {"weight", to_string(event.getWeight())},
            {"datetime", to_string(event.getDatetime())},
            {"weekly", to_string(event.getWeekly())},
            {"user", auth::localUser->getId()}
    };

    if(event.getEndDate().has_value()){
        cout << "End date " << event.getEndDate().value() << endl;
        body.insert({"endDate", to_string(event.getEndDate().value())});
    }

    auto js = postAPI(BASE_URL+"/courses/"+event.getCourseID()+"/events/"+event.getId()+"/modify", body);

    return make_shared<Event>(js["event"]);
}

bool courses::removeEvent(string &eventId, string &courseId) {
    map<string, string> body {
            {"user", auth::localUser->getId()}
    };

    return postAPI(BASE_URL+"/courses/"+courseId+"/events/"+eventId+"/remove", body)["success"];
}