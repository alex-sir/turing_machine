/**
 *  Alex Carbajal
 *  CPT_S 322, Spring 2025
 *  Turing Machine
 */

#include "../include/turing_machine.h"
#include "../include/uppercase.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Turing_Machine::Turing_Machine(string definition_file_name) {
  ifstream definition(definition_file_name + ".def");
  if (!definition) {
    cout << "Error: Could not open Turing machine definition file "
         << definition_file_name + ".def" << endl;
    definition.close();
    exit(EXIT_FAILURE);
  }

  string value = "";
  bool valid = true;
  // Description
  while ((definition >> value) && (uppercase(value) != "STATES:"))
    description.push_back(value);
  if (value != "STATES:") {
    cout << "Error: Missing keyword after description\n";
    definition.close();
    exit(EXIT_FAILURE);
  }
  // Keywords
  states.load(definition, valid);
  input_alphabet.load(definition, valid);
  tape_alphabet.load(definition, valid);
  input_alphabet.validate(tape_alphabet, valid);
  // TRANSITION_FUNCTION
  // INITIAL_STATE
  // BLANK_CHARACTER
  // FINAL_STATES

  definition.close();
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
  states.view();
  input_alphabet.view();
  tape_alphabet.view();
}

bool Turing_Machine::is_valid_definition() const { return true; }
