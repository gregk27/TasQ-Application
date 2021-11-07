//
// Created by Greg on 2021-10-26.
//

#ifndef TASQ_APPLICATION_NETMODEL_H
#define TASQ_APPLICATION_NETMODEL_H

#include <map>
#include <stdexcept>
#include <string>
#include <QString>
#include <QJsonObject>

using namespace std;

namespace models {
    class ActionException: public runtime_error {
    public:
        explicit ActionException(QString action, QString model);
    };

    class NetModel {
    public:
        enum Action {
            ADD, MODIFY, REMOVE
        };
        inline virtual QString getPayloadName(){
            throw runtime_error("Payload name function not implemented!");
        }

        virtual QString getURL(Action a) {
            throw runtime_error("Get URL function not implemented!");
        }
        virtual map<QString, QString> *getBody(Action a);
    };
}

#endif //TASQ_APPLICATION_NETMODEL_H
