//
// Created by Greg on 2021-10-30.
//

#include <sstream>
#include <net/api.h>
#include <net/auth.h>

using namespace std;

QString getAPIUrl(){
    const char* url = getenv("API_URL");
    return url ? url : "https://tasq.gregk.ca";
}

const QString APIRequest::BASE_URL = getAPIUrl();

QString APIRequest::buildURL() {
    stringstream ss;
    ss << BASE_URL.toStdString() << endpoint.toStdString();
    if(!parameters.empty()) {
        ss << "?";
        for (auto &arg: body) {
            ss << NetController::instance()->escapeString(arg.first)
               << "="
               << NetController::instance()->escapeString(arg.second)
               << "&";
        }
    }
    return QString::fromStdString(ss.str());
}

APIRequest::APIRequest(QString endpoint, Method method, bool includeAuth) {
    this->endpoint = endpoint;
    this->method = method;
    this->includeAuth = includeAuth;
}

APIRequest *APIRequest::setParameters(map<QString, QString> &parameters) {
    this->parameters = parameters;
    return this;
}

APIRequest *APIRequest::setBody(map<QString, QString> &body) {
    this->body = body;
    return this;
}

void APIRequest::execute() {
    auto nc = NetController::instance();
    if(includeAuth){
        nc->setCurlopt(CURLOPT_COOKIE,"token="+AuthController::instance()->getSessionTokenOptional().value_or(""));
    }
    QJsonDocument res;
    if(method == GET){
        res = nc->getJSON(buildURL());
    } else if (method == POST){
        res = nc->postJSON(buildURL(), body);
    }

    auto js = res.object();
    response = make_shared<APIResponse>(res);
    if(!js["success"].toBool()){
        throw APIResponseException(endpoint, js["error"].toString());
    }
}

shared_ptr<APIResponse> APIRequest::getResponse() {
    return response;
}

APIResponse::APIResponse(QJsonDocument &response) {
    this->response = response;
    success = response["success"].toBool();
    if(!success)
        error = response["error"].toString();
}

bool APIResponse::getSuccess() {
    return success;
}

QString APIResponse::getError() {
    return error;
}

QJsonDocument APIResponse::getResponse() {
    return response;
}

QJsonValue APIResponse::getPayload(QString payloadName) {
    return response[payloadName];
}

APIController *APIController::_instance = nullptr;

APIController *APIController::instance() {
    if(!_instance)
        _instance = new APIController();
    return _instance;
}

bool APIController::getStatus() {
    try{
        QString result = NetController::instance()->get(APIRequest::BASE_URL + "/status", 1000);
        return result == R"({"status": "Alive"})";
    } catch (NetworkException &e) {
        return false;
    }
}

// Build error string and use parent constructor
APIResponseException::APIResponseException(QString endpoint, QString message):
        std::runtime_error("Request to " + endpoint.toStdString() + " failed with message: " + message.toStdString()) { }
