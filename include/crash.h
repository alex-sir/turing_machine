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
  Crash(string reason);
};

#endif
