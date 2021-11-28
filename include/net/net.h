//
// Created by Greg on 2021-10-20.
//

#ifndef TASQ_APPLICATION_NET_H
#define TASQ_APPLICATION_NET_H

#include <string>
#include <map>
#include <stdexcept>
#include <curl/curl.h>
#include <QJsonDocument>
#include <Qstring>
#include <models/NetModel.h>
#include <iostream>
#include <mutex>


/**
 * Singleton controller for network requests
 */
class NetController {
private:
    /** Singleton instance of NetController */
    static NetController *_instance;

    /** Curl handle used for networking */
    CURL *curl = nullptr;

    /** Mutex to ensure only one request happens at once*/
    std::mutex mutex;

    NetController();
    ~NetController();

    QString request(QString &url, std::map<QString, QString> *body=nullptr, int timeout=0);
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
    inline CURLcode setCurlopt(CURLoption opt, QString value){
        return curl_easy_setopt(curl, opt, value.toLocal8Bit().data());
    }

    /**
     * Escape a string for use in request<br/>
     * Wrapper for curl_easy_escape()
     * @param s String to escape
     * @return Escaped string
     */
    inline std::string escapeString(const QString &s){
        return curl_easy_escape(curl, s.toLocal8Bit().data(), s.size());
    }

    /**
     * Execute an HTTP or HTTPS GET request
     * @param url The URL to request
     * @param timeout Optional request timeout, in ms
     * @return string with response
     */
    QString get(QString url, int timeout=0);

    /**
     * Execute an HTTP or HTTPS GET request and get JSON response
     * @param url The URL to request
     * @param timeout Optional request timeout, in ms
     * @return json object generated from response
     * @see net::get(std::string)
     */
    inline QJsonDocument getJSON(QString url, int timeout=0){
        return QJsonDocument::fromJson(get(url, timeout).toUtf8());
    }

    /**
     * Execute an HTTP or HTTPS POST request
     * @param url The URL to request
     * @param body The POST body, as key-value pairs
     * @return string with response
     */
    QString post(QString url, std::map<QString, QString> &body);

    /**
     * Execute an HTTP or HTTPS POST request
     * @param url The URL to request
     * @param body The POST body, as key-value pairs
     * @return json object generated from response
     * @see net::post(std::string, std::map<std::string, std::string>)
     */
    inline QJsonDocument postJSON(QString url, std::map<QString, QString> &body){
        return QJsonDocument::fromJson(post(url, body).toUtf8());
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
    explicit NetworkException(QString endpoint, CURLcode code);
};

#endif //TASQ_APPLICATION_NET_H
