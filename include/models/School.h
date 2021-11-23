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
    class School : public ModelBase {
    private:
        QString name;
    public:
        /**
         * Create a school from a json object with the structure
         * <pre>
         * "id": string,           - ID of school <br/>
         * "name": string,         - Name of school
         */
        explicit School(QJsonValue &json);

        /**
         * Get the school's name
         */
        QString getName();
    };
}

Q_DECLARE_METATYPE(models::School);

#endif //TASQ_APPLICATION_SCHOOL_H
