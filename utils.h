#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

void handleError(const std::string& errorMessage);
// Prints an error message and exits the program.

void printMovies(const std::vector<std::string>& movies);
// Prints the list of movies in a user-friendly format.

#endif // UTILS_H

