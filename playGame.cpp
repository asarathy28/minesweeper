#include <iostream>
#include "Cell.hpp"
using namespace std;

const int REVEAL = 1;
const int FLAG   = 2;

void reveal (Cell **grid, int gridSize, int row, int col);
void showGrid (Cell **grid, int gridSize);
void getCommand (int gridSize, int *command);
void printMenu ();

void play (Cell **grid, int **mLoc, int gridSize, int numMines) {
  // PLAY THE GAME.
  printMenu();
  bool gameover = false;
  while (gameover != true) {
    showGrid(grid, gridSize);
    int *command = new int [3];
    getCommand(gridSize, command);
    cout << "MADE IT (OUT)\n";
    int op = command[0];
    cout << "OP: " << op << '\n';
    if (op == FLAG) {
      grid[command[1]][command[2]].toggleFlagged();
    } else if (grid[command[1]][command[2]].getMined() == true){
      for (int x = 0; x < gridSize; x++) {
        for (int y = 0; y < gridSize; y++) {
          grid[x][y].setVisible();
        }
      }
      showGrid(grid, gridSize);
      cout << "YOU LOSE\n";
      gameover = true;
    } else {
      reveal(grid, gridSize, command[1], command[2]);
    }
    // check for victory
    bool victory = true;
    for (int i = 0; i < numMines; i++) {
      if (grid[mLoc[i][0]][mLoc[i][1]].getFlagged() == false) {
        victory = false;
        break;
      }
    }
    if (victory == true) {
      for (int x = 0; x < gridSize; x++) {
        for (int y = 0; y < gridSize; y++) {
          if (grid[x][y].getMined() == false && grid[x][y].getVisibility() == false) {
            victory = false;
          }
        }
      }
    }
    if (victory == true) {
      showGrid(grid, gridSize);
      cout << "YOU WIN!\n";
      gameover = true;
    }
  }
}
