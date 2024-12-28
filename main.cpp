#include <iostream>
#include <vector>
#include <stdexcept>
#include "cli_parser.h"
#include "tmdb_api.h"
#include "utils.h"

int main(int argc, char* argv[]) {
    try {
        // Parse command-line arguments to get the movie type
        std::string type = parseArguments(argc, argv);

        // Fetch movies from the TMDB API
        std::string jsonResponse = fetchMovies(type);

        // Parse the JSON response to extract movie titles
        std::vector<std::string> movies = parseMovies(jsonResponse);

        // Print the movie titles to the terminal
        printMovies(movies);

    } catch (const std::invalid_argument& e) {
        handleError(std::string("Argument Error: ") + e.what());
    } catch (const std::runtime_error& e) {
        handleError(std::string("Runtime Error: ") + e.what());
    } catch (const std::exception& e) {
        handleError(std::string("Error: ") + e.what());
    }

    return 0;
}
