/**
 *  Alex Carbajal
 *  CPT_S 322, Spring 2025
 *  Turing Machine
 */

#ifndef CRASH_H
#define CRASH_H

#include <stdexcept>
#include <string>
using namespace std;

class Crash : public runtime_error {
public:
  /**
   * @brief Constructor for an object of the class that executes a runtime error
   *        with a given message
   */
  Crash(string reason);
};

#endif
