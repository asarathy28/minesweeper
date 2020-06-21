#include <iostream>
#include "Cell.hpp"
using namespace std;

const int REVEAL = 1;
const int FLAG   = 2;

void populate(Cell **grid, int gridSize, int numMines, int **mLoc);
void setNeighbors (Cell **grid, int size);
void play (Cell **grid, int **mLoc, int gridSize, int numMines);
void reveal (Cell **grid, int gridSize, int row, int col);
void showGrid (Cell **grid, int gridSize);
void getCommand (int gridSize, int *command);
void printMenu ();

int main()
{
  int numMines = 0;
  int gridSize = 0;

  cout << "Enter number of mines:\n";
  cin >> numMines;

  cout << "Enter grid side dimension:\n";
  cin >> gridSize;

  // check that the number of mines and grid size are positive
  if ((numMines <= 0) || (gridSize <= 0)) {
    cout << "Invalid values... Program will terminate\n";
    exit(0);
  }

  //int mLoc[numMines][2];
  int **mLoc;
  mLoc = new int *[numMines];
  for (int i = 0; i<numMines; i++){
    mLoc[i] = new int[2];
  }

  Cell **grid;
  grid = new Cell *[gridSize];
  for (int i = 0; i<gridSize; i++){
    grid[i] = new Cell[gridSize];
  }

  populate(grid, gridSize, numMines, mLoc);

  play(grid, mLoc, gridSize, numMines);

  return 0;
}

void populate(Cell **grid, int gridSize, int numMines, int **mLoc) {
  for(int f = 0; f < numMines; f++){
    mLoc[f][0]= (int)(rand() % gridSize);
  }
  int i = 0;
  while (i < numMines){
    mLoc[i][1]= (int)(rand() % gridSize);
    int j = 0;
    bool locRepeat = false;
    while (j < i && locRepeat == false){
      if (mLoc[i][0]== mLoc[j][0] && mLoc[i][1]== mLoc[j][1]){
        locRepeat = true;
      }
      else{
        j++;
      }
    }
    if (locRepeat == false){
      i++;
    }
  }
  for (int a = 0; a < numMines; a++){
    grid[mLoc[a][0]][mLoc[a][1]].setMined();
  }
  setNeighbors(grid, gridSize);
}

void setNeighbors (Cell **grid, int size) {
  for (int x = 0; x < size; x++) {
    for (int y = 0; y < size; y++) {
      for (int r = x-1; r <= x+1; r++) {
        for (int c = y-1; c <= y+1; c++) {
          if (r>=0 && r<size && c>=0 && c<size){
            bool minedNeighbor = false;
            minedNeighbor = grid[r][c].getMined();
            if (minedNeighbor == true){
              grid[x][y].countLiveNeighbor();
            }
          }
        }
      }
    }
  }
}
