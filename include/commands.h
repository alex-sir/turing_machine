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
  /**
   * @brief Constructor that initializes an object of the class with a file name
   *        that corresponds to the Turing machine definition file and the input
   *        string file
   */
  Commands(string new_file_name);
  /**
   * @brief Run the delete command 'd', which allows the user to select an input
   *        string to delete from the list of input strings
   */
  void del(void);
  /**
   * @brief Run the exit command 'x', which allows the user to exit the
   *        application
   */
  void exit(void);
  /**
   * @brief Run the help command 'h', which allows the user to display a help
   *        message containing a list of commands and their descriptions
   */
  void help(void);
  /**
   * @brief Run the insert command 'i', which allows the user to
   *        enter an input string to insert into the list of input strings
   */
  void insert(void);
  /**
   * @brief Run the list command 'l', which allows the user to display the list
   *        of input strings
   */
  void list(void);
  /**
   * @brief Run the quit command 'q', which allows the user to stop Turing
   *        machine operation on an input string before completion
   */
  void quit(void);
  /**
   * @brief Run the run command 'r', which allows the user to input a string to
   *        run the Turing machine on or continue operation on an existing input
   *        string
   */
  void run(void);
  /**
   * @brief Run the set command 'e', which allows the user to set the setting
   *        for the maximum number of transitions to perform at a time on an
   *        input string
   */
  void set(void);
  /**
   * @brief Run the show command 'w', which displays the status of the
   *        application
   */
  void show(void);
  /**
   * @brief Run the truncate command 't', which allows the user to set the
   *        setting for the maximum number of cells to display in an
   *        instantaneous description
   */
  void truncate(void);
  /**
   * @brief Run the view command 'v', which displays the definition of the
   *        Turing machine in a readable form
   */
  void view(void);
};

#endif
