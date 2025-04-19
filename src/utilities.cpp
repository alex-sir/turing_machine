/**
 *  Alex Carbajal
 *  CPT_S 322, Spring 2025
 *  Turing Machine
 */

#include "../include/utilities.h"

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

bool Utilities::is_valid_arguments(int argc) {
  if (argc < 2 || argc > 2) {
    cout << "Usage: tm FILENAME\n"
         << "You must provide one FILENAME." << endl;
    return false;
  }
  return true;
}

void Utilities::trim_whitespace(string &str) {
  // Leading whitespace
  size_t non_whitespace = str.find_first_not_of(WHITESPACE);
  if (non_whitespace != string::npos)
    str.erase(0, non_whitespace);

  // Trailing whitespace
  non_whitespace = str.find_last_not_of(WHITESPACE);
  if (non_whitespace != string::npos)
    str.erase(non_whitespace + 1);
}

bool Utilities::is_all_whitespace(string &str) {
  bool all_whitespace = true;
  // Check all characters in line for whitespace
  for (char c : str) {
    if (!isspace(c)) {
      all_whitespace = false;
      break;
    }
  }

  return all_whitespace;
}

bool Utilities::is_command_all_whitespace(string &command) {
  bool all_whitespace = is_all_whitespace(command);
  // Treat command as an empty response
  if (all_whitespace)
    command.erase(0, command.length());
  return all_whitespace;
}

string Utilities::to_uppercase(const string &str) {
  string line_uppercase = str;
  transform(line_uppercase.begin(), line_uppercase.end(),
            line_uppercase.begin(), ::toupper);
  return line_uppercase;
}

bool Utilities::is_valid_command(string &command) {
  bool all_whitespace = false;
  getline(cin, command);
  trim_whitespace(command);
  all_whitespace = is_command_all_whitespace(command);

  // Command is valid if it has no whitespace or is all whitespace
  if ((command.find(WHITESPACE) == string::npos) || all_whitespace)
    return true;
  return false;
}

void Utilities::invalid_command(void) {
  cout << "\nInvalid command. Enter 'h' for help.\n" << endl;
}
