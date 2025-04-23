/**
 *  Alex Carbajal
 *  CPT_S 322, Spring 2025
 *  Turing Machine
 */

#include "../include/utilities.h"
#include "../include/whitespace.h"
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

bool Utilities::is_command_all_whitespace(string &command) {
  bool all_whitespace = is_all_whitespace(command);

  // Treat command as an empty response
  if (all_whitespace)
    command.erase(0, command.length());
  return all_whitespace;
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
