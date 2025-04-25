/**
 *  Alex Carbajal
 *  CPT_S 322, Spring 2025
 *  Turing Machine
 */

#include "../include/tape_alphabet.h"
#include "../include/uppercase.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Tape_Alphabet::load(ifstream &definition, bool &valid) {
  string value;
  while ((definition >> value) &&
         (uppercase(value) != "TRANSITION_FUNCTION:")) {
    // Tape alphabet only consists of printable ASCII characters, excluding
    // reserved characters
    if ((value.length() == 1) && (value[0] != '\\') && (value[0] != '[') &&
        (value[0] != ']') && (value[0] != '<') && (value[0] != '>') &&
        (value[0] >= '!') && (value[0] <= '~')) {
      // No duplicate tape alphabet values allowed
      if (!is_element(value[0]))
        alphabet.push_back(value[0]);
      else {
        cout << "Warning: Duplicate tape alphabet value" << endl;
        valid = false;
      }
    } else {
      cout << "Warning: Illegal tape alphabet value" << endl;
      valid = false;
    }
  }
  if (uppercase(value) != "TRANSITION_FUNCTION:") {
    cout << "Warning: Missing keyword after tape alphabet" << endl;
    valid = false;
  }
  // Empty tape alphabet is not valid
  if (alphabet.empty()) {
    cout << "Warning: Tape alphabet is empty" << endl;
    valid = false;
  }
}

void Tape_Alphabet::view(void) const {
  cout << "Γ = {";
  for (size_t value = 0; value < alphabet.size(); ++value) {
    cout << alphabet[value];
    if (value != alphabet.size() - 1)
      cout << ", ";
  }
  cout << "}" << endl << endl;
}

bool Tape_Alphabet::is_element(char value) const {
  for (const char &current_value : alphabet) {
    if (current_value == value)
      return true;
  }
  return false;
}
