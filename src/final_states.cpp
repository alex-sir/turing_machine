/**
 *  Alex Carbajal
 *  CPT_S 322, Spring 2025
 *  Turing Machine
 */

#include "../include/final_states.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Final_States::load(ifstream &definition, bool &valid) {
  string value;
  while (definition >> value) {
    for (const char ch : value) {
      // Final states must be upper & lower case letters, digits, underscores, &
      // hyphens
      if (!isalnum(ch) && ch != '_' && ch != '-') {
        cout << "Warning: Illegal final state \"" << value << "\"" << endl;
        valid = false;
      }
    }
    // No duplicate final states allowed
    if (!is_element(value))
      names.push_back(value);
    else {
      cout << "Warning: Duplicate final state \"" << value << "\"" << endl;
      valid = false;
    }
  }
}

void Final_States::validate(const States &states, bool &valid) const {
  for (const string &name : names) {
    if (!states.is_element(name)) {
      cout << "Warning: Value \"" << name << "\" in final states not in states"
           << endl;
      valid = false;
    }
  }
}

void Final_States::view(void) const {
  cout << "F = {";
  for (size_t name = 0; name < names.size(); ++name) {
    cout << names[name];
    if (name != names.size() - 1)
      cout << ", ";
  }
  cout << "}" << endl << endl;
}

bool Final_States::is_element(string value) const {
  for (const string &name : names) {
    if (name == value)
      return true;
  }
  return false;
}
