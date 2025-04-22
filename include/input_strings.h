/**
 *  Alex Carbajal
 *  CPT_S 322, Spring 2025
 *  Turing Machine
 */

#ifndef INPUT_STRINGS_H
#define INPUT_STRINGS_H

#include <string>
#include <vector>
using namespace std;

class Input_Strings {
private:
  vector<string> list;
  string file_name;
  bool changed;

public:
  /**
   * @brief Constructor that initializes an object of the class with default
   *        values and a file name
   */
  Input_Strings(string input_string_file_name);
  void insert(string input_string);
  void view(void);
  void remove(int input_string_number);
  string input_string(int input_string_number);
  int size(void);
  bool is_changed(void);
  bool is_element(string value);
  void write(void);
};

#endif
