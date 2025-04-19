/**
 *  Alex Carbajal
 *  CPT_S 322, Spring 2025
 *  Turing Machine
 */

#ifndef TURING_MACHINE_H
#define TURING_MACHINE_H

#include "final_states.h"
#include "input_alphabet.h"
#include "states.h"
#include "tape.h"
#include "tape_alphabet.h"
#include "transition_function.h"
#include "utilities.h"
#include <string>
#include <vector>
using namespace std;

// Keywords that MUST appear in this order in a Turing machine definition file
#define STATES "STATES:"
#define INPUT_ALPHABET "INPUT_ALPHABET:"
#define TAPE_ALPHABET "TAPE_ALPHABET:"
#define TRANSITION_FUNCTION "TRANSITION_FUNCTION:"
#define INITIAL_STATE "INITIAL_STATE:"
#define BLANK_CHARACTER "BLANK_CHARACTER:"
#define FINAL_STATES "FINAL_STATES:"

// Lengths of the keywords
#define STATES_LENGTH 7
#define INPUT_ALPHABET_LENGTH 15
#define TAPE_ALPHABET_LENGTH 14
#define TRANSITION_FUNCTION_LENGTH 20
#define INITIAL_STATE_LENGTH 14
#define BLANK_CHARACTER_LENGTH 16
#define FINAL_STATES_LENGTH 13

class Turing_Machine {
private:
  Utilities utilities;
  Tape tape;
  Input_Alphabet input_alphabet;
  Tape_Alphabet tape_alphabet;
  Transition_Function transition_function;
  States states;
  Final_States final_states;
  vector<string> description;
  string initial_state;
  string current_state;
  string original_input_string;
  int number_of_transitions;
  bool valid;
  bool used;
  bool operating;
  bool accepted;
  bool rejected;

public:
  Turing_Machine(string definition_file_name);
  void view_definition() const;
  void view_instantaneous_description(int maximum_number_of_cells) const;
  void initialize(string input_string);
  void perform_transitions(int maximum_number_of_transitions);
  void terminate_operation();
  string input_string() const;
  int total_number_of_transitions() const;
  bool is_valid_definition() const;
  bool is_valid_input_string(string value) const;
  bool is_used() const;
  bool is_operating() const;
  bool is_accepted_input_string() const;
  bool is_rejected_input_string() const;
};

#endif
