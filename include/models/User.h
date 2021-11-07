//
// Created by Greg on 2021-10-17.
//

#ifndef TASQ_APPLICATION_USER_H
#define TASQ_APPLICATION_USER_H

#include <QString>
#include <QJsonObject>
#include "Models.h"

/**
 * Classes and functions for handling data models
 */
namespace models {
    /**
     * Data model representing a user account/profile
     */
    class User {
    private:
        uuid id;
        QString name;
        uuid schoolId;
    public:
        /**
         * Create a user from a json object with the structure
         * <pre>
         * "id": string,               - Registered user's ID<br/>
         * "name": string,             - Registered user's name<br/>
         * "school": string            - Registered user's school's ID
         */
        explicit User(QJsonObject &json);

        uuid getId();

        /**
         * Get the user's name
         */
        QString getName();

        /**
         * Set the user's name, will be reflected in databases
         */
        void setName(QString &newName);

        /**
         * Get the user's school's id
         */
        uuid getSchoolId();

        /**
         * Set the user's school's id, will be reflected in databases
         */
        void setSchoolId(uuid &newId);
    };
}

#endif //TASQ_APPLICATION_USER_H
