//
// Created by Greg on 2021-10-26.
//

#include <QJsonArray>
#include <net/api.h>
#include <net/subscriptions.h>

using namespace std;
using namespace net;

bool subscriptions::addSubscription(Course &course) {
    map <QString, QString> body {
            {"course", course.getId()}
    };

    auto req = APIRequest("/users/subscriptions/add", APIRequest::POST);
    // Just execute, since there's no useful data to handle
    req.setBody(body)
        -> execute();
    return true;
}

bool subscriptions::removeSubscription(QString &courseID) {
    // API is post endpoint, but body can be empty
    map<QString, QString> body = {};

    auto req = APIRequest("/users/subscriptions/"+courseID+"/remove", APIRequest::POST);
    // Just execute, since there's no useful data to handle
    req.setBody(body)
            -> execute();
    return true;
}

shared_ptr<vector<Course>> subscriptions::updateSubscriptions(unsigned long long lastModified) {
    map<QString, QString> params = {};
    // If lastModified is non-zero, add the filter to request
    if(lastModified){
        params.insert({"since", QString::fromStdString(to_string(lastModified))});
    }
    auto req = APIRequest("/users/subscriptions/get");
    req.setParameters(params)
        -> execute();
    auto courses = req.getResponse()->getPayload("courses").toArray();

    auto out = make_shared<vector<Course>>();

    for(auto c : courses){
        QJsonObject o = c.toObject();
        out->push_back(Course(o));
    }

    return out;
}

