//
// Created by Greg on 2021-11-22.
//

#include <ApplicationController.h>

ApplicationController *ApplicationController::_instance = nullptr;

ApplicationController::ApplicationController() {

}

ApplicationController::~ApplicationController(){

}

ApplicationController *ApplicationController::instance() {
    if(_instance == nullptr)
        _instance = new ApplicationController();
    return _instance;
}