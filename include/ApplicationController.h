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
    ~ApplicationController() override;

    School *school;
    std::unordered_map<uuid, Course*> courses;
    std::unordered_map<uuid, Event*> events;

    /**
     * Get the map associated with a specific type
     *
     * @throw runtime exception if type not supported
     * @return map if type is supported
     */
    template<typename T>
    inline std::unordered_map<uuid, T*> &getMap() { throw std::runtime_error("Type not supported"); }

public:
    static ApplicationController *instance();

    School *getSchool();

    template<class T>
    std::unordered_map<uuid, T*> getInstances(){
        return getMap<T>();
    }

    template<class T>
    T *getInstance(uuid id){
        auto map = getMap<T>();
        if(map.count(id))
            return map[id];
        return nullptr;
    }

    template<class T>
    void addInstance(T *i){
        getMap<T>().insert(make_pair(i->getId(), i));
        // TODO: Update database and local storage
    }
    template<class T>
    void modifyInstance(T *i){
        getMap<T>()[i->getId()] = *i;
        // TODO: Update database and local storage
    }
    template<class T>
    void removeInstance(T *i){
        getMap<T>().erase(i->getId());
        // TODO: Update database subscription and local storage
        delete i;
    }

};

template<> inline std::unordered_map<uuid, Course*> &ApplicationController::getMap<Course>() { return courses; }
template<> inline std::unordered_map<uuid, Event*> &ApplicationController::getMap<Event>() { return events; }


#endif //TASQ_APPLICATION_APPLICATIONCONTROLLER_H
