//
// Created by Greg on 2021-10-24.
//

//
// Created by Greg on 2021-10-24.
//

#include <string>
#include <iostream>
#include <QJsonArray>
#include <net/net.h>
#include <net/schools.h>
#include <net/api.h>

using namespace net;

shared_ptr<vector<School>> schools::getSchools() {
    auto req = APIRequest("/schools/get");
    req.execute();
    auto schools = req.getResponse()->getPayload("schools").toArray();

    auto *out = new vector<School>;
    for(auto school : schools){
        QJsonObject o = school.toObject();
        out->push_back(School(o));
    }

    return shared_ptr<vector<School>>(out);
}

shared_ptr<vector<Course>> schools::getCourses(QString &schoolId){
    auto req = APIRequest("/schools/" + schoolId + "/courses/get");
    req.execute();
    auto courses = req.getResponse()->getPayload("courses").toArray();

    auto *out = new vector<Course>;
    for(auto course : courses){
        QJsonObject o = course.toObject();
        out->push_back(Course(o));
    }

    return shared_ptr<vector<Course>>(out);
}