#ifndef _OOP_CELL_H_
#define _OOP_CELL_H_

using namespace std;
#include <bits/stdc++.h>

class Cell {
private:
  bool state;

public:
  Cell();
  Cell(bool state); // constructors

  bool status() const; // getter

  static Cell live(int x, int y, int n, int m,
                   vector<vector<Cell>> grid); // process
};

#endif //_OOP_CELL_H_
