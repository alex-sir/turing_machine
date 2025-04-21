/**
 *  Alex Carbajal
 *  CPT_S 322, Spring 2025
 *  Turing Machine
 */

#include "../include/input_alphabet.h"
#include "../include/tape_alphabet.h"
#include "../include/uppercase.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Input_Alphabet::load(ifstream &definition, bool &valid) {
  string value;
  while ((definition >> value) && (uppercase(value) != "TAPE_ALPHABET:")) {
    // Input alphabet only consists of printable ASCII characters, excluding
    // reserved characters
    if ((value.length() == 1) && (value[0] != '\\') && (value[0] != '[') &&
        (value[0] != ']') && (value[0] != '<') && (value[0] != '>') &&
        (value[0] >= '!') && (value[0] <= '~')) {
      // No duplicate input alphabet values allowed
      if (!is_element(value[0]))
        alphabet.push_back(value[0]);
      else {
        cout << "Error: Duplicate input alphabet value\n";
        valid = false;
      }
    } else {
      cout << "Error: Illegal input alphabet value\n";
      valid = false;
    }
  }
  if (uppercase(value) != "TAPE_ALPHABET:") {
    cout << "Error: Missing keyword after input alphabet\n";
    valid = false;
  }
}

void Input_Alphabet::validate(Tape_Alphabet &tape_alphabet, bool &valid) const {
  // TODO: Add a check that ensures the blank character is not in the input
  // alphabet
  for (const char &current_value : alphabet) {
    if (!tape_alphabet.is_element(current_value)) {
      cout << "Error: Value in input alphabet not in tape alphabet\n";
      valid = false;
    }
  }
}

void Input_Alphabet::view(void) const {
  cout << "Σ = {";
  for (size_t value = 0; value < alphabet.size(); ++value) {
    cout << alphabet[value];
    if (value != alphabet.size() - 1)
      cout << ", ";
  }
  cout << "}" << endl << endl;
}
