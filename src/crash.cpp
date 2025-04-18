/**
 *  Alex Carbajal
 *  CPT_S 322, Spring 2025
 *  Turing Machine
 */

#include "../include/crash.h"
#include <stdexcept>
#include <string>
using namespace std;

Crash::Crash(string reason) : runtime_error(reason.c_str()) {}
