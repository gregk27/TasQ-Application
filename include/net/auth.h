//
// Created by Greg on 2021-10-24.
//

#ifndef TASQ_APPLICATION_AUTH_H
#define TASQ_APPLICATION_AUTH_H

#include <optional>
#include <net/net.h>
#include <models/User.h>
#include <QSettings>
#include <QObject>

/**
 * Singleton controller for user authentication
 */
class AuthController: public QObject {

    Q_OBJECT
private:
    /** Singleton instance of AuthController */
    static AuthController *_instance;

    /** Session token created on login, used for authorized accesses */
    std::optional<QString> sessionToken;
    /** ID of last user returned by register or login */
    std::optional<QString> localUID;

    AuthController();

    QSettings settings;

public:
    /**
     * Get singleton instance
     * @return Singleton instance of the AuthController
     */
    static AuthController *instance();

    /**
     * Validate the current session against the database
     * @note This will clear sessionToken and UID if the session is invalid
     * @return True if session is valid, false if not
     */
    bool validateSession();

    /**
     * Register a new user in the database<br/>
     * This will update sessionToken and localUID
     * @param username user's username
     * @param email user's email
     * @param password user's password
     * @param schoolId ID of user's selected school
     * @return User created by database
     */
    std::shared_ptr<models::User> registerUser(QString &username, QString &email, QString &password, QString &schoolId);

    /**
     * Log in to a user<br/>
     * This will update sessionToken and localUID
     * @param email user's email
     * @param password user's password
     * @return User in database
     */
    std::shared_ptr<models::User> login(QString &email, QString &password);

    /**
     * Get the locally signed in user
     * @return User in database, nullptr if not logged it
     */
    std::shared_ptr<models::User> getLocalUser();

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
    std::optional<QString> getSessionTokenOptional();
    /**
     * Get the ID for current user
     * @throws AuthException if no user logged in
     */
    QString getLocalUID();
    /**
     * Get the getLocalUID as a std::optional value
     */
    std::optional<QString> getLocalUIDOptional();

public slots:
    inline void loginSlot(QString email, QString password){
        login(email, password);
    };
    inline void registerSlot(QString &username, QString &email, QString &password, QString &schoolId){
        registerUser(username, email, password, schoolId);
    }
signals:
    void authStateChanged();
};

/**
 * Exception thrown when there's no localUser to perform an action requiring authorization
 */
class AuthException : public std::runtime_error {
public:
    /**
     * Create a new AuthException
     * @param action description of action being performed
     */
    explicit AuthException(QString action = "perform this action");
};

#endif //TASQ_APPLICATION_AUTH_H
