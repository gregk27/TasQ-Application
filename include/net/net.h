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
    inline nlohmann::json getJSON(std::string url){
        return nlohmann::json::parse(get(url));
    }

    /**
     * Execute a GET request to API, with check for API success flag
     * @param url The URL to request
     * @return json object generated from response
     * @see net::getJSON(std::string)
     */
    nlohmann::json getAPI(std::string url);

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

    /**
     * Execute a POST request to API, with check for API success flag
     * @param url The URL to request
     * @param body The POST body, as key-value pairs
     * @return json object generated from response
     * @see net::postJSON(std::string, std::map<std::string, std::string>)
     */
    nlohmann::json postAPI(std::string url, std::map<std::string, std::string> &body);

    /**
     * Get the API status
     * @returns True if API is alive and can be reached
     */
    bool getStatus();

    template <typename T>
    shared_ptr<T> addModel(models::NetModel &m){
        map<string, string> *body = m.getBody(models::NetModel::Action::ADD);
        auto js = postAPI(BASE_URL+m.getURL(models::NetModel::Action::ADD), *body);
        delete body;
        return make_shared<T>(js[m.getPayloadName()]);
    }

    template <typename T>
    shared_ptr<T> modifyModel(models::NetModel &m){
        map<string, string> *body = m.getBody(models::NetModel::Action::MODIFY);
        auto js = postAPI(BASE_URL+m.getURL(models::NetModel::Action::MODIFY), *body);
        delete body;
        return make_shared<T>(js[m.getPayloadName()]);
    }

    template <typename T>
    bool removeModel(models::NetModel &m){
        map<string, string> *body = m.getBody(models::NetModel::Action::REMOVE);
        auto js = postAPI(BASE_URL+m.getURL(models::NetModel::Action::REMOVE), *body);
        delete body;
        return true;
    }

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

}

#endif //TASQ_APPLICATION_NET_H
