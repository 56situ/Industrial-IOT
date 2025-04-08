#pragma once
#include <string>

class Network {
private:
    std::string host;
    int port;

public:
    Network(const std::string& host, int port);
    bool sendSecureData(const std::string& data);
};
