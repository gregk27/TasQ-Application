//
// Created by Greg on 2021-10-19.
//

#include <models/Application.h>

using namespace std;
using namespace models;

unsigned long long Application::getLastUpdate() {
    return lastUpdate;
}

void Application::setLastUpdate(unsigned long long &newTime) {
    // TODO: Add database changes
    lastUpdate = newTime;
}

uuid Application::getLocalUserId() {
    return localUserId;
}