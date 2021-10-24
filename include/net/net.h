//
// Created by Greg on 2021-10-20.
//

#ifndef TASQ_APPLICATION_NET_H
#define TASQ_APPLICATION_NET_H

#include <string>
#include <stdexcept>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

/**
 * Namespace containing netcode for interfacing with backend API
 */
namespace net {
    /** Curl handle used for networking */
    extern CURL *curl;

    /** Base URL for API endpoints */
    extern const std::string BASE_URL;

    /**
     * Initialise the netcode.<br/>
     * Must be called before any other operations can be performed
     */
    void init();

    /**
     * Execute an HTTP or HTTPS GET request
     * @param url The URL to request
     * @return string with response
     */
    std::string get(std::string url);

    /**
     * Execute an HTTP or HTTPS GET request and get JSON response
     * @param url The URL to request
     * @return json object generated from response
     * @see net::get(std::string)
     */
    nlohmann::json getJSON(std::string url);

    /**
     * Get the API status
     * @returns True if API is alive and can be reached
     */
    bool getStatus();

    /**
     * Exception thrown on curl request failure
     */
    class NetworkException: public std::runtime_error {
    public:
        /**
         * Create a new NetworkException
         * @param code curl response code
         */
        explicit NetworkException(CURLcode code);
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
}

#endif //TASQ_APPLICATION_NET_H
