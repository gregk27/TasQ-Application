//
// Created by Greg on 2021-10-26.
//

#include <net/api.h>
#include <net/subscriptions.h>

using namespace net;

bool subscriptions::addSubscription(Course &course) {
    map <string, string> body {
            {"course", course.getId()}
    };

    auto req = APIRequest("/users/subscriptions/add", APIRequest::POST);
    // Just execute, since there's no useful data to handle
    req.setBody(body)
        -> execute();
    return true;
}

bool subscriptions::removeSubscription(string &courseID) {
    // API is post endpoint, but body can be empty
    map<string, string> body = {};

    auto req = APIRequest("/users/subscriptions/"+courseID+"/remove", APIRequest::POST);
    // Just execute, since there's no useful data to handle
    req.setBody(body)
            -> execute();
    return true;
}

shared_ptr<vector<Course>> subscriptions::updateSubscriptions(unsigned long long lastModified) {
    map<string, string> params = {};
    // If lastModified is non-zero, add the filter to request
    if(lastModified){
        params.insert({"since", to_string(lastModified)});
    }
    auto req = APIRequest("/users/subscriptions/get");
    req.setParameters(params)
        -> execute();
    auto courses = req.getResponse()->getPayload("courses");

    auto out = make_shared<vector<Course>>();

    for(auto c : courses){
        out->push_back(Course(c));
    }

    return out;
}

