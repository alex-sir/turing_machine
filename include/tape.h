/**
 *  Alex Carbajal
 *  CPT_S 322, Spring 2025
 *  Turing Machine
 */

#ifndef TAPE_H
#define TAPE_H

#include "direction.h"
#include "input_alphabet.h"
#include "tape_alphabet.h"
#include <fstream>
#include <string>
using namespace std;

class Tape {
private:
  string cells;
  int current_cell;
  char blank_character;

public:
  /**
   * @brief Constructor that initializes a Tape with default values
   */
  Tape();
  /**
   * @brief Read the blank character from the Turing machine definition file
   *
   * @param definition Turing machine definition file
   * @param valid true if the blank character is loaded
   *              false if the blank character is not loaded
   */
  void load(ifstream &definition, bool &valid);
  /**
   * @brief Determine if the blank character is in the tape alphabet but not the
   *        input alphabet
   *
   * @param input_alphabet Input alphabet to check
   * @param tape_alphabet Tape alphabet to check
   * @param valid true if the blank character is valid
   *              false if the blank character is not valid
   */
  void validate(const Input_Alphabet &input_alphabet,
                const Tape_Alphabet &tape_alphabet, bool &valid) const;
  /**
   * @brief Display the blank character
   */
  void view() const;
  /**
   * @brief Initialize the TM tape, replacing the previous contents of the tape
   *
   * @param input_string Input string to initialize the TM tape with
   */
  void initialize(string input_string);
  /**
   * @brief Determine if an update of the TM tape is possible & perform an
   *        update
   *
   * @param write_character Character to write on the tape in the current cell
   * @param move_direction Direction to move the current cell
   */
  void update(char write_character, direction move_direction);
  /**
   * @brief Return a string of a specified number of cells of the Turing machine
   *        tape from the left of the current cell (excludes current cell)
   *
   * @param maximum_number_of_cells Number of cells to the left of the current
   *                                cell
   * @return string String of the specified cells
   */
  string left(int maximum_number_of_cells) const;
  /**
   * @brief Return a string of a specified number of cells of the Turing machine
   *        tape from the right of the current cell (includes current cell)
   *
   * @param maximum_number_of_cells Number of cells to the right of the current
   *                                cell
   * @return string String of the specified cells
   */
  string right(int maximum_number_of_cells) const;
  /**
   * @brief Return the character contained in the current cell
   *
   * @return char Character in the current cell
   */
  char current_character() const;
  /**
   * @brief Return whether the current cell is the first cell of the tape
   *
   * @return bool true if the current cell is the first cell
   *              false if the current cell is not the first cell
   */
  bool is_first_cell() const;
};

#endif
