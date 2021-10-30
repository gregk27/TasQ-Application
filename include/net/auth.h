//
// Created by Greg on 2021-10-24.
//

#ifndef TASQ_APPLICATION_AUTH_H
#define TASQ_APPLICATION_AUTH_H

#include <optional>
#include <net/net.h>
#include <models/User.h>

using namespace std;

/**
 * Namespace containing netcode for authentication with API
 */
namespace net::auth {
    /**
     * Session token created on login, used for authorized accesses
     */
    extern optional<string> sessionToken;
    /**
     * Global variable with the last user returned by register or login
     */
    extern optional<string> localUID;

    /**
     * Register a new user in the database<br/>
     * This will update net::sessionToken and net::localUID
     * @param username user's username
     * @param email user's email
     * @param password user's password
     * @param schoolId ID of user's selected school
     * @return User created by database
     */
    shared_ptr<models::User> registerUser(string &username, string &email, string &password, string &schoolId);

    /**
     * Log in to a user<br/>
     * This will update net::sessionToken and net::localUID
     * @param email user's email
     * @param password user's password
     * @return User in database
     */
    shared_ptr<models::User> login(string &email, string &password);

    /**
     * Get the locally signed in user
     * @return User in database
     */
    shared_ptr<models::User> getLocalUser();

    /**
     * Exception thrown when there's no localUser to perform an action requiring authorization
     */
    class AuthException: public runtime_error {
    public:
        /**
         * Create a new AuthException
         * @param action description of action being performed
         */
        explicit AuthException(string action);
    };
}

#endif //TASQ_APPLICATION_AUTH_H
