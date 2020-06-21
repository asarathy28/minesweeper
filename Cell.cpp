#include <iostream>
#include "Cell.hpp"
using namespace std;



Cell::Cell () : HIDDEN ("H"), EMPTY (" "), FLAGGED ("f"), MINED ("!")
{
  minedNeighbors = 0;
  isMine         = false;
  isVisible      = false;
  isFlagged      = false;
}

int Cell::getMinedNeighbors () {
  return minedNeighbors;
}

void Cell::countLiveNeighbor () {
  minedNeighbors = minedNeighbors + 1;
}

bool Cell::getMined () {
  return isMine;
}

void Cell::setMined () {
  isMine = true;
}

bool Cell::getVisibility () {
  return isVisible;
}

void Cell::setVisible () {
  isVisible = true;
}

bool Cell::getFlagged () {
  return isFlagged;
}
void Cell::toggleFlagged () {
  isFlagged = !isFlagged;
}

// determines how to visually represent the Cell
string Cell::toString () {
  if (isVisible) {
    if (isMine) {
      return MINED;
    }
    else if (minedNeighbors == 0) {
      return EMPTY;
    }
    else {
      return to_string(minedNeighbors);
    }
  }
  else {
    if (isFlagged) {
      return FLAGGED;
    }
    else {
      return HIDDEN;
    }
  }
}
