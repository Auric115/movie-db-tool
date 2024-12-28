#include "cli_parser.h"
#include <iostream>
#include <stdexcept>

std::string parseArguments(int argc, char* argv[]) {
    if (argc < 3) {
        throw std::invalid_argument("Insufficient arguments provided. Use '--help' for usage details.");
    }

    for (int i = 1; i < argc; ++i) {
        if (std::string(argv[i]) == "--type") {
            if (i + 1 < argc) {
                return argv[i + 1];
            } else {
                throw std::invalid_argument("Missing value for '--type'. Use '--help' for usage details.");
            }
        } else if (std::string(argv[i]) == "--help") {
            printHelp();
            exit(0);
        }
    }

    throw std::invalid_argument("Unknown arguments provided. Use '--help' for usage details.");
}

void printHelp() {
    std::cout << "TMDB CLI Tool - Usage Instructions\n";
    std::cout << "-----------------------------------\n";
    std::cout << "Usage:\n";
    std::cout << "  tmdb-app --type <type>\n";
    std::cout << "\nAvailable Types:\n";
    std::cout << "  playing   - Now Playing Movies\n";
    std::cout << "  popular   - Popular Movies\n";
    std::cout << "  top       - Top Rated Movies\n";
    std::cout << "  upcoming  - Upcoming Movies\n";
    std::cout << "\nExamples:\n";
    std::cout << "  tmdb-app --type popular\n";
    std::cout << "  tmdb-app --type playing\n";
}

