//
// Created by Greg on 2021-10-30.
//

#ifndef TASQ_APPLICATION_API_H
#define TASQ_APPLICATION_API_H

#include <string>
#include <map>
#include <QJsonDocument>
#include <QJsonObject>
#include <net/net.h>

using namespace std;
using json = nlohmann::json;

// Forward declare APIResponse
class APIResponse;

/**
 * Class to create and execute and API request
 */
class APIRequest {
public:
    /**
     * HTTP method used to execute request
     */
    enum Method {
        GET, POST
    };
    /** Base URL for API endpoints */
    static const QString BASE_URL;
private:
    /** Endpoint targeted by the request */
    QString endpoint;
    /** HTTP method used to execute request */
    Method method;
    /** Flag indicating whether authentication token is included */
    bool includeAuth;

    /** Parameters to be provided in query string */
    map<QString, QString> parameters;
    /** POST body, only used if method is set to post */
    map<QString, QString> body;
    /** Response from API */
    shared_ptr<APIResponse> response = nullptr;

    /**
     * Build the request url string
     * @return URL built from members
     */
    QString buildURL();
public:
    /**
     * Create a new API Request
     * @param endpoint API endpoint to use
     * @param method HTTP method to use
     * @param includeAuth Flag indicating whether authentication token is included
     */
    explicit APIRequest(QString endpoint, Method method = GET, bool includeAuth = true);

    /**
     * Set query string parameters
     * @param parameters Parameters to be included in query string
     * @return the APIRequest object so initialisation can be chained
     */
    APIRequest *setParameters(map<QString, QString> &parameters);

    /**
     * Set POST body
     * @param body Body to be included in request
     * @return the APIRequest object so initialisation can be chained
     */
    APIRequest *setBody(map<QString, QString> &body);

    /**
     * Execute the API request
     * @throw APIResponseException on API failure
     */
    void execute();

    /**
     * Get the API's response object
     */
    shared_ptr<APIResponse> getResponse();
};

/**
 * Class representing response from the API
 */
class APIResponse {
private:
    /** API response success */
    bool success;
    /** API response error */
    QString error;

    /** API response body */
    QJsonDocument response;
public:
    /**
     * Create a new APIResponse
     * @param response Response body as json object
     */
    explicit APIResponse(QJsonDocument &response);

    /**
     * Get API response success
     */
    bool getSuccess();

    /**
     * Get API response error message
     */
    QString getError();

    /**
     * Get API response body
     * @return QJsonDocument, object can be obtained with .object()
     */
    QJsonDocument getResponse();

    /**
     * Get API response payload
     * @param payloadName Name of the payload object in response
     * @return QJsonValue, which must then be converted as required
     */
    QJsonValue getPayload(QString payloadName);
};

class APIController {
private:
    /** Singleton instance of AuthController */
    static APIController *_instance;

    APIController() = default;

public:
    /**
     * Get singleton instance
     * @return Singleton instance of the APIController
     */
    static APIController *instance();

    /**
     * Get the API status
     * @returns True if API is alive and can be reached
     */
    bool getStatus();

    template <typename T>
    shared_ptr<T> add(models::NetModel &m){
        map<QString, QString> *body = m.getBody(models::NetModel::Action::ADD);
        auto req = APIRequest(m.getURL(models::NetModel::Action::ADD), APIRequest::POST);
        req.setBody(*body);
        req.execute();
        delete body;
        auto payload = req.getResponse()->getPayload(m.getPayloadName());
        return make_shared<T>(payload);
    }

    template <typename T>
    shared_ptr<T> modify(models::NetModel &m){
        map<QString, QString> *body = m.getBody(models::NetModel::Action::MODIFY);
        auto req = APIRequest(m.getURL(models::NetModel::Action::MODIFY), APIRequest::POST);
        req.setBody(*body);
        req.execute();
        delete body;
        auto payload = req.getResponse()->getPayload(m.getPayloadName());
        return make_shared<T>(payload);
    }

    template <typename T>
    bool remove(models::NetModel &m){
        map<QString, QString> *body = m.getBody(models::NetModel::Action::REMOVE);
        auto req = APIRequest(m.getURL(models::NetModel::Action::REMOVE), APIRequest::POST);
        req.setBody(*body);
        req.execute();
        delete body;
        return req.getResponse()->getSuccess();
    }
};

/**
 * Exception thrown when API returns failed response
 */
class APIResponseException: public std::runtime_error{
public:
    /**
     * Create a new APIResponseException
     * @param endpoint API endpoint returning the response
     * @param message error message provided by API
     */
    APIResponseException(QString endpoint, QString message);
};

#endif //TASQ_APPLICATION_API_H
