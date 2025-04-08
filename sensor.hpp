#pragma once
#include <vector>

class Sensor {
private:
    std::vector<double> dataBuffer;
    const int bufferSize = 5;

public:
    void initialize();
    double readRawData(); // Simulate raw sensor read
    double readProcessedData(); // Apply averaging/filtering
};
