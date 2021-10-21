//
// Created by Greg on 2021-10-20.
//

#include <net/net.h>
#include <iostream>

using namespace std;
using namespace net;

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
CURL *net::curl = nullptr;

void net::init() {
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    // Set memory callback
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
    // Set SSL CA certificates
    curl_easy_setopt (curl, CURLOPT_CAINFO, "../lib/bin/cacert.pem");
    // Specify user agent
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "libcurl-agent/1.0");
}

string net::get(string url){
    // Create a memory chunk to use
    MemoryStruct chunk;
    chunk.memory = (char*)malloc(1);
    chunk.size = 0;

    // Set URL
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    // Specify chunk for callback
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);

    CURLcode res = curl_easy_perform(curl);

    // If the code is anything but okay, throw an exception
    if(res != CURLE_OK){
        throw NetworkException(res);
    }

    // Create string from response
    string out(chunk.memory);
    // Free allocated memory to prevent leak
    free(chunk.memory);

    return out;
}

bool net::getStatus() {
    try{
        string result = net::get(BASE_URL + "/status");
        return result == R"({"status": "Alive"})";
    } catch (NetworkException &e){
        cerr << e.what() << endl;
    }
    return false;
}

// Build error string and use parent constructor
net::NetworkException::NetworkException(CURLcode code):
    std::runtime_error("Request returned code " + to_string(code) + ": " + curl_easy_strerror(code)) { }