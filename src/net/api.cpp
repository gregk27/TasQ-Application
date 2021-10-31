//
// Created by Greg on 2021-10-30.
//

#include <sstream>
#include <net/api.h>
#include <net/auth.h>

string APIRequest::buildURL() {
    stringstream ss;
    ss << net::BASE_URL << endpoint;
    if(!parameters.empty()) {
        ss << "?";
        for (auto &arg: body) {
            ss << curl_easy_escape(net::curl, arg.first.c_str(), arg.first.size())
               << "="
               << curl_easy_escape(net::curl, arg.second.c_str(), arg.second.size())
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
    if(includeAuth){
        curl_easy_setopt(net::curl, CURLOPT_COOKIE, ("token="+AuthController::instance()->getSessionTokenOptional().value_or("")).c_str());
    }
    string res;
    if(method == GET){
        res = net::get(buildURL());
    } else if (method == POST){
        res = net::post(buildURL(), body);
    }

    auto js = json::parse(res);
    if(!js["success"]){
        response = make_shared<APIResponse>(js);
        throw net::APIResponseException(endpoint, js["error"]);
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