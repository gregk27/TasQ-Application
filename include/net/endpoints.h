//
// Created by Greg on 2021-10-26.
//

#ifndef TASQ_APPLICATION_ENDPOINTS_H
#define TASQ_APPLICATION_ENDPOINTS_H

#include <net/net.h>
#include <models/Event.h>
#include <models/Course.h>
#include <models/Reminder.h>
#include <models/Todo.h>

// Assorted endpoints that are not handled elsewhere
// Separated from main netcode to keep things clean

using namespace models;

namespace net {
    /**
     * Get events for a course
     * @param courseId ID of the desired course
     * @return List of events for the course
     */
    shared_ptr<vector<Event>> getEvents(string &courseId);
    /**
     * Get events for a course
     * @param course Desired course
     * @return List of events for the course
     */
    inline shared_ptr<vector<Event>> getEvents(Course &course){
        string id = course.getId();
        return getEvents(id);
    }

    /**
     * Get reminders for local user
     * @return List of reminders for the course
     */
    shared_ptr<vector<Reminder>> getReminders();

    /**
     * Get todos for the local user
     * @return  vector with todos for local user
     */
    shared_ptr<vector<Todo>> getTodos();
}

#endif //TASQ_APPLICATION_ENDPOINTS_H
