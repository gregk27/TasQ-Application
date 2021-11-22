//
// Created by Greg on 2021-10-21.
//

#ifndef TASQ_APPLICATION_MODELS_H
#define TASQ_APPLICATION_MODELS_H

#include <string>
#include <QString>
#include <QJsonObject>

/**
 * Classes and functions for handling data models
 */
namespace models {
    typedef QString uuid;

    // Forward-declare the classes to allow for circular reference
    class NetModel;
    class Course;
    class Event;
    class Reminder;
    class School;
    class ToDo;
    class User;

    namespace enums {
        class Term;
        class EventType;
    }

}
#endif //TASQ_APPLICATION_MODELS_H
