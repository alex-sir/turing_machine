/**
 *  Alex Carbajal
 *  CPT_S 322, Spring 2025
 *  Turing Machine
 */

#ifndef UTILITIES_H
#define UTILITIES_H

#include <fstream>
#include <string>
using namespace std;

// All whitespace characters as defined in isspace()
#define WHITESPACE " \f\n\r\t\v"

class Utilities {
private:
public:
  /**
   * @brief Check if the number of arguments provided by the user is valid
   *
   * @param argc Number of arguments
   * @return bool true if the number of arugments is valid
   *              false if the number of arguments is not valid
   */
  bool is_valid_arguments(int argc);
  /**
   * @brief Trim leading & trailing whitespace from the string
   *
   * @param str String to remove whitespace from
   */
  void trim_whitespace(string &str);
  /**
   * @brief Check if a string contains only whitespace
   *
   * @param str String to check for only whitespace
   * @return bool true if the string contains only whitespace
   *              false if it contains non-whitespace characters
   */
  bool is_all_whitespace(string &str);
  /**
   * @brief Check if the command string contains only whitespace
   *
   * @param command String to check for only whitespace
   * @return bool true if the command string contains only whitespace
   *              false if it contains non-whitespace characters
   */
  bool is_command_all_whitespace(string &command);
  /**
   * @brief Convert all the characters of a string to uppercase
   *
   * @param str String to convert to all uppercase
   * @return string Modified string with all uppercase characters
   */
  string to_uppercase(const string &str);
  /**
   * @brief Obtain a command from the user and check if it is valid
   *
   * @param command String containing the command
   * @return bool true if the command is valid
   *              false if the command is invalid
   */
  bool is_valid_command(string &command);
  /**
   * @brief Display a message after user inputs an invalid command
   */
  void invalid_command(void);
};

#endif
