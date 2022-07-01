
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
  void print_rec(int depth);
  void print_2D_rec(int x, int y);
  Field rec_for_live(int x, int y, Field cur);

public:
  Field(){};
  Field(int n, int m);
  Field(int n, int m, vector<vector<Cell>> grid); // constructors

  int get_n();
  int get_m();
  vector<vector<Cell>> get_grid(); // getters

  Field rec_for_constructor(int x, int y, Field cur);
  Field rec_to_add_points(Field cur, vector<string> s, int pos);

  Field live();
  Field with(int x, int y, Cell a);
  void print(); // next_gen makers
};

#endif //_OOP_FIELD_H_