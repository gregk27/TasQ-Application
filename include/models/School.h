//
// Created by Greg on 2021-10-19.
//

#ifndef TASQ_APPLICATION_SCHOOL_H
#define TASQ_APPLICATION_SCHOOL_H

#include <QJsonObject>
#include <QString>
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
        QString name;
    public:
        /**
         * Create a school from a json object with the structure
         * <pre>
         * "id": string,           - ID of school <br/>
         * "name": string,         - Name of school
         */
        explicit School(QJsonObject &json);

        /**
         * Get the school's ID
         */
        QString getId();

        /**
         * Get the school's name
         */
        QString getName();
    };
}

#endif //TASQ_APPLICATION_SCHOOL_H
