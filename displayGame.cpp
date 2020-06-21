#include <iostream>
#include "Cell.hpp"
using namespace std;

const int REVEAL = 1;
const int FLAG   = 2;

void reveal (Cell **grid, int gridSize, int row, int col) {
  if (row<0 || row>=gridSize || col<0 || col>=gridSize || grid[row][col].getVisibility() == true) {
    return;
  }
  if (grid[row][col].getMinedNeighbors() > 0) {
    grid[row][col].setVisible();
    return;
  }
  grid[row][col].setVisible();
  reveal(grid, gridSize, row-1, col-1);
  reveal(grid, gridSize, row-1, col);
  reveal(grid, gridSize, row-1, col+1);
  reveal(grid, gridSize, row, col-1);
  reveal(grid, gridSize, row, col+1);
  reveal(grid, gridSize, row+1, col-1);
  reveal(grid, gridSize, row+1, col);
  reveal(grid, gridSize, row+1, col+1);
}

void showGrid (Cell **grid, int gridSize) {
  cout << '\n';
  // Show the column numbers
  cout << '\t';
  for (int col = 0; col < gridSize; col++) {
    cout << col << '\t';
  }
  cout << '\n';
  cout << "  ";
  for(int col = 0; col < gridSize; col++) {
    cout << "--------";
  }
  cout << '\n';
  // Show the grid...
  for (int row = 0; row < gridSize; row++) {
    // ...with leading row numbers.
    cout << row << "|\t";
    for (int col = 0; col < gridSize; col++) {
      cout << grid[row][col].toString() << "\t";
    }
    cout << '\n';
  }
  cout << '\n';
}

void printMenu () {
  cout << "Command format: [R|F|H] [row #] [col #]\n"
  << "\tR = Reveal a cell\n"
  << "\tF = Flag a cell\n"
  <<"\tH = Help (this info)\n"
  << "\tExample: R 3 6 (to reveal the cell in row 3, column 6";
}

void getCommand (int gridSize, int *command) {
  cout << "Enter a move (H for help): ";
  char c;
  int row;
  int col;
  cin >> c;
  cin >> row;
  cin >> col;
  cout << c << "  " << row << "  " << col << '\n';

  // convert the R/F command selection to an int
  int op = -1;
  if (c == 'R') {
    op = REVEAL;
  }
  else if (c == 'F') {
    op = FLAG;
  }
  else {
    printMenu();
    getCommand(gridSize, command);
    return;
  }

  // make sure the entered row and column are within the grid
  if (! ((0 <= row && row < gridSize) && (0 <= col && col < gridSize)) ) {
    printMenu();
    getCommand(gridSize, command);
    return;
  }

  // return an array containing the numeric value of the command
  // and the row and column to operate on
  command[0]=op;
  command[1]=row;
  command[2]= col;
  cout << "COMMAND\n";
  for (int i = 0; i<3; i++){
    cout << command[i];
  }
  return;

}
