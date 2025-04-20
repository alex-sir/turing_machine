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
  vector<string> names;

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
   * @brief Display the set of all states of the Turing machine
   */
  void view(void) const;
  /**
   * @brief Check if a state is a duplicate
   *
   * @param value String of the state to check for duplicity
   * @return bool true if the state is a duplicate
   *              false if the state is not a duplicate
   */
  bool is_element(string value);
};

#endif
