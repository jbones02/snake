#include <iostream>
#include <stdlib.h>
#include <vector.h>

using tile = char;
// Possible tiles
#define empty ' '
#define snake '+'
#define border '#'
#define apple '@'

// Global vars
int score = 0;
int snake_size = 4;  // Snake size starts at 4
std::vector<std::vector<tile>> grid;
int grid_height;
int grid_width;
int border_height;
int border_width;
int y_pos;
int x_pos;

// Checks if arg is valid
bool arg_is_valid(std::string arg_to_check) {
  for (int i = 0; i < arg_to_check.size(); i++) {
    if (!isdigit(arg_to_check.at(i))) {
      return false;  // If arg is not digit, return false
    }
  }
  return true;
}

void take_cmd_args() {
   
}

void setup(int argc, char** argv) {
  // If no command line args are given, use default grid size
  if (argc == 1) {
      grid_height = 15;
      grid_width = 17;

  // If command args are given, check the amount
  } else if (argc == 3) {
    // Convert command args to cpp strings
    std::string cmd_arg_1(argv[2]);
    std::string cmd_arg_2(argv[3]);
    // Check that command args are digits
    if (arg_is_valid(cmd_arg_1) && arg_is_valid(cmd_arg_2)) {
      grid_height = stoi(cmd_arg_1);
      grid_width = stoi(cmd_arg_2);
    } else {
      std::cerr << "Error: command line arguments given were not integers\n";
      exit(1);
    }
  } else {
    std::cerr << "Error: incorrect number of command line arguments were given\n"
    << "Either give no arguments to use default values, or 2 integers for the height and width of the grid\n";
    exit(2);
  }

  // Set border sizes
  border_height = grid_height + 2;
  border_width = grid_width + 2;
  y_pos = (grid_height / 2) + 1;
  x_pos = 5;

  // Setup grid
  for (int i = 0; i < grid_height; i++) {
    std::vector<tile> cur_row;
    // Construct grid one row at a time
    for (int j = 0; j < grid_width; j++) {
      cur_row.pushback(empty);
    }
    grid.pushback(cur_row);  // Add current row being constructed to grid
  }

  // Add snake to starting grid
  for (int i = 0; i < snake_size; i++) {
    grid.at(y_pos).at(x_pos - i) = snake;
  }
}

int main(int argc, char** argv) {
  // Setup game
  setup();
  // Play game
  play();
  // Output results
  results();
  return 0;
}
