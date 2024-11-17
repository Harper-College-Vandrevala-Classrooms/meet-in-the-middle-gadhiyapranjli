#include "median.hpp"
#include <stdexcept>
#include <vector>
#include <string>
#include <cstdio> 
#include <sstream>

double calculateMedian(const std::vector<int>& data) {
    size_t n = data.size();
    if (n == 0) {
        throw std::invalid_argument("Dataset is empty. Cannot calculate the median.");
    }

    if (n % 2 == 1) {
        return data[n / 2];
    } else {
        return (data[n / 2 - 1] + data[n / 2]) / 2.0;
    }
}

std::vector<int> readDataFromFile(const std::string& filename) {
    FILE* file = fopen(filename.c_str(), "r");
    if (!file) {
        throw std::runtime_error("Unable to open file: " + filename);
    }

    char buffer[1024];
    std::vector<int> data;

    if (fgets(buffer, sizeof(buffer), file)) {
        std::stringstream ss(buffer);
        std::string token;
        while (std::getline(ss, token, ',')) {
            data.push_back(std::stoi(token));
        }
    }

    fclose(file);
    return data;
}
