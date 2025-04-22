/**
 *  Alex Carbajal
 *  CPT_S 322, Spring 2025
 *  Turing Machine
 */

#ifndef CONFIGURATION_SETTINGS_H
#define CONFIGURATION_SETTINGS_H

class Configuration_Settings {
private:
  int number_of_transitions;
  int number_of_cells;

public:
  /**
   * @brief Constructor for an object of the class that sets the default values
   */
  Configuration_Settings();
  /**
   * @brief Modify the maximum number of transitions to perform on an input
   *        string
   *
   * @param number_of_transitions New maximum number of transitions
   */
  void set_number_of_transitions(int number_of_transitions);
  /**
   * @brief Modify the maximum number of cells to display in an instantaneous
   *        description
   *
   * @param number_of_cells New number of cells
   */
  void set_number_of_cells(int number_of_cells);
  /**
   * @brief Return the value of the setting for the maximum number of
   *        transitions to perform on an input string
   *
   * @return int Setting for the maximum number of transitions
   */
  int maximum_number_of_transitions(void);
  /**
   * @brief Return the value of the setting for the maximum number of cells to
   *        display in an instantaneous description
   *
   * @return int Setting for the maximum number of cells
   */
  int maximum_number_of_cells(void);
};

#endif
