/**
 *  Alex Carbajal
 *  CPT_S 322, Spring 2025
 *  Turing Machine
 */

#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
using namespace std;

// All whitespace characters as defined in isspace()
#define WHITESPACE " \f\n\r\t\v"

/**
 * @brief Trim leading & trailing whitespace from the command string
 *
 * @param command String to remove whitespace from
 */
void trim_whitespace(string &command);
/**
 * @brief Check if the command string contains only whitespace
 *
 * @param command String to check for only whitespace
 * @return true if the command string contains only whitespace
 *         false if it contains non-whitespace characters
 */
bool is_all_whitespace(string &command);
/**
 * @brief obtain a command from the user and check if it is valid
 *
 * @param command string containing the command
 * @return true if the command is valid
 *         false if the command is invalid
 */
bool is_valid_command(string &command);

#endif
