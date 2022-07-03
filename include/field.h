
#ifndef _OOP_FIELD_H_
#define _OOP_FIELD_H_

#include "cell.h"
#include <bits/stdc++.h>

using namespace std;

class Field {
private:
  vector<vector<Cell>> grid;
  int n;
  int m;
  void rec_line_print(int depth);
  void rec_grid_print(int x, int y);

public:
  Field();
  Field(int n, int m);
  Field(int n, int m, vector<vector<Cell>> grid); // constructors

  int length();
  int width();
  vector<vector<Cell>> field(); // getters

  Field rec_add(Field cur, vector<string> s, int pos);
  Field rec_live(int x, int y, Field cur, bool flag);

  Field live();
  Field with(int x, int y, Cell a);
  void print(); // next_gen makers
};

#endif //_OOP_FIELD_H_