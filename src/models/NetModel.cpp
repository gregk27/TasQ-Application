//
// Created by Greg on 2021-10-26.
//

#include <models/NetModel.h>

using namespace std;
using namespace models;

NetModel::NetModel(uuid id): ModelBase(move(id)) {};

ActionException::ActionException(QString action, QString model):
        runtime_error("Invalid action " + action.toStdString() + " for model " + model.toStdString() + "."){}

std::map<QString, QString> *NetModel::getBody(Action a) {
    throw runtime_error("Payload name function not implemented!");
}