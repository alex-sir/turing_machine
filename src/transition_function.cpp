/**
 *  Alex Carbajal
 *  CPT_S 322, Spring 2025
 *  Turing Machine Implementation
 */

#include "transition_function.h"
#include "direction.h"
#include "final_states.h"
#include "states.h"
#include "tape_alphabet.h"
#include "transition.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Transition_Function::load(ifstream &definition, bool &valid) {}

void Transition_Function::validate(const Tape_Alphabet &tape_alphabet,
                                   const States &states,
                                   const Final_States &final_states,
                                   bool &valid) const {
  for (int index = 0; index < transitions.size(); ++index) {
    // if (final_states.is_element(transitions[index].source_state())) {
    //   cout << "Source state " << transitions[index].source_state()
    //        << " is in final states.\n";
    //   valid = false;
    // }
    // if (!states.is_element(transitions[index].source_state())) {
    //   cout << "Source state" << transitions[index].source_state()
    //        << " is not in states.\n";
    //   valid = false;
    // }
    // if (!tape_alphabet.is_element(transitions[index].read_character())) {
    //   cout << "Read character " << transitions[index].read_character()
    //        << " is not in tape alphabet.\n";
    //   valid = false;
    // }
    // if (!states.is_element(transitions[index].destination_state())) {
    //   cout << "Destination state" << transitions[index].destination_state()
    //        << " is not in states.\n";
    //   valid = false;
    // }
    // if (!tape_alphabet.is_element(transitions[index].write_character())) {
    //   cout << "Write character " << transitions[index].write_character()
    //        << " is not in tape alphabet.\n";
    //   valid = false;
    // }
  }
};

void Transition_Function::view() const {}

void Transition_Function::find_transition(
    string source_state, char read_character, string &destination_state,
    char &write_character, direction &move_direction, bool &found) const {
  for (int index = 0; index < transitions.size(); ++index)
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
