/**
 *  Alex Carbajal
 *  CPT_S 322, Spring 2025
 *  Turing Machine
 */

#include "../include/turing_machine.h"
#include "../include/uppercase.h"
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Turing_Machine::Turing_Machine(string definition_file_name) {
  ifstream definition(definition_file_name + ".def");
  if (!definition) {
    cout << "Error: Could not open Turing machine definition file "
         << definition_file_name + ".def" << endl;
    exit(EXIT_FAILURE);
  }

  string value = "";
  bool valid = true;
  // Description
  while ((definition >> value) && (uppercase(value) != "STATES:"))
    description.push_back(value);
  if (value != "STATES:") {
    cout << "Error: Missing keyword after description\n";
    valid = false;
  }
  // Keywords
  states.load(definition, valid);
  input_alphabet.load(definition, valid);
  tape_alphabet.load(definition, valid);
  transition_function.load(definition, valid);
  // Initial state
  definition >> initial_state;
  definition >> value;
  if (value != "BLANK_CHARACTER:") {
    cout << "Error: Missing keyword after initial state\n";
    valid = false;
  }
  // Blank character
  tape.load(definition, valid);
  final_states.load(definition, valid);
  definition.close();
  // Check that the Turing machine definition file is fully valid
  valid = is_valid_definition();

  if (!valid)
    exit(EXIT_FAILURE);
}

void Turing_Machine::view_definition() const {
  // Description
  cout << endl;
  for (size_t word = 0; word < description.size(); ++word) {
    cout << description[word];
    if (word != description.size() - 1)
      cout << " ";
  }
  cout << endl << endl;
  // Keywords
  states.view();
  input_alphabet.view();
  tape_alphabet.view();
  transition_function.view();
  cout << "q0 = " << initial_state << endl << endl;
  tape.view();
  final_states.view();
}

bool Turing_Machine::is_valid_definition() const {
  bool valid = true;
  input_alphabet.validate(tape_alphabet, valid);
  transition_function.validate(tape_alphabet, states, final_states, valid);
  tape.validate(input_alphabet, tape_alphabet, valid);
  final_states.validate(states, valid);
  return valid;
}

bool Turing_Machine::is_valid_input_string(string value) const {
  bool valid = true;
  // Empty string represented by '\'
  if (value.length() == 1 && value[0] == '\\')
    return valid;
  /* String is invalid if it satisfies any of the following
   * Empty line
   * All whitespace
   * Contains leading/trailing whitespace
   */
  if (value.empty() ||
      all_of(value.begin(), value.end(), [](char ch) { return isspace(ch); }) ||
      isspace(value.front()) || isspace(value.back())) {
    cout << "Error: Input string is empty or contains leading/trailing "
            "whitespace"
         << endl;
    valid = false;
  }
  // String is invalid if it contains characters not in the input alphabet
  for (char ch : value) {
    if (!input_alphabet.is_element(ch) && !isspace(ch)) {
      cout << "Error: Input string contains character not in input alphabet"
           << endl;
      valid = false;
      break;
    }
  }
  return valid;
}
