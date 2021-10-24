# Lib
This folder should contain require libraries as outlined in this file.

Libraries are not distributed with this project, and must be sourced externally.

## CURL
The CURL library is used for web requests to the backend API

Windows binaries can be downloaded from [https://curl.se/windows/](https://curl.se/windows/). <br/>
The bin, lib, and include folders should be copied to /lib.

You will also need to add `cacert.pem` downloaded from [http://curl.haxx.se/ca/cacert.pem](http://curl.haxx.se/ca/cacert.pem) to /bin for https functionality.

## nlohmann/json
The nlohmann/json library is used for parsing API responses.

It is a single-header library, and can be downloaded from [https://github.com/nlohmann/json/releases](https://github.com/nlohmann/json/releases). <br/>
The header should be placed in /lib/include/nlohmann

## Catch2
Catch 2 is used for unit and integration testing.

It is a single-header library which can be downloaded from [https://github.com/catchorg/Catch2/releases](https://github.com/catchorg/Catch2/releases) </br>
The header should be placed in /lib/include/catch2
