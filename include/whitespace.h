/**
 *  Alex Carbajal
 *  CPT_S 322, Spring 2025
 *  Turing Machine
 */

#ifndef WHITESPACE_H
#define WHITESPACE_H

#include <cctype>
#include <iostream>
#include <string>
using namespace std;

// All whitespace characters as defined in isspace()
#define WHITESPACE " \f\n\r\t\v"

/**
 * @brief Check whether a string consists of only whitespace
 *
 * @param value String to check for all whitespace
 * @return bool true if the string is all whitespace
 *              false if the string is not all whitespace
 */
inline bool is_all_whitespace(const string &value) {
  for (const char ch : value) {
    if (!isspace(ch))
      return false;
  }
  return true;
}

/**
 * @brief Trim leading & trailing whitespace from a string
 *
 * @param str String to remove whitespace from
 */
inline void trim_whitespace(string &str) {
  // Leading whitespace
  size_t non_whitespace = str.find_first_not_of(WHITESPACE);
  if (non_whitespace != string::npos)
    str.erase(0, non_whitespace);

  // Trailing whitespace
  non_whitespace = str.find_last_not_of(WHITESPACE);
  if (non_whitespace != string::npos)
    str.erase(non_whitespace + 1);
}

#endif
