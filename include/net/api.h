//
// Created by Greg on 2021-10-30.
//

#ifndef TASQ_APPLICATION_API_H
#define TASQ_APPLICATION_API_H

#include <string>
#include <map>
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
private:
    /** Endpoint targeted by the request */
    string endpoint;
    /** HTTP method used to execute request */
    Method method;
    /** Flag indicating whether authentication token is included */
    bool includeAuth;

    /** Parameters to be provided in query string */
    map<string, string> parameters;
    /** POST body, only used if method is set to post */
    map<string, string> body;
    /** Response from API */
    shared_ptr<APIResponse> response = nullptr;

    /**
     * Build the request url string
     * @return URL built from members
     */
    string buildURL();
public:
    /**
     * Create a new API Request
     * @param endpoint API endpoint to use
     * @param method HTTP method to use
     * @param includeAuth Flag indicating whether authentication token is included
     */
    explicit APIRequest(string endpoint, Method method = GET, bool includeAuth = true);

    /**
     * Set query string parameters
     * @param parameters Parameters to be included in query string
     * @return the APIRequest object so initialisation can be chained
     */
    APIRequest *setParameters(map<string, string> &parameters);

    /**
     * Set POST body
     * @param body Body to be included in request
     * @return the APIRequest object so initialisation can be chained
     */
    APIRequest *setBody(map<string, string> &body);

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
    string error;

    /** API response body */
    json response;
public:
    /**
     * Create a new APIResponse
     * @param response Response body as json object
     */
    explicit APIResponse(json &response);

    /**
     * Get API response success
     */
    bool getSuccess();

    /**
     * Get API response error message
     */
    string getError();

    /**
     * Get API response body
     */
    json getResponse();

    /**
     * Get API response payload
     * @param payloadName Name of the payload object in response
     */
    json getPayload(string payloadName);
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
    APIResponseException(std::string endpoint, std::string message);
};

#endif //TASQ_APPLICATION_API_H
