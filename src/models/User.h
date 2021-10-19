//
// Created by Greg on 2021-10-17.
//

#ifndef TASQ_APPLICATION_USER_H
#define TASQ_APPLICATION_USER_H

#include "ModelBase.h"

/**
 * Classes and functions for handling data models
 */
namespace models {
    /**
     * Data model representing a user account/profile
     */
    class User : public ModelBase {
    private:
        uuid id;
        string name;
        string email;
        uuid schoolId;
    public:
        uuid getId();

        /**
         * Get the user's name
         */
        string getName();

        /**
         * Set the user's name, will be reflected in databases
         */
        void setName(string &newName);

        /**
         * Get the user's email
         */
        string getEmail();

        /**
         * Set the user's email, will be reflected in databases
         */
        void setEmail(string &newEmail);

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
