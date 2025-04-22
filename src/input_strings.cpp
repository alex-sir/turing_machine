/**
 *  Alex Carbajal
 *  CPT_S 322, Spring 2025
 *  Turing Machine
 */

#include "../include/input_strings.h"
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Input_Strings::Input_Strings(string input_string_file_name)
    : list({}), file_name(input_string_file_name + ".str"), changed(false) {}

void Input_Strings::insert(string input_string) {
  list.push_back(input_string);
  // TODO: changed should only be set to true when the user changes the list
  // when running the application, not when just reading the file
  changed = true;
}

void Input_Strings::view(void) {
  // Used to properly align the list
  size_t list_size_number_of_digits = to_string(list.size()).length();
  cout << endl;
  for (size_t index = 0; index < list.size(); ++index)
    cout << setw(list_size_number_of_digits) << index + 1 << ". " << list[index]
         << endl;
  cout << endl;
}

void Input_Strings::remove(int input_string_number) {
  // NOTE: Validating user input is done in the del() command in Commands
  list.erase(list.begin() + input_string_number);
  changed = true;
}

string Input_Strings::input_string(int input_string_number) {
  // NOTE: Validating user input is done in the del() command in Commands
  return list[input_string_number];
}

int Input_Strings::size(void) { return list.size(); }

bool Input_Strings::is_changed(void) { return changed; }

bool Input_Strings::is_element(string value) {
  for (const string &input_string : list) {
    if (input_string == value)
      return true;
  }
  return false;
}

void Input_Strings::write(void) {
  if (is_changed()) {
    changed = false;
  }
}
