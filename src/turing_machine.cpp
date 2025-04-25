/**
 *  Alex Carbajal
 *  CPT_S 322, Spring 2025
 *  Turing Machine
 */

#include "../include/turing_machine.h"
#include "../include/crash.h"
#include "../include/uppercase.h"
#include "../include/whitespace.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Turing_Machine::Turing_Machine(string definition_file_name) {
  ifstream definition(definition_file_name + ".def");
  if (!definition)
    throw Crash("Could not open Turing machine definition file " +
                definition_file_name + ".def");

  string value = "";
  bool valid = true;
  // Description
  while ((definition >> value) && (uppercase(value) != "STATES:"))
    description.push_back(value);
  if (value != "STATES:") {
    cout << "Warning: Missing keyword after description" << endl;
    valid = false;
  }
  // Keywords
  states.load(definition, valid);
  input_alphabet.load(definition, valid);
  tape_alphabet.load(definition, valid);
  transition_function.load(definition, valid);
  // Initial state
  definition >> initial_state;
  if (initial_state != "BLANK_CHARACTER:") {
    definition >> value;
    if (value != "BLANK_CHARACTER:") {
      cout << "Warning: Missing keyword after initial state" << endl;
      valid = false;
    }
  } else {
    cout << "Warning: Initial state is empty" << endl;
    valid = false;
  }
  if (!states.is_element(initial_state)) {
    cout << "Warning: Initial state is not in set of states" << endl;
    valid = false;
  }
  // Blank character
  tape.load(definition, valid);
  final_states.load(definition, valid);
  definition.close();
  // Check that the Turing machine definition file is fully valid
  valid = is_valid_definition();
  if (!valid)
    throw Crash("Invalid Turing machine definition file");

  used = false;
  operating = false;
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

void Turing_Machine::view_instantaneous_description(
    int maximum_number_of_cells) const {
  if (final_states.is_element(current_state)) {
  }
  cout << number_of_transitions << "." << tape.left(maximum_number_of_cells)
       << "[" << current_state << "]" << tape.right(maximum_number_of_cells)
       << endl;
}

void Turing_Machine::initialize(string input_string) {
  current_state = initial_state;
  original_input_string = input_string;
  number_of_transitions = 0;
  used = true;
  operating = true;
  accepted = false;
  rejected = false;
  tape.initialize(input_string);
}

void Turing_Machine::perform_transitions(int maximum_number_of_transitions) {
  // Case where initial state is also final state
  if (final_states.is_element(current_state)) {
    accepted = true;
    return;
  }

  string destination_state = "";
  char write_character = '\0';
  direction move_direction = '\0';
  bool found = false;
  for (int transition = 0; transition < maximum_number_of_transitions;
       ++transition) {
    transition_function.find_transition(current_state, tape.current_character(),
                                        destination_state, write_character,
                                        move_direction, found);
    // Update the tape if a transition function was found
    // Otherwise, reject the input string
    if (found) {
      tape.update(write_character, move_direction);
      current_state = destination_state;
      ++number_of_transitions;
    } else {
      rejected = true;
      return;
    }
    // Final state found, input string accepted
    if (final_states.is_element(current_state)) {
      accepted = true;
      return;
    }
  }
}

void Turing_Machine::terminate_operation() { operating = false; }

string Turing_Machine::input_string() const { return original_input_string; }

int Turing_Machine::total_number_of_transitions() const {
  return number_of_transitions;
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

  /* String is invalid if it satisfies any of the following:
   * Empty line
   * All whitespace
   * Contains leading/trailing whitespace
   */
  if (value.empty() || is_all_whitespace(value) || isspace(value.front()) ||
      isspace(value.back())) {
    cout << "Warning: Input string is empty or contains leading/trailing "
            "whitespace"
         << endl;
    valid = false;
  }

  // String is invalid if it contains characters not in the input alphabet
  for (char ch : value) {
    if (!input_alphabet.is_element(ch) && !isspace(ch)) {
      cout << "Warning: Input string contains character not in input alphabet"
           << endl;
      valid = false;
      break;
    }
  }
  return valid;
}

bool Turing_Machine::is_used() const { return used; }

bool Turing_Machine::is_operating() const { return operating; }

bool Turing_Machine::is_accepted_input_string() const { return accepted; }

bool Turing_Machine::is_rejected_input_string() const { return rejected; }
