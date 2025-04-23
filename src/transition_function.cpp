/**
 *  Alex Carbajal
 *  CPT_S 322, Spring 2025
 *  Turing Machine
 */

#include "../include/transition_function.h"
#include "../include/direction.h"
#include "../include/final_states.h"
#include "../include/states.h"
#include "../include/tape_alphabet.h"
#include "../include/transition.h"
#include "../include/uppercase.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Transition_Function::load(ifstream &definition, bool &valid) {
  string source = "";
  char read = '\0';
  string destination = "";
  char write = '\0';
  direction move = '\0';
  bool is_redefined = false;

  while ((definition >> source) && (uppercase(source) != "INITIAL_STATE:") &&
         (definition >> read >> destination >> write >> move)) {
    if (uppercase(move) != 'L' && uppercase(move) != 'R') {
      cout << "Warning: Move direction is not left or right" << endl;
      valid = false;
    }
    // Check if a transition is being redefined (not allowed)
    for (const Transition &transition : transitions) {
      if (transition.source_state() == source &&
          transition.read_character() == read) {
        cout << "Warning: Redefined transition function" << endl;
        is_redefined = true;
        valid = false;
      }
    }
    if (!is_redefined)
      transitions.emplace_back(
          Transition(source, read, destination, write, move));
    else
      is_redefined = false;
  }
  if (uppercase(source) != "INITIAL_STATE:") {
    cout << "Warning: Missing keyword after transition functions" << endl;
    valid = false;
  }
}

void Transition_Function::validate(const Tape_Alphabet &tape_alphabet,
                                   const States &states,
                                   const Final_States &final_states,
                                   bool &valid) const {
  for (size_t index = 0; index < transitions.size(); ++index) {
    // Transition from a final state not allowed
    if (final_states.is_element(transitions[index].source_state())) {
      cout << "Warning: Source state " << transitions[index].source_state()
           << " is in final states" << endl;
      valid = false;
    }
    // Source state not found in the set of states
    if (!states.is_element(transitions[index].source_state())) {
      cout << "Warning: Source state " << transitions[index].source_state()
           << " is not in states" << endl;
      valid = false;
    }
    // Read character not found in the tape alphabet
    if (!tape_alphabet.is_element(transitions[index].read_character())) {
      cout << "Warning: Read character " << transitions[index].read_character()
           << " is not in tape alphabet" << endl;
      valid = false;
    }
    // Destination state not found in set of states
    if (!states.is_element(transitions[index].destination_state())) {
      cout << "Warning: Destination state "
           << transitions[index].destination_state() << " is not in states"
           << endl;
      valid = false;
    }
    // Write character not found in the tape alphabet
    if (!tape_alphabet.is_element(transitions[index].write_character())) {
      cout << "Warning: Write character "
           << transitions[index].write_character() << " is not in tape alphabet"
           << endl;
      valid = false;
    }
  }
}

void Transition_Function::view() const {
  for (size_t index = 0; index < transitions.size(); ++index) {
    cout << "δ(" << transitions[index].source_state() << ", "
         << transitions[index].read_character() << ") = ("
         << transitions[index].destination_state() << ", "
         << transitions[index].write_character() << ", "
         << transitions[index].move_direction() << ")" << endl;
  }
  cout << endl;
}

void Transition_Function::find_transition(
    string source_state, char read_character, string &destination_state,
    char &write_character, direction &move_direction, bool &found) const {
  for (int index = 0; index < static_cast<int>(transitions.size()); ++index)
    if ((transitions[index].source_state() == source_state) &&
        (transitions[index].read_character() == read_character)) {
      destination_state = transitions[index].destination_state();
      write_character = transitions[index].write_character();
      move_direction = transitions[index].move_direction();
      found = true;
      return;
    }
  found = false;
}
