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
#include <iostream>


/**
 * Singleton controller for network requests
 */
class NetController {
private:
    /** Singleton instance of NetController */
    static NetController *_instance;

    /** Curl handle used for networking */
    CURL *curl = nullptr;

    NetController();
    ~NetController();

    string request(string &url, map<string, string> *body=nullptr);
public:
    /**
     * Get singleton instance
     * @return Singleton instance of the NetController
     */
    static NetController *instance();

    /**
     * Set a CURLOpt, should only be done while preparing a request<br/>
     * Partial wrapper for curl_easy_setopt()
     * @param opt CURLOpt to set
     * @param value String value to give opt
     * @return CURLCode returned by curl_easy_setopt()
     */
    inline CURLcode setCurlopt(CURLoption opt, string value){
        return curl_easy_setopt(curl, opt, value.c_str());
    }

    /**
     * Escape a string for use in request<br/>
     * Wrapper for curl_easy_escape()
     * @param s String to escape
     * @return Escaped string
     */
    inline string escapeString(const string &s){
        return curl_easy_escape(curl, s.c_str(), s.size());
    }

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
