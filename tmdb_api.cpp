#include "tmdb_api.h"
#include <iostream>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

const std::string API_BASE_URL = "https://api.themoviedb.org/3/movie/";
const std::string API_KEY = std::getenv("TMDB_API_KEY") ? std::getenv("TMDB_API_KEY") : "";

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* out) {
    size_t totalSize = size * nmemb;
    out->append((char*)contents, totalSize);
    return totalSize;
}

std::string fetchMovies(const std::string& type) {
    if (API_KEY.empty()) {
        throw std::runtime_error("API key is missing. Set the TMDB_API_KEY environment variable.");
    }

    std::string endpoint;
    if (type == "popular") {
        endpoint = "popular";
    } else if (type == "top") {
        endpoint = "top_rated";
    } else if (type == "upcoming") {
        endpoint = "upcoming";
    } else if (type == "playing") {
        endpoint = "now_playing";
    } else {
        throw std::invalid_argument("Invalid type provided. Use '--help' for valid options.");
    }

    std::string url = API_BASE_URL + endpoint + "?api_key=" + API_KEY;

    CURL* curl = curl_easy_init();
    if (!curl) {
        throw std::runtime_error("Failed to initialize cURL.");
    }

    std::string response;
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        curl_easy_cleanup(curl);
        throw std::runtime_error("cURL request failed: " + std::string(curl_easy_strerror(res)));
    }

    curl_easy_cleanup(curl);
    return response;
}

std::vector<std::string> parseMovies(const std::string& jsonResponse) {
    using json = nlohmann::json;

    std::vector<std::string> movieTitles;
    try {
        auto parsed = json::parse(jsonResponse);
        if (parsed.contains("results")) {
            for (const auto& movie : parsed["results"]) {
                if (movie.contains("title")) {
                    movieTitles.push_back(movie["title"].get<std::string>());
                }
            }
        } else {
            throw std::runtime_error("Unexpected API response format.");
        }
    } catch (const std::exception& e) {
        throw std::runtime_error("Failed to parse JSON response: " + std::string(e.what()));
    }

    return movieTitles;
}

