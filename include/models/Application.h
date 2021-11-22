//
// Created by Greg on 2021-10-19.
//

#ifndef TASQ_APPLICATION_APPLICATION_H
#define TASQ_APPLICATION_APPLICATION_H

#include "Models.h"

/**
 * Classes and functions for handling data models
 */
namespace models {
    /**
     * Data model representing the application state
     */
    class Application {
    private:
        unsigned long long lastUpdate;
        uuid localUserId;
    public:
        /**
         * Get timestamp of the last API update
         */
        unsigned long long getLastUpdate();

        /**
         * Set timestamp of last API update
         */
        void setLastUpdate(unsigned long long &newTime);

        /**
         * Get ID of the local user
         */
        uuid getLocalUserId();
    };
}


#endif //TASQ_APPLICATION_APPLICATION_H
