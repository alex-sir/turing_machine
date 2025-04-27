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
        cout << "Warning: Duplicate input alphabet value '" << value << "'"
             << endl;
        valid = false;
      }
    } else {
      cout << "Warning: Illegal input alphabet value '" << value << "'" << endl;
      valid = false;
    }
  }
  if (uppercase(value) != "TAPE_ALPHABET:") {
    cout << "Warning: Missing keyword after input alphabet" << endl;
    valid = false;
  }
}

void Input_Alphabet::validate(const Tape_Alphabet &tape_alphabet,
                              bool &valid) const {
  for (const char &current_value : alphabet) {
    if (!tape_alphabet.is_element(current_value)) {
      cout << "Warning: Value '" << current_value
           << "' in input alphabet not in tape alphabet" << endl;
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

bool Input_Alphabet::is_element(char value) const {
  for (const char &current_value : alphabet) {
    if (current_value == value)
      return true;
  }
  return false;
}
