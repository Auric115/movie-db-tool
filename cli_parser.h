#ifndef CLI_PARSER_H
#define CLI_PARSER_H

#include <string>

// Function declarations
std::string parseArguments(int argc, char* argv[]);
// Parses the command-line arguments to extract the movie type.

void printHelp();
// Prints usage instructions for the CLI tool.

#endif // CLI_PARSER_H

