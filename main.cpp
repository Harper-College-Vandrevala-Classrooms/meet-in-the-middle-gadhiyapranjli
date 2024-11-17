#include <iostream>
#include <vector>
#include <string>
#include "median.hpp"

int main() {
    std::string filename;
    std::cout << "Enter the filename: ";
    std::cin >> filename;

    try {
        std::vector<int> data = readDataFromFile(filename);
        double median = calculateMedian(data);
        std::cout << "The median of the dataset is " << median << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}






