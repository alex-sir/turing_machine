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
  // TODO: Add a method that allows for setting changed to true
  /**
   * @brief Constructor that initializes an object of the class with default
   *        values and a file name
   */
  Input_Strings(string input_string_file_name);
  /**
   * @brief Add an input string to the list of input strings
   *
   * @param input_string Input string to add to the list
   */
  void insert(string input_string);
  /**
   * @brief Display the list of input strings
   */
  void view(void);
  /**
   * @brief Remove a specified input string from the list of input strings
   *
   * @param input_string_number Index of the input string to remove
   */
  void remove(int input_string_number);
  /**
   * @brief Return an input string specified by the user
   *
   * @param input_string_number Index of the input string to return
   * @return string Input string specified by the user
   */
  string input_string(int input_string_number);
  /**
   * @brief Return the total number of input strings in the input strings list
   *
   * @return int Total number of input strings
   */
  int size(void);
  /**
   * @brief Return whether the input strings list has been modified
   *
   * @return bool true if the input strings list has been modified
   *              false if the input strings list has not been modified
   */
  bool is_changed(void);
  /**
   * @brief Check if a value is a duplicate in the list of input strings
   *
   * @param value String of the value to check for duplicity in the list of
   *              input strings
   * @return bool true if the value is a duplicate
   *              false if the value is not a duplicate
   */
  bool is_element(string value);
  /**
   * @brief Write the current input strings list to the input string file if the
   *        input strings list has been modified
   */
  void write(void);
};

#endif
