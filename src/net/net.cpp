//
// Created by Greg on 2021-10-20.
//

#include <net/net.h>
#include <iostream>

using namespace std;
using namespace net;

typedef struct {
    char *memory;
    size_t size;
} MemoryStruct;

static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    size_t realsize = size * nmemb;
    MemoryStruct *mem = (MemoryStruct *)userp;

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

CURL *net::curl = nullptr;

void net::init() {
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
}

string net::get(string url){
    MemoryStruct chunk;
    chunk.memory = (char*)malloc(1);
    chunk.size = 0;

    // Set URL
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    // Specify chunk for callback
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
    // Specify user agent
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "libcurl-agent/1.0");
    // Set SSL CA certificates
    curl_easy_setopt (curl, CURLOPT_CAINFO, "../lib/bin/cacert.pem");

    CURLcode res = curl_easy_perform(curl);

    if(res != CURLE_OK){
        // TODO: Error handling
        cerr << curl_easy_strerror(res) << endl;
        return "";
    }
    return string(chunk.memory);
}

bool net::getStatus() {
    string result = net::get(BASE_URL + "/status");
    return result == R"({"status": "Alive"})";
}