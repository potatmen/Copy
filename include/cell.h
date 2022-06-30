#ifndef _OOP_CELL_H_
#define _OOP_CELL_H_


using namespace std;
#include <bits/stdc++.h>
#include "field.h" 

class Cell{
  private:
  bool state;

  public:
  Cell(bool state);
  bool get_state();
  
  Cell live(int x, int y, Field *f);
};

#endif //_OOP_CELL_H_
