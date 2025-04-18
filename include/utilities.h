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

class Utilities {
private:
public:
  /**
   * @brief Check if the number of arguments provided by the user is valid
   *
   * @param argc Number of arguments
   * @return true if the number of arugments is valid
   *         false if the number of arguments is not valid
   */
  bool is_valid_arguments(int argc);
  bool is_valid_files(string filename);
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
   * @brief Obtain a command from the user and check if it is valid
   *
   * @param command String containing the command
   * @return true if the command is valid
   *         false if the command is invalid
   */
  bool is_valid_command(string &command);
  /**
   * @brief Display a message after user inputs an invalid command
   */
  void invalid_command(void);
};

#endif
