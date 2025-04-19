/**
 *  Alex Carbajal
 *  CPT_S 322, Spring 2025
 *  Turing Machine
 */

#ifndef COMMANDS_H
#define COMMANDS_H

#include "configuration_settings.h"
#include "input_strings.h"
#include "turing_machine.h"
#include <string>
using namespace std;

// ANSI escape codes for underlines
#define UL "\033[4m"     // Add underline
#define RM_UL "\033[24m" // Remove underline

class Commands {
private:
  Turing_Machine turing_machine;
  Input_Strings input_strings;
  Configuration_Settings configuration_settings;

public:
  Commands(string new_file_name);
  /**
   * @brief Run the delete command 'd'
   *        User selects a string to delete from the list
   */
  void del(void);
  /**
   * @brief Run the exit command 'x'
   *        User exits the application
   */
  void exit(void);
  /**
   * @brief Run the help command 'h'
   *        Display commands and their descriptions
   */
  void help(void);
  /**
   * @brief Run the insert command 'i'
   *        User inputs a string to insert into the list
   */
  void insert(void);
  /**
   * @brief Run the list command 'l'
   *        Display input strings list
   */
  void list(void);
  /**
   * @brief Run the quit command 'q'
   *        Stop Turing machine operation on the input string
   */
  void quit(void);
  /**
   * @brief Run the run command 'r'
   *        User inputs a string to run the Turing machine on
   *        or continues operation on an existing input string
   */
  void run(void);
  /**
   * @brief Run the set command 'e'
   *        User sets the maximum number of transitions to perform
   */
  void set(void);
  /**
   * @brief Run the show command 'w'
   *        Display status of the application
   */
  void show(void);
  /**
   * @brief Run the truncate command 't'
   *        User sets the maximum number of cells for the instantaneous
   *        descriptions
   */
  void truncate(void);
  /**
   * @brief Run the view command 'v'
   *        Display Turing machine description
   */
  void view(void);
};

#endif
