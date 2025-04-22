/**
 *  Alex Carbajal
 *  CPT_S 322, Spring 2025
 *  Turing Machine
 */

#ifndef TAPE_ALPHABET_H
#define TAPE_ALPHABET_H

#include <fstream>
#include <vector>
using namespace std;

class Tape_Alphabet {
private:
  vector<char> alphabet = {};

public:
  /**
   * @brief Read the set of tape alphabet values from a Turing machine
   * definition file
   *
   * @param definition Turing machine definition file
   * @param valid true if the set of tape alphabet values is valid
   *              false if the set of tape alphabet values is invalid
   */
  virtual void load(ifstream &definition, bool &valid);
  /**
   * @brief Display the tape alphabet of the Turing machine
   */
  virtual void view(void) const;
  /**
   * @brief Check if a value is a duplicate in the tape alphabet
   *
   * @param value Character to check for duplicity in the tape alphabet
   * @return bool true if the value is a duplicate
   *              false if the value is not a duplicate
   */
  virtual bool is_element(char value) const;
};

#endif
