//
// Created by Greg on 2021-10-26.
//

#include <net/net.h>
#include <net/auth.h>
#include <net/users.h>
#include <iostream>

using namespace net;

bool users::addSubscription(Course &course) {
    map <string, string> body {
            {"course", course.getId()}
    };
    // Just execute, since there's no useful data to handle
    postAPI(BASE_URL+"/users/"+auth::localUser->getId()+"/subscriptions/add", body);
    return true;
}

bool users::removeSubscription(string &courseID) {
    // API is post endpoint, but body can be empty
    map<string, string> body = {};
    postAPI(BASE_URL+"/users/"+auth::localUser->getId()+"/subscriptions/"+courseID+"/remove", body);
    return true;
}

shared_ptr<vector<Course>> users::updateSubscriptions(unsigned long long lastModified) {
    string url = BASE_URL+"/users/"+auth::localUser->getId()+"/subscriptions";
    // If lastModified is non-zero, add the filter to request
    if(lastModified){
        url += "?since="+to_string(lastModified);
    }
    auto js = getAPI(url);

    auto out = make_shared<vector<Course>>();

    for(auto c : js["courses"]){
        out->push_back(Course(c));
    }

    return out;
}
