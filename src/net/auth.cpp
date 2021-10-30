//
// Created by Greg on 2021-10-24.
//

#include <net/auth.h>
#include <map>
#include <memory>
#include <iostream>

using namespace net;
using namespace models;

optional<string> auth::sessionToken;
optional<string> auth::localUID;

shared_ptr<User> auth::registerUser(string &username, string &email, string &password, string &schoolId) {
    map<string, string> body {
        {"name", username},
        {"email", email},
        {"password", password},
        {"school", schoolId}
    };

    auto js = postJSON(BASE_URL+"/users/register", body);

    if(!js["success"])
        throw APIResponseException("/users/register", js["error"]);

    auto out = std::make_shared<User>(js["user"]);
    auth::localUID = out->getId();
    auth::sessionToken = js["user"]["token"];
    return out;
}

shared_ptr<User> auth::login(string &email, string &password) {
    map<string, string> body {
            {"email",    email},
            {"password", password}
    };

    auto js = postJSON(BASE_URL+"/users/login", body);

    if(!js["success"])
        throw APIResponseException("/users/login", js["error"]);

    auto out = std::make_shared<User>(js["user"]);
    auth::localUID = out->getId();
    auth::sessionToken = js["user"]["token"];
    return out;
}

shared_ptr<User> auth::getLocalUser(){
    if(!localUID.has_value())
        return nullptr;

    auto js = getJSON(BASE_URL+"/users/"+localUID.value());

    if(!js["success"])
        throw APIResponseException("/users/login", js["error"]);

    auto out = std::make_shared<User>(js["user"]);
    return out;
}