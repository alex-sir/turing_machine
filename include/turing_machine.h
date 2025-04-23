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

class Turing_Machine {
private:
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
  /**
   * @brief Constructor that initializes a Turing machine based on a definition
   *        file
   *
   * @param definition_file_name Name of the Turing machine definition file
   */
  Turing_Machine(string definition_file_name);
  /**
   * @brief Display the definition of the Turing machine in a readable form
   */
  void view_definition() const;
  void view_instantaneous_description(int maximum_number_of_cells) const;
  void initialize(string input_string);
  void perform_transitions(int maximum_number_of_transitions);
  void terminate_operation();
  /**
   * @brief Return the original input string that is currently being worked on
   *
   * @return string Original input string
   */
  string input_string() const;
  /**
   * @brief Return the number of transitions that have been performed so far on
   *        the input string that is currently being worked on
   *
   * @return int Total number of transitions
   */
  int total_number_of_transitions() const;
  /**
   * @brief Return whether the Turing machine definition is fully valid
   *
   * @return bool true if the definition is fully valid
   *              false if the definition is not fully vaild
   */
  bool is_valid_definition() const;
  /**
   * @brief Return whether an input string conforms to the rules of validity
   *
   * @return bool true if the input string is valid
   *              false if the input string is not valid
   */
  bool is_valid_input_string(string value) const;
  /**
   * @brief Return whether the Turing machine has been used at least once
   *
   * @return bool true if the Turing machine has been used at least once
   *              false if the Turing machine has not been used at least once
   */
  bool is_used() const;
  /**
   * @brief Return whether the Turing machine is currently operating on an input
   *        string
   *
   * @return bool true if the Turing machine is operating on an input string
   *              false if the Turing machine is not operating on an input
   *              string
   */
  bool is_operating() const;
  /**
   * @brief Return whether the most recent input string that was operated on was
   *        accepted
   *
   * @return bool true if the most recent input string was accepted
   *              false if the most recent input string was not accepted
   */
  bool is_accepted_input_string() const;
  /**
   * @brief Return whether the most recent input string that was operated on was
   *        rejected
   *
   * @return bool true if the most recent input string was rejected
   *              false if the most recent input string was not rejected
   */
  bool is_rejected_input_string() const;
};

#endif
