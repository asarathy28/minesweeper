#include <iostream>
#include <sstream>
using namespace std;
#pragma once

class Cell {
private:
  const string HIDDEN;
  const string EMPTY;
  const string FLAGGED;
  const string MINED;

  int  minedNeighbors;
  bool isMine;
  bool isVisible;
  bool isFlagged;

public:
  Cell ();

  int getMinedNeighbors ();

  void countLiveNeighbor ();

  bool getMined ();

  void setMined ();

  bool getVisibility ();

  void setVisible ();

  bool getFlagged ();

  void toggleFlagged ();

  // determines how to visually represent the Cell
  string toString ();
};
