//
// Created by Greg on 2021-10-24.
//

#include <net/auth.h>
#include <map>
#include <memory>
#include <iostream>
#include <net/api.h>
#include <net/subscriptions.h>
#include <QSettings>

#define SESSION_TOKEN_KEY "session"
#define LOCAL_UID_KEY "localUID"

using namespace std;
using namespace models;

AuthController *AuthController::_instance = nullptr;

AuthController::AuthController() {
    // Get auth properties if available
    if((sessionToken = settings.value(SESSION_TOKEN_KEY, "").toString()) == ""){
        sessionToken.reset();
    } else if((localUID = settings.value(LOCAL_UID_KEY, "").toString()) == ""){
        localUID.reset();
    }
}

AuthController *AuthController::instance() {
    if(!_instance) {
        _instance = new AuthController();
        // Validate the session, must be called after instance is created
        _instance->validateSession();
    }
    return _instance;
}

bool AuthController::validateSession() {
    try {
        net::subscriptions::getSubscriptions();
        return true;
    } catch (APIResponseException &e){
        sessionToken.reset();
        settings.remove(SESSION_TOKEN_KEY);
        localUID.reset();
        settings.remove(LOCAL_UID_KEY);
        return false;
    }
}


shared_ptr<User> AuthController::registerUser(QString &username, QString &email, QString &password, QString &schoolId) {
    map<QString, QString> body {
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
    sessionToken = payload["token"].toString();
    settings.setValue(LOCAL_UID_KEY, localUID.value());
    settings.setValue(SESSION_TOKEN_KEY, sessionToken.value());
    emit authStateChanged();
    return out;
}

shared_ptr<User> AuthController::login(QString &email, QString &password) {
    map<QString, QString> body {
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
    sessionToken = payload["token"].toString();
    settings.setValue(LOCAL_UID_KEY, localUID.value());
    settings.setValue(SESSION_TOKEN_KEY, sessionToken.value());
    emit authStateChanged();
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

QString AuthController::getSessionToken() {
    if(sessionToken.has_value())
        return sessionToken.value();
    throw AuthException();
}

optional<QString> AuthController::getSessionTokenOptional() {
    return sessionToken;
}

QString AuthController::getLocalUID() {
    if(localUID.has_value())
        return localUID.value();
    throw AuthException();
}

optional<QString> AuthController::getLocalUIDOptional() {
    return localUID;
}

// Build error string and use parent constructor
AuthException::AuthException(QString action):
        runtime_error("You must be logged in to "+action.toStdString()){}