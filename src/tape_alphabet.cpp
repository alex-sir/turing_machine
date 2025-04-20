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
        cout << "Error: Duplicate tape alphabet value\n";
        valid = false;
      }
    } else {
      cout << "Error: Illegal tape alphabet value\n";
      valid = false;
    }
  }
  if (uppercase(value) != "TRANSITION_FUNCTION:") {
    cout << "Error: Missing keyword after tape alphabet\n";
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
