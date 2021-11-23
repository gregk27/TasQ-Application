//
// Created by Greg on 2021-10-21.
//

#ifndef TASQ_APPLICATION_MODELS_H
#define TASQ_APPLICATION_MODELS_H

#include <string>
#include <QString>
#include <QJsonObject>
#include <utility>

/**
 * Classes and functions for handling data models
 */
namespace models {
    typedef QString uuid;

    class ModelBase {
    protected:
        uuid id;
        explicit ModelBase(uuid id) : id(std::move(id)) {};
    public:
        /**
         * Get the model's unique ID
        */
        uuid getId() const {
            return id;
        }
    };

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
