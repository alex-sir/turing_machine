/**
 *  Alex Carbajal
 *  CPT_S 322, Spring 2025
 *  Turing Machine Implementation
 */

#include "tape.h"
#include "direction.h"
#include "input_alphabet.h"
#include "tape_alphabet.h"
// #include "uppercase.h" // contains a custom function to convert a string to
// all uppercase
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

Tape::Tape() : cells(" "), current_cell(0), blank_character(' ') {}

void Tape::load(ifstream &definition, bool &valid) {
  string value;
  if ((definition >> value) && (value.length() == 1) && (value[0] != '\\') &&
      (value[0] != '[') && (value[0] != ']') && (value[0] != '<') &&
      (value[0] != '>') && (value[0] >= '!') && (value[0] <= '~'))
    blank_character = value[0];
  else {
    cout << "Illegal blank character.\n";
    valid = false;
  }
  // if ((!(definition >> value)) || (uppercase(value) != "FINAL_STATES")) {
  //   cout << "Missing keyword after blank character.\n";
  //   valid = false;
  // }
}

// void Tape::validate(const Input_Alphabet &input_alphabet,
//                     const Tape_Alphabet &tape_alphabet, bool &valid) const {
//   if (input_alphabet.is_element(blank_character)) {
//     cout << "Blank character " << blank_character << " is in input
//     alphabet.\n"; valid = false;
//   }
//   if (!tape_alphabet.is_element(blank_character)) {
//     cout << "Blank character " << blank_character
//          << "is not in tape alphabet.\n";
//     valid = false;
//   }
// }

void Tape::view() const { cout << "B = " << blank_character << "\n\n"; }

void Tape::initialize(string input_string) {
  cells = input_string + blank_character;
  current_cell = 0;
}
