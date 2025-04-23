/**
 *  Alex Carbajal
 *  CPT_S 322, Spring 2025
 *  Turing Machine
 */

#include "../include/commands.h"
#include "../include/crash.h"
#include "../include/turing_machine.h"
#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

Commands::Commands(string file_name)
    : turing_machine(file_name), input_strings(file_name) {
  ifstream input_string_file(file_name + ".str");
  if (!input_string_file)
    throw Crash("Could not open input string file " + file_name + ".str");

  string value = "";
  bool not_duplicate = true;
  bool string_was_discarded = false;
  /*
   * Insert every line from the input string file into the list
   * Input string duplicates and invalid strings are simply discarded with an
   * appropriate error message displayed
   */
  while (getline(input_string_file, value)) {
    if (input_strings.is_element(value)) {
      cout << "Warning: Input string is duplicate" << endl;
      not_duplicate = false;
    }
    if (not_duplicate && turing_machine.is_valid_input_string(value))
      input_strings.insert(value);
    else {
      cout << "Notice: Invalid input string \"" << value << "\" discarded"
           << endl;
      // Discarding an input string changes the input strings list
      string_was_discarded = true;
    }
    not_duplicate = true;
  }
  // Don't count the input strings list as changed when reading in the list in
  // the file if no input strings were discarded
  if (!string_was_discarded)
    input_strings.set_changed(false);
  input_string_file.close();
}

void Commands::del(void) {
  cout << "\nInput String Number: 1\n"
       << "Input string aabb successfully deleted from list!\n"
       << endl;
}

void Commands::ext(void) {
  if (input_strings.is_changed()) {
    input_strings.write();
  }
}

void Commands::help(void) {
  int outw = 11; // Space between the command and description
  cout << "\n"
       << UL << "Command" << RM_UL << setw(outw - 7) << left << "" << UL
       << "Description\n"
       << RM_UL << UL << "D" << RM_UL << setw(outw - 1) << left << "elete"
       << "Delete input string from list\n"
       << "E" << UL << "x" << RM_UL << setw(outw - 2) << left << "it"
       << "Exit application\n"
       << UL << "H" << RM_UL << setw(outw - 1) << left << "elp"
       << "Help user\n"
       << UL << "I" << RM_UL << setw(outw - 1) << left << "nsert"
       << "Insert input string into list\n"
       << UL << "L" << RM_UL << setw(outw - 1) << left << "ist"
       << "List input strings\n"
       << UL << "Q" << RM_UL << setw(outw - 1) << left << "uit"
       << "Quit operation of Turing machine on input string\n"
       << UL << "R" << RM_UL << setw(outw - 1) << left << "un"
       << "Run Turing machine on input string\n"
       << "S" << UL << "e" << RM_UL << setw(outw - 2) << left << "t"
       << "Set maximum number of transitions to perform\n"
       << "Sho" << UL << "w" << RM_UL << setw(outw - 4) << left << ""
       << "Show status of application\n"
       << UL << "T" << RM_UL << setw(outw - 1) << left << "runcate"
       << "Truncate instantaneous descriptions\n"
       << UL << "V" << RM_UL << setw(outw - 1) << left << "iew"
       << "View Turing machine\n"
       << endl;
}

void Commands::insert(void) {
  cout << "\nInput String: aabb\n"
       << "Input string aabb successfully entered into list!\n"
       << endl;
}

void Commands::list(void) { input_strings.view(); }

void Commands::quit(void) {
  cout << "\nInput string abab is not accepted or rejected in 20 transitions.\n"
       << endl;
}

void Commands::run(void) {
  cout << "\nInput String Number: 2\n"
       << "0.[s0]aabb\n"
       << "20.XY[s4]XY\n"
       << "Input string aabb is accepted in 20 transitions.\n"
       << endl;
}

void Commands::set(void) {
  cout << "\nMaximum Number of Transitions [1]: 2\n"
       << "Value successfully changed to 2!\n"
       << endl;
}

void Commands::show(void) {
  cout << "\nCourse: CPT_S 322\n"
       << "Semester: Spring\n"
       << "Year: 2025\n"
       << "Instructor: Neil Corrigan\n"
       << "Author: Alex Carbajal\n"
       << "Version: 0.0\n"
       << "Maximum Number of Transitions: 1\n"
       << "Maximum Instantaneous Description Cells: 32\n"
       << "Turing Machine Name: anbn\n"
       << "Turing Machine Status: Has not been run during session\n"
       << "Input Strings List Status: Modified\n"
       << endl;
}

void Commands::truncate(void) {
  cout << "\nMaximum Instantaneous Description Cells [32]: 2\n"
       << "Value successfully changed to 2!\n"
       << endl;
}

void Commands::view(void) { turing_machine.view_definition(); }
