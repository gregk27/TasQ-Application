//
// Created by Greg on 2021-10-21.
//

#ifndef TASQ_APPLICATION_MODELS_H
#define TASQ_APPLICATION_MODELS_H

#include <string>
#include <QString>
#include <QJsonObject>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

/**
 * Classes and functions for handling data models
 */
namespace models {
    typedef QString uuid;

}
#endif //TASQ_APPLICATION_MODELS_H
