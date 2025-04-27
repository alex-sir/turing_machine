/**
 *  Alex Carbajal
 *  CPT_S 322, Spring 2025
 *  Turing Machine
 */

#include "../include/commands.h"
#include "../include/crash.h"
#include "../include/utilities.h"
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
  Utilities utilities;
  if (!utilities.is_valid_arguments(argc))
    return EXIT_FAILURE;

  try {
    Commands commands(argv[1]);
    string turing_machine_name = argv[1];
    size_t forward_slash_position = turing_machine_name.find_last_of('/');
    if (forward_slash_position != string::npos)
      turing_machine_name =
          turing_machine_name.substr(forward_slash_position + 1);
    cout << turing_machine_name << " successfully loaded!\n" << endl;
    string command = "";
    bool valid_command = false;
    bool exit = false;
    while (!exit) {
      cout << "Command: ";
      valid_command = utilities.is_valid_command(command);
      if (valid_command && command.length() <= 1) {
        switch (tolower(command[0])) {
        case 'd': // Delete
          commands.del();
          break;
        case 'x': // Exit
          commands.ext();
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
          utilities.invalid_command();
          break;
        }
      } else {
        utilities.invalid_command();
      }
    }
  } catch (const Crash &error) {
    cout << "Error: " << error.what() << endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
