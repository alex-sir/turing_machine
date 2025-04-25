/**
 *  Alex Carbajal
 *  CPT_S 322, Spring 2025
 *  Turing Machine
 */

#ifndef FINAL_STATES_H
#define FINAL_STATES_H

#include "states.h"
#include <string>
#include <vector>
using namespace std;

class Final_States : public States {
private:
  vector<string> names = {};

public:
  /**
   * @brief Read the set of final states from a Turing machine definition file
   *
   * @param definition Turing machine definition file
   * @param valid true if the set of final states is valid
   *              false if the set of final states is invalid
   */
  void load(ifstream &definition, bool &valid) override;
  /**
   * @brief Determine if the set of final states are a subset of the set of
   *        states
   *
   * @param states Set of states to compare to the set of final states
   * @param valid true if the set of final states is a subset of the set of
   *              states
   *              false if the set of final states is not a subset of the set of
   *              states
   */
  void validate(const States &states, bool &valid) const;
  /**
   * @brief Display the set of final states of the Turing machine
   */
  void view(void) const override;
  /**
   * @brief Check if a value is an element in the set of final states
   *
   * @param value String of the value to check
   * @return bool true if the value is in the set of final states
   *              false if the value is not in the set of final states
   */
  bool is_element(string value) const override;
};

#endif
