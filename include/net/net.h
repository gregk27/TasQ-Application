//
// Created by Greg on 2021-10-20.
//

#ifndef TASQ_APPLICATION_NET_H
#define TASQ_APPLICATION_NET_H

#include <string>
#include <curl/curl.h>

namespace net {
    extern CURL *curl;

    const std::string BASE_URL = "http://server.lan:120";

    void init();

    std::string get(std::string url);

    bool getStatus();
}

#endif //TASQ_APPLICATION_NET_H
