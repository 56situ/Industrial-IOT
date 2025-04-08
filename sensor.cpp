#include "Sensor.hpp"
#include <cstdlib>
#include <ctime>

void Sensor::initialize() {
    std::srand(std::time(nullptr));
}

double Sensor::readRawData() {
    return 50 + (std::rand() % 1000) / 10.0; // Simulated raw sensor data
}

double Sensor::readProcessedData() {
    double raw = readRawData();
    if (dataBuffer.size() >= bufferSize)
        dataBuffer.erase(dataBuffer.begin());
    dataBuffer.push_back(raw);

    double sum = 0.0;
    for (double val : dataBuffer)
        sum += val;

    return sum / dataBuffer.size(); // Simple moving average
}
