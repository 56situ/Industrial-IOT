#include "Network.hpp"
#include <curl/curl.h>
#include <iostream>

Network::Network(const std::string& host, int port)
    : host(host), port(port) {}

bool Network::sendSecureData(const std::string& data) {
    CURL* curl = curl_easy_init();
    if (!curl) return false;

    std::string url = "https://" + host + ":" + std::to_string(port) + "/data";

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 1L);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 2L);
    curl_easy_setopt(curl, CURLOPT_CAINFO, "/path/to/cacert.pem"); // Replace with actual path

    CURLcode res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    return (res == CURLE_OK);
}
