//
// Created by Greg on 2021-10-20.
//

#include <net/net.h>
#include <iostream>
#include <optional>
#include <string>
#include <sstream>
#include <net/auth.h>
#include <net/api.h>

using namespace std;

/** Struct to store curl response data */
typedef struct {
    /** Memory containing response text */
    char *memory;
    /** Size of response text */
    size_t size;
} MemoryStruct;

/**
 * Callback used by curl to write memory into a MemoryStruct <br/>
 * Taken from https://curl.se/libcurl/c/getinmemory.html
 */
static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    size_t realsize = size * nmemb;
    auto *mem = (MemoryStruct *)userp;

    char *ptr = (char *)realloc(mem->memory, mem->size + realsize + 1);
    if(!ptr) {
        /* out of memory! */
        printf("not enough memory (realloc returned NULL)\n");
        return 0;
    }

    mem->memory = ptr;
    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;

    return realsize;
}

/** Initialise curl handle to nullptr */
NetController *NetController::_instance = nullptr;

NetController::NetController() {
    cout << "Global init" << endl;
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    // Set memory callback
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
    // Set SSL CA certificates
    curl_easy_setopt (curl, CURLOPT_CAINFO, "./lib/bin/cacert.pem");
    // Specify user agent
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "libcurl-agent/1.0");
}

NetController::~NetController() {
    curl_easy_cleanup(curl);
    curl_global_cleanup();
}

/**
 * Local function to perform the HTTP/HTTPS requests<br/>
 * This function is local to ensure that get/post methods are used for legibility
 * @param url The URL to request
 * @param body The POST body. If null then will perform GET request
 * @param timeout Optional request timeout, in milliseconds
 * @return QString with response
 */
QString NetController::request(QString &url, map<QString, QString> *body, int timeout){
    lock_guard<std::mutex> guard(mutex);
    // Create a memory chunk to use
    MemoryStruct chunk;
    chunk.memory = (char*)malloc(1);
    chunk.size = 0;

    // Set URL
    curl_easy_setopt(curl, CURLOPT_URL, url.toLocal8Bit().data());
    // Specify chunk for callback
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
    // Fail on bad HTTP response
    curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1);
    // Set timeout
    curl_easy_setopt(curl, CURLOPT_TIMEOUT_MS, timeout);

    // If the body is set, then perform POST request
    // Otherwise perform GET request
    /** Storage to keep postFields in scope until execution */
    string postFields;
    if(body){
        stringstream bodyStr;
        for(auto &arg : *body){
            bodyStr << escapeString(arg.first)
                    << "="
                    << escapeString(arg.second)
                    << "&";
        }
        postFields = bodyStr.str();
        // Specify POST data
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postFields.c_str());
        // Set POST mode
        curl_easy_setopt(curl, CURLOPT_POST, 1);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 0);
    } else {
        // Set GET mode
        curl_easy_setopt(curl, CURLOPT_HTTPGET, 1);
    }

    CURLcode res = curl_easy_perform(curl);
    // If the code is anything but okay, throw an exception
    if(res != CURLE_OK){
        throw NetworkException(url, res);
    }

    // Create string from response
    QString out(chunk.memory);
    // Free allocated memory to prevent leak
    free(chunk.memory);

    return out;
}

NetController *NetController::instance() {
    if(!_instance)
        _instance = new NetController();
    return _instance;
}

QString NetController::get(QString url, int timeout){
    return request(url, nullptr, timeout);
}

QString NetController::post(QString url, map<QString, QString> &body) {
    return request(url, &body);
}

// Build error string and use parent constructor
NetworkException::NetworkException(QString endpoint, CURLcode code):
    std::runtime_error("Request to " + endpoint.toStdString() + " returned code " + to_string(code) + ": " + curl_easy_strerror(code)) { }
