# TMDB CLI Tool

An CLI application to use TMDB API to fetch movie information and display it in the terminal.

## Description

The **TMDB CLI Tool** is a simple command-line interface (CLI) application that interacts with the [TMDB API](https://www.themoviedb.org/documentation/api) to fetch and display movie information directly in your terminal. This project allows users to explore popular, top-rated, upcoming, and now-playing movies with ease.

[Project Description Link](https://roadmap.sh/projects/tmdb-cli)

---

## Features

- Fetch and display lists of movies:
  - **Popular Movies**
  - **Top Rated Movies**
  - **Upcoming Movies**
  - **Now Playing Movies**
- Command-line interface for quick and seamless interaction.
- Graceful handling of errors such as API failures or network issues.
- Clear and intuitive command-line arguments.

---

## Installation

### Prerequisites
- **C++ Compiler** (e.g., GCC or Clang)
- **CMake** (Optional but recommended for build automation)
- **cURL Library** (Required for HTTP requests)
- **JSON Library** for parsing JSON responses (e.g., [nlohmann/json](https://github.com/nlohmann/json))

### Steps

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/tmdb-cli-tool.git
   cd tmdb-cli-tool
   ```

2. Build the application:
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

3. Obtain an API key from [The Movie Database API](https://www.themoviedb.org/documentation/api) and note it down.

4. Set your API key as an environment variable:
   ```bash
   export TMDB_API_KEY=your_api_key_here
   ```

---

## Usage

Run the application from the command line with the desired movie type:

```bash
./tmdb-app --type "popular"
```

### Supported Arguments
| Argument         | Description                 |
|------------------|-----------------------------|
| `--type`         | Specify the type of movies to display. Possible values: `playing`, `popular`, `top`, `upcoming`. |
| `--help`         | Display help information about the CLI tool.            |

### Examples
- Fetch now playing movies:
  ```bash
  ./tmdb-app --type "playing"
  ```

- Fetch popular movies:
  ```bash
  ./tmdb-app --type "popular"
  ```

---

## Error Handling

- **Network Issues**: Displays a message indicating a failure to connect to the API.
- **Invalid API Key**: Prompts the user to verify their API key.
- **Invalid Command**: Guides the user on the correct usage of the CLI tool with `--help`.

---

## Development

### Dependencies
The project depends on the following libraries:
- **cURL**: For making HTTP requests.
- **nlohmann/json**: For parsing JSON responses.

Ensure these are installed before building the project.

### Code Structure
- `main.cpp`: Entry point of the application.
- `tmdb_api.cpp/h`: Handles API interactions.
- `cli_parser.cpp/h`: Handles command-line argument parsing.
- `utils.cpp/h`: Utility functions for error handling and output formatting.
