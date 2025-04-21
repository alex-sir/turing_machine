/**
 *  Alex Carbajal
 *  CPT_S 322, Spring 2025
 *  Turing Machine
 */

#ifndef TRANSITION_H
#define TRANSITION_H

#include "direction.h"
#include <string>
using namespace std;

class Transition {
private:
  string source;
  char read;
  string destination;
  char write;
  direction move;

public:
  Transition(string source_state, char read_character, string destination_state,
             char write_character, direction move_direction);
  /**
   * @brief Return the start state of the transition function
   */
  string source_state() const;
  /**
   * @brief Return the staring character of the transition function
   */
  char read_character() const;
  /**
   * @brief Return the end state of the transition function
   */
  string destination_state() const;
  /**
   * @brief Return the character to write over the current tape cell
   */
  char write_character() const;
  /**
   * @brief Return the direction to move the tape head (left or right)
   */
  direction move_direction() const;
};

#endif
