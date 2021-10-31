//
// Created by Greg on 2021-10-24.
//

#include <net/auth.h>
#include <map>
#include <memory>
#include <iostream>
#include <net/api.h>

using namespace models;

AuthController *AuthController::_instance = nullptr;

AuthController::AuthController() {
    // TODO: Hardcoded values used until proper local storage is established
    sessionToken = "e859b1a3-38e8-11ec-a3fd-0023aea14009";
    localUID = "6df88578-3526-11ec-a3fd-0023aea14009";
}

AuthController *AuthController::instance() {
    if(!_instance)
        _instance = new AuthController();
    return _instance;
}

shared_ptr<User> AuthController::registerUser(string &username, string &email, string &password, string &schoolId) {
    map<string, string> body {
        {"name", username},
        {"email", email},
        {"password", password},
        {"school", schoolId}
    };

    auto req = APIRequest("/users/register", APIRequest::POST, false);
    req.setBody(body)
        -> execute();

    auto res = req.getResponse();

    auto payload = res->getPayload("user");

    auto out = std::make_shared<User>(payload);
    localUID = out->getId();
    sessionToken = payload["token"];
    return out;
}

shared_ptr<User> AuthController::login(string &email, string &password) {
    map<string, string> body {
            {"email",    email},
            {"password", password}
    };

    auto req = APIRequest("/users/login", APIRequest::POST, false);
    req.setBody(body)
        -> execute();

    auto res = req.getResponse();

    auto payload = res->getPayload("user");
    auto out = std::make_shared<User>(payload);
    localUID = out->getId();
    sessionToken = payload["token"];
    return out;
}

shared_ptr<User> AuthController::getLocalUser(){
    if(!localUID.has_value())
        return nullptr;

    auto req = APIRequest("/users/"+localUID.value());
    req.execute();

    auto res = req.getResponse();
    auto payload = res->getPayload("user");

    return std::make_shared<User>(payload);
}

bool AuthController::hasSession() {
    return sessionToken.has_value() && localUID.has_value();
}

string AuthController::getSessionToken() {
    if(sessionToken.has_value())
        return sessionToken.value();
    throw AuthException();
}

optional<string> AuthController::getSessionTokenOptional() {
    return sessionToken;
}

string AuthController::getLocalUID() {
    if(localUID.has_value())
        return localUID.value();
    throw AuthException();
}

optional<string> AuthController::getLocalUIDOptional() {
    return localUID;
}

// Build error string and use parent constructor
AuthException::AuthException(string action):
        runtime_error("You must be logged in to "+action){}