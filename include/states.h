/**
 *  Alex Carbajal
 *  CPT_S 322, Spring 2025
 *  Turing Machine
 */

#ifndef STATES_H
#define STATES_H

#include <fstream>
#include <string>
#include <vector>
using namespace std;

class States {
private:
  vector<string> names = {};

public:
  /**
   * @brief Read the set of states from a Turing machine definition file
   *
   * @param definition Turing machine definition file
   * @param valid true if the set of states is valid
   *              false if the set of states is invalid
   */
  void load(ifstream &definition, bool &valid);
  /**
   * @brief Display the states of the Turing machine
   */
  void view(void) const;
  /**
   * @brief Check if a value is a duplicate in the set of states
   *
   * @param value String of the value to check for duplicity in the set of
   *              states
   * @return bool true if the value is a duplicate
   *              false if the value is not a duplicate
   */
  bool is_element(string value);
};

#endif
