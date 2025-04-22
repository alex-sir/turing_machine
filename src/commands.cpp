/**
 *  Alex Carbajal
 *  CPT_S 322, Spring 2025
 *  Turing Machine
 */

#include "../include/commands.h"
#include "../include/turing_machine.h"
#include <iomanip>
#include <iostream>
using namespace std;

Commands::Commands(string new_file_name)
    : turing_machine(new_file_name), input_strings(new_file_name) {}

void Commands::del(void) {
  cout << "\nInput String Number: 1\n"
       << "Input string aabb successfully deleted from list!\n"
       << endl;
}

void Commands::exit(void) {
  cout << "\nInput strings list successfully written to file!" << endl;
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
