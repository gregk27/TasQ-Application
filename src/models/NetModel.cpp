//
// Created by Greg on 2021-10-26.
//

#include <models/NetModel.h>

using namespace models;

ActionException::ActionException(QString action, QString model):
        runtime_error("Invalid action " + action.toStdString() + " for model " + model.toStdString() + "."){}

map<QString, QString> *NetModel::getBody(Action a) {
    throw runtime_error("Payload name function not implemented!");
}