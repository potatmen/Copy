
#ifndef _OOP_FIELD_H_
#define  _OOP_FIELD_H_

#include <bits/stdc++.h> 
#include "cell.h"

using namespace std;

class Field {
  private:
  vector<vector<Cell>> grid;
  int n;
  int m;
  void print_rec(int depth);
  void print_2D_rec(int x,int y);
  Field rec_for_live(int x,int y, Field *cur);


  public:
  Field(int n,int m,vector<vector<Cell>> grid);
  int get_n();
  int get_m();
  vector<vector<Cell>> get_grid();

  Field live();
  Field with(int x, int y, Cell a);
  void print();
};

#endif //_OOP_FIELD_H_