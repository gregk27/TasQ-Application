//
// Created by Greg on 2021-10-24.
//

#ifndef TASQ_APPLICATION_SCHOOLS_H
#define TASQ_APPLICATION_SCHOOLS_H

#include <net/net.h>
#include <models/School.h>
#include <models/Course.h>

using namespace models;

/**
 * Namespace containing netcode for endpoints under /schools/
 */
namespace net::schools {
    /**
     * Get a list of supported schools
     * @return pointer to vector with list of supported schools
     */
    std::shared_ptr<std::vector<School>> getSchools();

    /**
     * Get a list of courses for a school
     * @param schoolId ID of school to check
     * @return pointer to vector with list of courses for the school
     */
    std::shared_ptr<std::vector<Course>> getCourses(QString &schoolId);
    /**
     * Get a list of courses for a school
     * @param school School to check
     * @return pointer to vector with list of courses for the school
     */
    inline std::shared_ptr<std::vector<Course>> getCourses(School &school){
        QString id = school.getId();
        return schools::getCourses(id);
    }
}

#endif //TASQ_APPLICATION_SCHOOLS_H
