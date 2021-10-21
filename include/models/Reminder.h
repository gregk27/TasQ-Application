//
// Created by Greg on 2021-10-19.
//

#ifndef TASQ_APPLICATION_REMINDER_H
#define TASQ_APPLICATION_REMINDER_H

#include "Models.h"

/**
 * Classes and functions for handling data models
 */
namespace models {
    /**
     * Data model representing a reminder for the local user
     */
    class Reminder {
    private:
        uuid id;
        uuid eventId;
    public:
        /**
         * Get the reminder's id
         */
        uuid getId();

        /**
         * Get the reminder's event's id
         */
        uuid getEventId();
    };
}


#endif //TASQ_APPLICATION_REMINDER_H
