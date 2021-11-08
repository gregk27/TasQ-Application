//
// Created by Greg on 2021-10-19.
//

#ifndef TASQ_APPLICATION_TODO_H
#define TASQ_APPLICATION_TODO_H

#include "Models.h"
#include <models/NetModel.h>

/**
 * Classes and functions for handling data models
 */
namespace models {

    /**
     * Data model representing a To-do item for the local user
     */
    class Todo : public NetModel {
    private:
        uuid id;
        QString name;
        bool completed;
    public:
        /**
         * Create a To-Do from a json object with the structure
         * <pre>
         * "id": string,           - ID of the To-Do<br/>
         * "name": string,         - Name of the To-Do<br/>
         * "completed": boolean,   - To-Do completion flag
         */
        explicit Todo(QJsonValue &json);

        /**
         * Get the To-do's id
         */
        uuid getId();

        /**
         * Get the To-do's name
         */
        QString getName();

        /**
         * Set the To-do's name, will be reflected in databases
         */
        void setName(QString &newName);

        /**
         * Get the To-do's completion flag
         */
        bool getCompleted();

        /**
         * Set the To-do's completion flag, will be reflected in databases
         */
        void setCompleted(bool newCompleted);

        inline QString getPayloadName() override {
            return "todo";
        }

        QString getURL(Action a) override;

        map<QString, QString> * getBody(Action a) override;
    };
}


#endif //TASQ_APPLICATION_TODO_H
