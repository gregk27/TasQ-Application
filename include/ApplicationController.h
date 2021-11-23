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
    std::unordered_map<uuid, Reminder*> reminders;
    std::unordered_map<uuid, ToDo*> todos;
    std::unordered_map<uuid, User*> users;

    /**
     * Get the map associated with a specific type
     *
     * @throw runtime exception if type not supported
     * @return map if type is supported
     */
    template<typename T>
    inline std::unordered_map<uuid, T*> &getMap() { throw std::runtime_error("Type not supported"); }

    template<typename T>
    inline void emitChange() { };

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
        emitChange<T>();
        // TODO: Update database and local storage
    }
    template<class T>
    void modifyInstance(T *i){
        getMap<T>()[i->getId()] = *i;
        emitChange<T>();
        // TODO: Update database and local storage
    }
    template<class T>
    void removeInstance(T *i){
        getMap<T>().erase(i->getId());
        emitChange<T>();
        // TODO: Update database subscription and local storage
        delete i;
    }

public slots:
    void unsubscribe(Course *c);
    void subscribe(Course *c);

signals:
    void coursesChanged();
    void eventsChanged();
    void remindersChanged();
    void todosChanged();
    void usersChanged();
};

template<> inline std::unordered_map<uuid, Course*> &ApplicationController::getMap<Course>() { return courses; }
template<> inline std::unordered_map<uuid, Event*> &ApplicationController::getMap<Event>() { return events; }
template<> inline std::unordered_map<uuid, Reminder*> &ApplicationController::getMap<Reminder>() { return reminders; }
template<> inline std::unordered_map<uuid, ToDo*> &ApplicationController::getMap<ToDo>() { return todos; }
template<> inline std::unordered_map<uuid, User*> &ApplicationController::getMap<User>() { return users; }

template<> inline void ApplicationController::emitChange<Course>() { emit coursesChanged(); }
template<> inline void ApplicationController::emitChange<Event>() { emit eventsChanged(); }
template<> inline void ApplicationController::emitChange<Reminder>() { emit remindersChanged(); }
template<> inline void ApplicationController::emitChange<ToDo>() { emit todosChanged(); }
template<> inline void ApplicationController::emitChange<User>() { emit usersChanged(); }

#endif //TASQ_APPLICATION_APPLICATIONCONTROLLER_H
