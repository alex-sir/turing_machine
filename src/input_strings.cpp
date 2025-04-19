/**
 *  Alex Carbajal
 *  CPT_S 322, Spring 2025
 *  Turing Machine
 */

#include "../include/input_strings.h"
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

Input_Strings::Input_Strings(string input_string_file_name)
    : list({}), file_name(""), changed(false) {
  ifstream input_string_file(input_string_file_name + ".str");
  if (!input_string_file) {
    cerr << "Error: Could not open input string file "
         << input_string_file_name + ".str" << endl;
    exit(EXIT_FAILURE);
  }

  string input_string_file_line = "";
  // Insert every line from the input string file into the list
  while (getline(input_string_file, input_string_file_line)) {
    insert(input_string_file_line);
  }

  input_string_file.close();
}

void Input_Strings::insert(string input_string) {
  // TODO: Check if the input string is valid
  list.push_back(input_string);
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
