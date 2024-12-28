#include "utils.h"
#include <iostream>

void handleError(const std::string& errorMessage) {
    std::cerr << "Error: " << errorMessage << std::endl;
    exit(1);
}

void printMovies(const std::vector<std::string>& movies) {
    if (movies.empty()) {
        std::cout << "No movies found for the selected category." << std::endl;
        return;
    }

    std::cout << "Movies:" << std::endl;
    std::cout << "-----------------------------" << std::endl;

    int index = 1;
    for (const auto& movie : movies) {
        std::cout << index++ << ". " << movie << std::endl;
    }

    std::cout << "-----------------------------" << std::endl;
}
