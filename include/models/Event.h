//
// Created by Greg on 2021-10-19.
//

#ifndef TASQ_APPLICATION_EVENT_H
#define TASQ_APPLICATION_EVENT_H

#include <optional>
#include "Models.h"
#include "Enums.h"
#include <models/NetModel.h>

/**
 * Classes and functions for handling data models
 */
namespace models {
    /**
     * Data model representing an event
     */
    class Event : public NetModel {
    private:
        uuid courseID;
        QString name;
        enums::EventType type;
        int weight;
        unsigned long long datetime;
        std::optional<unsigned long long> endDate;
        bool weekly;

    public:
        /**
         * Create an event from a json object with the structure
         * <pre>
         * "id": string,           - ID of the event<br/>
         * "course": string,       - ID of the event's course<br/>
         * "name": string,         - Name of the event<br/>
         * "type": string,         - Type of event<br/>
         * "weight": int,          - Grade weight of event<br/>
         * "datetime": long int,   - Unix timestamp of event start<br/>
         * "endDate": long int,    - Unix timestamp of event ending<br/>
         * "weekly": boolean       - Flag to indicate if the event occurs each week
         */
        explicit Event(QJsonValue json);

        /**
         * Get the event's course
         */
        Course *getCourse();

        /**
         * Get the event's courseID
         */
        uuid getCourseId();

        /**
         * Set the event's courseID, will be reflected in databases
         */
        void setCourseID(uuid &newCourseID);

        /**
         * Get the event's name
         */
        QString getName();

        /**
         * Set the event's name, will be reflected in databases
         */
        void setName(QString &newName);

        /**
         * Get the event's type
         */
        enums::EventType getType();

        /**
         * Set the event's type, will be reflected in databases
         */
        void setType(enums::EventType &newType);

        /**
         * Get the event's weight
         */
        int getWeight();

        /**
         * Set the event's weight, will be reflected in databases
         */
        void setWeight(int newWeight);

        /**
         * Get the event's start date/time
         */
        unsigned long long getDatetime();
        /**
         * Get the event's QDateTime
         */
         inline QDateTime getQDatetime() { return QDateTime::fromSecsSinceEpoch(getDatetime()); }

        /**
         * Set the event's start date/time, will be reflected in databases
         */
        void setDatetime(unsigned long long &newDatetime);

        /**
         * Get the event's end date/time
         */
        std::optional<unsigned long long> getEndDate();

        /**
         * Set the event's end date/time, will be reflected in databases
         */
        void setEndDate(std::optional<unsigned long long> &newEndDate);

        /**
         * Get the event's weekly flag
         */
        bool getWeekly();

        /**
         * Set the event's weekly flag, will be reflected in databases
         */
        void setWeekly(bool newWeekly);

        inline QString getPayloadName() override {
            return "event";
        }

        QString getURL(Action a) override;

        std::map<QString, QString> * getBody(Action a) override;
    };
}

Q_DECLARE_METATYPE(models::Event);

#endif //TASQ_APPLICATION_EVENT_H
