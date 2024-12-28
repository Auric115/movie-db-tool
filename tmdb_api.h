#ifndef TMDB_API_H
#define TMDB_API_H

#include <string>
#include <vector>

std::string fetchMovies(const std::string& type);
// Fetches movie data from the TMDB API for the specified type.

std::vector<std::string> parseMovies(const std::string& jsonResponse);
// Parses a JSON response to extract movie titles.

#endif // TMDB_API_H
