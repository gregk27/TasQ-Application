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

    auto js = postJSON(BASE_URL+"/courses/add", body);

    if(!js["success"])
        throw APIResponseException("/courses/add", js["error"]);

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

    auto js = postJSON(BASE_URL+"/courses/"+course.getId()+"/modify", body);

    if(!js["success"])
        throw APIResponseException("/courses/"+course.getId()+"/modify", js["error"]);

    cout << js << endl;
    return std::make_shared<Course>(js["course"]);
}

bool courses::remove(string &courseId) {
    if(auth::localUser == nullptr) throw auth::AuthException("create a course");
    map<string, string> body {
            {"owner", auth::localUser->getId()},
    };

    auto js = postJSON(BASE_URL+"/courses/"+courseId+"/remove", body);

    if(!js["success"])
        throw APIResponseException("/courses/"+courseId+"/remove", js["error"]);

    return js["success"];
}
