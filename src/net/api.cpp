//
// Created by Greg on 2021-10-30.
//

#include <sstream>
#include <net/api.h>
#include <net/auth.h>

const string APIRequest::BASE_URL = "http://server.lan:120";

string APIRequest::buildURL() {
    stringstream ss;
    ss << BASE_URL << endpoint;
    if(!parameters.empty()) {
        ss << "?";
        for (auto &arg: body) {
            ss << NetController::instance()->escapeString(arg.first)
               << "="
               << NetController::instance()->escapeString(arg.second)
               << "&";
        }
    }
    return ss.str();
}

APIRequest::APIRequest(string endpoint, Method method, bool includeAuth) {
    this->endpoint = endpoint;
    this->method = method;
    this->includeAuth = includeAuth;
}

APIRequest *APIRequest::setParameters(map<string, string> &parameters) {
    this->parameters = parameters;
    return this;
}

APIRequest *APIRequest::setBody(map<string, string> &body) {
    this->body = body;
    return this;
}

void APIRequest::execute() {
    auto nc = NetController::instance();
    if(includeAuth){
        nc->setCurlopt(CURLOPT_COOKIE,"token="+AuthController::instance()->getSessionTokenOptional().value_or(""));
    }
    string res;
    if(method == GET){
        res = nc->get(buildURL());
    } else if (method == POST){
        res = nc->post(buildURL(), body);
    }

    auto js = json::parse(res);
    if(!js["success"]){
        response = make_shared<APIResponse>(js);
        throw APIResponseException(endpoint, js["error"]);
    }
    response = make_shared<APIResponse>(js);
}

shared_ptr<APIResponse> APIRequest::getResponse() {
    return response;
}

APIResponse::APIResponse(json &response) {
    this->response = response;
    success = response["success"];
    if(!success)
        error = response["error"];
}

bool APIResponse::getSuccess() {
    return success;
}

string APIResponse::getError() {
    return error;
}

json APIResponse::getResponse() {
    return response;
}

json APIResponse::getPayload(string payloadName) {
    return response[payloadName];
}

APIController *APIController::_instance = nullptr;

APIController *APIController::instance() {
    if(!_instance)
        _instance = new APIController();
    return _instance;
}

bool APIController::getStatus() {
    string result = NetController::instance()->get(APIRequest::BASE_URL + "/status");
    return result == R"({"status": "Alive"})";
}

// Build error string and use parent constructor
APIResponseException::APIResponseException(std::string endpoint, std::string message):
        std::runtime_error("Request to " + endpoint + " failed with message: " + message) { }