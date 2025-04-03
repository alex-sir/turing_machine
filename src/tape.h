/**
 *  Alex Carbajal
 *  CPT_S 322, Spring 2025
 *  Turing Machine Implementation
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
  Tape();
  void load(ifstream &definition, bool &valid);
  void validate(const Input_Alphabet &input_alphabet,
                const Tape_Alphabet &tape_alphabet, bool &valid) const;
  void view() const;
  void initialize(string input_string);
  void update(char write_character, direction move_direction);
  void left(int maximum_number_of_cells) const;
  void right(int maximum_number_of_cells) const;
  char current_character() const;
  bool is_first_cell() const;
};

#endif
