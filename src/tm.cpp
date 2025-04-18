/**
 *  Alex Carbajal
 *  CPT_S 322, Spring 2025
 *  Turing Machine
 */

#include "../include/commands.h"
#include "../include/utilities.h"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
  cout << "anbn successfully loaded!\n" << endl;

  Commands commands;
  string command = "";
  bool valid_command = false;
  bool exit = false;
  while (!exit) {
    cout << "Command: ";
    valid_command = is_valid_command(command);
    if (valid_command && command.length() <= 1) {
      switch (tolower(command[0])) {
      case 'd': // Delete
        commands.del();
        break;
      case 'x': // Exit
        commands.exit();
        exit = true;
        break;
      case 'h': // Help
        commands.help();
        break;
      case 'i': // Insert
        commands.insert();
        break;
      case 'l': // List
        commands.list();
        break;
      case 'q': // Quit
        commands.quit();
        break;
      case 'r': // Run
        commands.run();
        break;
      case 'e': // Set
        commands.set();
        break;
      case 'w': // Show
        commands.show();
        break;
      case 't': // Truncate
        commands.truncate();
        break;
      case 'v': // View
        commands.view();
        break;
      case '\0': // Empty response is ignored
        break;
      default: // Command does not exist
        commands.invalid_command();
        break;
      }
    } else {
      commands.invalid_command();
    }
  }

  return 0;
}
