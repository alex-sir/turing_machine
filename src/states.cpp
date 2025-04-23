/**
 *  Alex Carbajal
 *  CPT_S 322, Spring 2025
 *  Turing Machine
 */

#include "../include/states.h"
#include "../include/uppercase.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void States::load(ifstream &definition, bool &valid) {
  string value;
  while ((definition >> value) && (uppercase(value) != "INPUT_ALPHABET:")) {
    for (const char ch : value) {
      // State must be upper & lower case letters, digits, underscores, &
      // hyphens
      if (!isalnum(ch) && ch != '_' && ch != '-') {
        cout << "Warning: Illegal state" << endl;
        valid = false;
      }
    }
    // No duplicate states allowed
    if (!is_element(value))
      names.push_back(value);
    else {
      cout << "Warning: Duplicate state" << endl;
      valid = false;
    }
  }
  // Make sure the next keyword follows
  if (uppercase(value) != "INPUT_ALPHABET:") {
    cout << "Warning: Missing keyword after states" << endl;
    valid = false;
  }
}

void States::view(void) const {
  cout << "Q = {";
  for (size_t name = 0; name < names.size(); ++name) {
    cout << names[name];
    // Don't include the comma and space for the last state
    if (name != names.size() - 1)
      cout << ", ";
  }
  cout << "}" << endl << endl;
}

bool States::is_element(string value) const {
  for (const string &name : names) {
    if (name == value)
      return true;
  }
  return false;
}
