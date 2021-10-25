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

}

#endif //TASQ_APPLICATION_COURSES_H
