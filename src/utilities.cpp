/**
 *  Alex Carbajal
 *  CPT_S 322, Spring 2025
 *  Turing Machine
 */

#include "../include/utilities.h"

#include <iostream>
#include <string>
using namespace std;

void trim_whitespace(string &command) {
  // Leading whitespace
  size_t non_whitespace = command.find_first_not_of(WHITESPACE);
  if (non_whitespace != string::npos) {
    command.erase(0, non_whitespace);
  }

  // Trailing whitespace
  non_whitespace = command.find_last_not_of(WHITESPACE);
  if (non_whitespace != string::npos) {
    command.erase(non_whitespace + 1);
  }
}

bool is_all_whitespace(string &command) {
  bool all_whitespace = true;
  // Check all characters in command for whitespace
  for (char c : command) {
    if (!isspace(c)) {
      all_whitespace = false;
      break;
    }
  }

  // Treat command as an empty response
  if (all_whitespace) {
    command.erase(0, command.length());
  }
  return all_whitespace;
}

bool is_valid_command(string &command) {
  bool valid_command = false;
  bool all_whitespace = false;
  getline(cin, command);
  trim_whitespace(command);
  all_whitespace = is_all_whitespace(command);

  // Command is valid if it has no whitespace or is all whitespace
  if ((command.find(WHITESPACE) == string::npos) || all_whitespace) {
    valid_command = true;
  }
  return valid_command;
}
