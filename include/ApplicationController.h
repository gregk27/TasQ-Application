//
// Created by Greg on 2021-11-22.
//

#ifndef TASQ_APPLICATION_APPLICATIONCONTROLLER_H
#define TASQ_APPLICATION_APPLICATIONCONTROLLER_H

#include <unordered_map>
#include <QObject>
#include <QString>
#include <models/Models.h>

using namespace models;

/**
 * Singleton controller for application state/data
 */
class ApplicationController : public QObject {
    Q_OBJECT

private:
    /** Singleton instance of ApplicationController */
    static ApplicationController *_instance;

    ApplicationController();
    ~ApplicationController();

    School *school;
    std::unordered_map<uuid, Course*> courses;
    std::unordered_map<uuid, Event*> events;

public:
    static ApplicationController *instance();

    School *getSchool();

    std::unordered_map<uuid, Course*> getCourses();
    Course *getCourse(uuid courseID);

    void addCourse(Course *c);
    void modifyCourse(Course *c);
    void removeCourse(Course *c);

};


#endif //TASQ_APPLICATION_APPLICATIONCONTROLLER_H
