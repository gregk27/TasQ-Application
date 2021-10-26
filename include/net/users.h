//
// Created by Greg on 2021-10-26.
//

#ifndef TASQ_APPLICATION_USERS_H
#define TASQ_APPLICATION_USERS_H

#include <models/User.h>
#include <models/Course.h>
#include <models/Todo.h>
#include <models/Reminder.h>

using namespace models;

/**
 * Namespace containing netcode for endpoints under /users/
 * Note that login and registers are under net::auth
 */
namespace net::users {

    /**
     * Subscribe to a new course
     * @param course Course to subscribe to
     * @return True if subscription is successful
     */
    bool addSubscription(Course &course);

    /**
     * Unsubscribe from a course
     * @param courseID ID of the course to unsubscribe from
     * @return True if unsubscription is successful
     */
    bool removeSubscription(string &courseID);
    /**
     * Unsubscribe from a course
     * @param course Course to unsubscribe from
     * @return True if unsubscription is successful
     * @see net::users::removeSubscription(string)
     */
    inline bool removeSubscription(Course &course){
        string id = course.getId();
        return removeSubscription(id);
    }

    /**
     * Get the subscribed courses modified after a timestamp
     * @param lastModified Timestamp to filter courses which have not been udpated
     * @return Vector of courses which have been updated
     */
    shared_ptr<vector<Course>> updateSubscriptions(unsigned long long lastModified);
    /**
     * Get the courses the current user is subscribed to
     * @return Vector of courses the user is subscribed to
     * @see net::users::updateSubscriptions(unsigned long long)
     */
    inline shared_ptr<vector<Course>> getSubscriptions() {
        return updateSubscriptions(0);
    }


    /**
     * Add a new to-do to database
     * @param name Name of to-do to be added
     * @return The to-do object returned by API
     */
    shared_ptr<Todo> addTodo(string &name);
    /**
     * Add a new to-do to database
     * @param t To-do data to be added. id and owner can be empty strings, will be set by function
     * @return The to-do object returned by API
     */
    inline shared_ptr<Todo> addTodo(Todo &t){
        string name = t.getName();
        return addTodo(name);
    }

    /**
     * Modify an existing to-do in database
     * @param t Updated data for to-do to be modified
     * @return The to-do object returned by API
     */
    shared_ptr<Todo> modifyTodo(Todo &t);
    /**
     * Delete a to-do in database
     * @param todoId ID of the to-do to delete
     * @return True on successful deletion
     */
    bool deleteTodo(string &todoID);
    /**
     * Delete a to-do in database
     * @param t Course to delete
     * @return True on successful deletion
     * @see net::to-dos::remove(string);
     */
    inline bool deleteTodo(Todo &t){
        string id = t.getId();
        return deleteTodo(id);
    }

    /**
     * Get todos for the local user
     * @return  vector with todos for local user
     */
    shared_ptr<vector<Todo>> getTodos();


    /**
     * Get reminders for local user
     * @return List of reminders for the course
     */
    shared_ptr<vector<Reminder>> getReminders();

    /**
     * Add an reminder for local user
     * @param reminder Reminder data to create from
     * @return The reminder object returned by API
     */
    shared_ptr<Reminder> addReminder(Reminder &reminder);

    /**
     * Delete reminder in database
     * @param reminderId ID of the reminder to delete
     * @param courseId ID of the reminder's course
     * @return True on success
     */
    bool removeReminder(string &reminderId);
    /**
     * Delete reminder in database
     * @param reminder Reminder to delete
     * @return True on success
     */
    inline bool removeReminder(Reminder &reminder){
        string reminderId = reminder.getId();
        return removeReminder(reminderId);
    }
}

#endif //TASQ_APPLICATION_USERS_H
