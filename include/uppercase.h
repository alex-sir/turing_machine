/**
 *  Alex Carbajal
 *  CPT_S 322, Spring 2025
 *  Turing Machine
 */

#ifndef UPPERCASE_H
#define UPPERCASE_H

#include <algorithm>
#include <string>
using namespace std;

/**
 * @brief Convert all the characters of a string to uppercase
 *
 * @param str String to convert to all uppercase
 * @return string Modified string with all uppercase characters
 */
inline string uppercase(const string &str) {
  string str_uppercase = str;
  transform(str_uppercase.begin(), str_uppercase.end(), str_uppercase.begin(),
            ::toupper);
  return str_uppercase;
}

#endif
