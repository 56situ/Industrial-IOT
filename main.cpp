#include "Sensor.hpp"
#include "Network.hpp"

int main() {
    Sensor sensor;
    Network network("your.server.com", 443); // Use port 443 for HTTPS

    sensor.initialize();

    while (true) {
        double value = sensor.readProcessedData(); // Averaged and filtered value
        std::string jsonData = "{\"sensor_value\": " + std::to_string(value) + "}";

        if (network.sendSecureData(jsonData)) {
            std::cout << "Data sent successfully.\n";
        } else {
            std::cout << "Data send failed.\n";
        }

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
