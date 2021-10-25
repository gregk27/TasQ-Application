//
// Created by Greg on 2021-10-24.
//

#ifndef TASQ_APPLICATION_COURSES_H
#define TASQ_APPLICATION_COURSES_H

#include <string>
#include <net/net.h>
#include <models/Course.h>
#include <models/Event.h>

using namespace std;
using namespace models;

/**
 * Namespace containing netcode for endpoints under /courses/
 */
namespace net::courses {

    /**
     * Add a new course to database
     * @param course Course data to be added. id and owner can be empty strings, will be set by function
     * @return The course object returned by API
     */
    shared_ptr<Course> add(Course &course);

    /**
     * Modify an existing course in database
     * @param course Updated data for course to be modified
     * @return The course object returned by API
     */
    shared_ptr<Course> modify(Course &course);

    /**
     * Delete a course in database
     * @param courseId ID of the course to delete
     * @return True on successful deletion
     */
    bool remove(string &courseId);
    /**
     * Delete a course in database
     * @param course Course to delete
     * @return True on successful deletion
     * @see net::courses::remove(string);
     */
    inline bool remove(Course &course){
        string id = course.getId();
        return remove(id);
    }

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
     * Add an event for a course
     * @param event Event data to create from
     * @return The event object returned by API
     */
    shared_ptr<Event> addEvent(Event &event);

    /**
     * Modify an existing event
     * @param event New event data
     * @return The event object returned by API
     */
    shared_ptr<Event> modifyEvent(Event &event);

    /**
     * Delete event in database
     * @param eventId ID of the event to delete
     * @param courseId ID of the event's course
     * @return True on success
     */
    bool removeEvent(string &eventId, string &courseId);
    /**
     * Delete event in database
     * @param event Event to delete
     * @return True on success
     */
    inline bool removeEvent(Event &event){
        string eventId = event.getId();
        string courseId = event.getCourseID();
        return removeEvent(eventId, courseId);
    }
}

#endif //TASQ_APPLICATION_COURSES_H
