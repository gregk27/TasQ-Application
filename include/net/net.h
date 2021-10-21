//
// Created by Greg on 2021-10-20.
//

#ifndef TASQ_APPLICATION_NET_H
#define TASQ_APPLICATION_NET_H

#include <string>
#include <stdexcept>
#include <curl/curl.h>

/**
 * Namespace containing netcode for interfacing with backend API
 */
namespace net {
    /** Curl handle used for networking */
    extern CURL *curl;

    /** Base URL for API endpoints */
    const std::string BASE_URL = "https://tasq.gregk.ca";

    /**
     * Initialise the netcode.<br/>
     * Must be called before any other operations can be performed
     */
    void init();

    /**
     * Execute and HTTP or HTTPS GET request
     * @param url The URL to request
     * @return string with response
     */
    std::string get(std::string url);

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
}

#endif //TASQ_APPLICATION_NET_H
