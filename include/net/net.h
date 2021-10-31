//
// Created by Greg on 2021-10-20.
//

#ifndef TASQ_APPLICATION_NET_H
#define TASQ_APPLICATION_NET_H

#include <string>
#include <map>
#include <stdexcept>
#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include <models/NetModel.h>

/**
 * Namespace containing netcode for interfacing with backend API
 */
namespace net {
    /** Curl handle used for networking */
    extern CURL *curl;

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
    inline nlohmann::json getJSON(std::string url){
        return nlohmann::json::parse(get(url));
    }

    /**
     * Execute an HTTP or HTTPS POST request
     * @param url The URL to request
     * @param body The POST body, as key-value pairs
     * @return string with response
     */
    std::string post(std::string url, std::map<std::string, std::string> &body);

    /**
     * Execute an HTTP or HTTPS POST request
     * @param url The URL to request
     * @param body The POST body, as key-value pairs
     * @return json object generated from response
     * @see net::post(std::string, std::map<std::string, std::string>)
     */
    inline nlohmann::json postJSON(std::string url, std::map<std::string, std::string> &body){
        return nlohmann::json::parse(post(url, body));
    }

};

/**
 * Exception thrown on curl request failure
 */
class NetworkException: public std::runtime_error {
public:
    /**
     * Create a new NetworkException
     * @param code curl response code
     */
    explicit NetworkException(std::string endpoint, CURLcode code);
};

#endif //TASQ_APPLICATION_NET_H
