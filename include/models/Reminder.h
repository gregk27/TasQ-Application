//
// Created by Greg on 2021-10-19.
//

#ifndef TASQ_APPLICATION_REMINDER_H
#define TASQ_APPLICATION_REMINDER_H

#include "Models.h"
#include <models/NetModel.h>

/**
 * Classes and functions for handling data models
 */
namespace models {
    /**
     * Data model representing a reminder for the local user
     */
    class Reminder : public NetModel {
    private:
        uuid id;
        uuid eventId;
    public:
        /**
         * Create an event from a json object with the structure
         * <pre>
         * "id": string,           - ID of the reminder<br/>
         * "event": string         - ID of the event the reminder is for
         */
        explicit Reminder(json &json);

        /**
         * Get the reminder's id
         */
        uuid getId();

        /**
         * Get the reminder's event's id
         */
        uuid getEventId();

        inline string getPayloadName() override {
            return "reminder";
        }

        string getURL(Action a) override;

        map<string, string> * getBody(Action a) override;
    };
}


#endif //TASQ_APPLICATION_REMINDER_H
