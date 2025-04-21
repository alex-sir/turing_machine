/**
 *  Alex Carbajal
 *  CPT_S 322, Spring 2025
 *  Turing Machine
 */

#ifndef TRANSITION_FUNCTION_H
#define TRANSITION_FUNCTION_H

#include "direction.h"
#include "final_states.h"
#include "states.h"
#include "tape_alphabet.h"
#include "transition.h"
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Transition_Function {
private:
  vector<Transition> transitions;

public:
  /**
   * @brief Read the transition functions from a Turing machine definition file
   *
   * @param definition Turing machine definition file
   * @param valid true if the transition functions are valid
   *              false if the transition functions are invalid
   */
  void load(ifstream &definition, bool &valid);
  /**
   * @brief Determine if the transition functions are valid
   *
   * @param tape_alphabet Tape alphabet to use to verify the characters
   * @param states Set of states to use to verify the states
   * @param final_states Set of final states to use to verify the final states
   * @param valid true if the transition functions are valid
   *              false if the transition functions are not valid
   */
  void validate(const Tape_Alphabet &tape_alphabet, const States &states,
                const Final_States &final_states, bool &valid) const;
  /**
   * @brief Display the transition functions of the Turing machine
   */
  void view() const;
  /**
   * @brief Find the transition for a given state & character
   *
   * @param source_state Given state
   * @param read_character Given character
   * @param destination_state State to transition to
   * @param write_character Character to write
   * @param move_direction Direction to move
   * @param found true if valid transition function is identified
   *              false if no valid transition function is identified
   */
  void find_transition(string source_state, char read_character,
                       string &destination_state, char &write_character,
                       direction &move_direction, bool &found) const;
};

#endif
