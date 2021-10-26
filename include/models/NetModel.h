//
// Created by Greg on 2021-10-26.
//

#ifndef TASQ_APPLICATION_NETMODEL_H
#define TASQ_APPLICATION_NETMODEL_H

#include <map>
#include <stdexcept>
#include <string>

using namespace std;

namespace models {
    class ActionException: public runtime_error {
    public:
        explicit ActionException(string action, string model);
    };

    class NetModel {
    public:
        enum Action {
            ADD, MODIFY, REMOVE
        };
        inline virtual string getPayloadName(){
            throw runtime_error("Payload name function not implemented!");
        }

        virtual string getURL(Action a) {
            throw runtime_error("Get URL function not implemented!");
        }
        virtual map<string, string> *getBody(Action a);
    };
}

#endif //TASQ_APPLICATION_NETMODEL_H
