/**
 *  Alex Carbajal
 *  CPT_S 322, Spring 2025
 *  Turing Machine
 */

#include "../include/configuration_settings.h"

Configuration_Settings::Configuration_Settings()
    : number_of_transitions(1), number_of_cells(32) {}

void Configuration_Settings::set_number_of_transitions(
    int number_of_transitions) {
  this->number_of_transitions = number_of_transitions;
}

void Configuration_Settings::set_number_of_cells(int number_of_cells) {
  this->number_of_cells = number_of_cells;
}

int Configuration_Settings::maximum_number_of_transitions(void) {
  return number_of_transitions;
}

int Configuration_Settings::maximum_number_of_cells(void) {
  return number_of_cells;
}
