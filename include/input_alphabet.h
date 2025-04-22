/**
 *  Alex Carbajal
 *  CPT_S 322, Spring 2025
 *  Turing Machine
 */

#ifndef INPUT_ALPHABET_H
#define INPUT_ALPHABET_H

#include "tape_alphabet.h"
#include <fstream>
#include <vector>
using namespace std;

class Input_Alphabet : public Tape_Alphabet {
private:
  vector<char> alphabet = {};

public:
  /**
   * @brief Read the set of input alphabet values from a Turing machine
   * definition file
   *
   * @param definition Turing machine definition file
   * @param valid true if the set of input alphabet values is valid
   *              false if the set of input alphabet values is invalid
   */
  void load(ifstream &definition, bool &valid) override;
  /**
   * @brief Determine if the input alphabet is a subset of the tape alphabet
   *
   * @param tape_alphabet Tape alphabet to compare to the input alaphabet
   * @param valid true if the input alphabet is a subset of the tape alphabet
   *              false if the input alphabet is not a subset of the tape
   *              alphabet
   */
  void validate(const Tape_Alphabet &tape_alphabet, bool &valid) const;
  /**
   * @brief Display the input alphabet of the Turing machine
   */
  void view(void) const override;
};

#endif
