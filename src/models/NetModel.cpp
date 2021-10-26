//
// Created by Greg on 2021-10-26.
//

#include <models/NetModel.h>

using namespace models;

ActionException::ActionException(string action, string model):
        runtime_error("Invalid action " + action + " for model " + model + "."){}

map<string, string> *NetModel::getBody(Action a) {
    throw runtime_error("Payload name function not implemented!");
}