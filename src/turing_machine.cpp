/**
 *  Alex Carbajal
 *  CPT_S 322, Spring 2025
 *  Turing Machine
 */

#include "../include/turing_machine.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Turing_Machine::Turing_Machine(string definition_file_name) {
  ifstream definition_file(definition_file_name + ".def");
  if (!definition_file) {
    cerr << "Error: Could not open Turing machine definition file "
         << definition_file_name + ".def" << endl;
    exit(EXIT_FAILURE);
  }

  string definition_file_line = "";
  string definition_file_line_uppercase = "";
  size_t keyword_index = 0;

  // Description
  getline(definition_file, definition_file_line);
  definition_file_line += '\n';
  definition_file_line_uppercase = utilities.to_uppercase(definition_file_line);
  while ((keyword_index = definition_file_line_uppercase.find(STATES)) ==
         string::npos) {
    description.push_back(definition_file_line);
    getline(definition_file, definition_file_line);
    definition_file_line += '\n';
    definition_file_line_uppercase =
        utilities.to_uppercase(definition_file_line);
  }
  description.push_back(definition_file_line.substr(0, keyword_index));
  // STATES
  // INPUT_ALPHABET
  // TAPE_ALPHABET
  // TRANSITION_FUNCTION
  // INITIAL_STATE
  // BLANK_CHARACTER
  // FINAL_STATES

  definition_file.close();
}

void Turing_Machine::view_definition() const {
  cout << endl;
  for (size_t line = 0; line < description.size(); ++line)
    cout << description[line];
  cout << endl << endl;
}

bool Turing_Machine::is_valid_definition() const { return true; }
