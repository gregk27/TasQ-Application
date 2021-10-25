//
// Created by Greg on 2021-10-24.
//

#include <net/auth.h>
#include <map>
#include <memory>
#include <iostream>

using namespace net;
using namespace models;

shared_ptr<User> auth::localUser = nullptr;

shared_ptr<User> auth::registerUser(string &username, string &email, string &password, string &schoolId) {
    map<string, string> body {
        {"name", username},
        {"email", email},
        {"password", password},
        {"school", schoolId}
    };

    auto js = postAPI(BASE_URL+"/users/register", body);

    auto out = std::make_shared<User>(js["user"]);
    auth::localUser = out;
    return out;
}

shared_ptr<User> auth::login(string &email, string &password) {
    map<string, string> body {
            {"email",    email},
            {"password", password}
    };

    auto js = postAPI(BASE_URL+"/users/login", body);

    auto out = std::make_shared<User>(js["user"]);
    auth::localUser = out;
    return out;
}

// Build error string and use parent constructor
auth::AuthException::AuthException(string action):
        runtime_error("You must be logged in to "+action){}