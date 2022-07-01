#include "../include/field.h"
#include "../include/parse.h"
const int add = 5;

Field Field::rec_for_constructor(int x, int y, Field cur) {
  if (y == m) {
    return rec_for_constructor(x + 1, 0, cur);
  }

  if (x == n) {
    Field result = Field(cur.get_n(), cur.get_m(), cur.get_grid());
    return result;
  }

  Cell new_cell = Cell(false);
  return rec_for_constructor(x, y + 1, cur.with(x, y, new_cell));
}

Field Field::rec_to_add_points(Field cur, vector<string> s, int pos) {
  if (pos == s.size()) {
    Field result = Field(cur.get_n(), cur.get_m(), cur.get_grid());
    return result;
  }
  Parse p = Parse();
  pair<int,int> x = p.get_point(s[pos]);
  return rec_to_add_points(cur.with(x.first - 1,x.second - 1, Cell(true)),s,pos + 1);
}

Field::Field(int n, int m, vector<vector<Cell>> grid) {
  this->n = n;
  this->m = m;
  this->grid = grid;
}

Field::Field(int n, int m) {
  this->n = n;
  this->m = m;
  vector<vector<Cell>> t;
  t.resize(n);
  for (int i = 0; i < n; i++) {
    t[i].resize(m);
  }
  this->grid = t;
}


int Field::get_n() { return n; }

int Field::get_m() { return m; }

vector<vector<Cell>> Field::get_grid() { return grid; }

void Field::print_rec(int depth) {
  if (depth == m * 2 + add) {
    cout << "\n";
    return;
  }
  cout << "-";
  print_rec(depth + 1);
}

void Field::print_2D_rec(int x, int y) {
  if (y >= m) {
    cout << " |\n";
    print_2D_rec(x + 1, 0);
    return;
  }

  if (x >= n) {
    return;
  }

  if (y == 0) {
    cout << "|  ";
  }
  if (grid[x][y].get_state()) {
    cout << "o ";
  } else {
    cout << ". ";
  }
  print_2D_rec(x, y + 1);
}

Field Field::rec_for_live(int x, int y, Field cur) {
  if (y == m) {
    return rec_for_live(x + 1, 0, cur);
  }

  if (x == n) {
    Field result = Field(cur.get_n(), cur.get_m(), cur.get_grid());
    return result;
  }

  Cell new_cell = cur.get_grid()[x][y].live(x, y, this->get_n(),this->get_m(),this->get_grid());
  return rec_for_live(x, y + 1, cur.with(x, y, new_cell));
}

void Field::print() {
  print_rec(0);
  print_2D_rec(0, 0);
  print_rec(0);
  
}

Field Field::live() { 
  Field obj = Field(this->n,this->m,this->grid);
  return rec_for_live(0, 0, obj); }

Field Field::with(int x, int y, Cell a) {
  vector<vector<Cell>> new_grid = grid;
  new_grid[x][y] = a;
  return Field(n, m, new_grid);
}
