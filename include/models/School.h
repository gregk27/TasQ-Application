//
// Created by Greg on 2021-10-19.
//

#ifndef TASQ_APPLICATION_SCHOOL_H
#define TASQ_APPLICATION_SCHOOL_H

#include "Models.h"

/**
 * Classes and functions for handling data models
 */
namespace models {
    /**
     * Data model representing a school
     */
    class School {
    private:
        uuid id;
        string name;
    public:
        /**
         * Get the school's name
         */
        string getName();
    };
}

#endif //TASQ_APPLICATION_SCHOOL_H
