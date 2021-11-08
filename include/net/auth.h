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
 * Singleton controller for user authentication
 */
class AuthController {
private:
    /** Singleton instance of AuthController */
    static AuthController *_instance;

    /** Session token created on login, used for authorized accesses */
    optional<QString> sessionToken;
    /** ID of last user returned by register or login */
    optional<QString> localUID;

    AuthController();

public:
    /**
     * Get singleton instance
     * @return Singleton instance of the AuthController
     */
    static AuthController *instance();

    /**
     * Register a new user in the database<br/>
     * This will update sessionToken and localUID
     * @param username user's username
     * @param email user's email
     * @param password user's password
     * @param schoolId ID of user's selected school
     * @return User created by database
     */
    shared_ptr<models::User> registerUser(QString &username, QString &email, QString &password, QString &schoolId);

    /**
     * Log in to a user<br/>
     * This will update sessionToken and localUID
     * @param email user's email
     * @param password user's password
     * @return User in database
     */
    shared_ptr<models::User> login(QString &email, QString &password);

    /**
     * Get the locally signed in user
     * @return User in database, nullptr if not logged it
     */
    shared_ptr<models::User> getLocalUser();

    /**
     * Get if there's a session credential (may or may not be valid)
     * @return True if sessionToken and localUID are both set
     */
    bool hasSession();

    /**
     * Get the session token for current user
     * @throws AuthException if no user logged in
     */
    QString getSessionToken();
    /**
     * Get the sessionToken as a std::optional value
     */
    optional<QString> getSessionTokenOptional();
    /**
     * Get the ID for current user
     * @throws AuthException if no user logged in
     */
    QString getLocalUID();
    /**
     * Get the getLocalUID as a std::optional value
     */
    optional<QString> getLocalUIDOptional();
};

/**
 * Exception thrown when there's no localUser to perform an action requiring authorization
 */
class AuthException : public runtime_error {
public:
    /**
     * Create a new AuthException
     * @param action description of action being performed
     */
    explicit AuthException(QString action = "perform this action");
};

#endif //TASQ_APPLICATION_AUTH_H
