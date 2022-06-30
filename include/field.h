using namespace std;
#include <bits/stdc++.h> 
#include "cell.h"

class Field {
  vector<vector> grid;
  int n;
  int m;
  Field(int n, int m, set<pair<int, int>> p);
  Field live();
  Field with(int x, int y, Cell c, Field initial);
  void print();
};