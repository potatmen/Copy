#include <utility>

#include "../include/field.h"
#include "../include/parse.h"
const int add = 5;

Field::Field(int n, int m, vector<vector<Cell>> grid) {
  this->n = n;
  this->m = m;
  this->grid = std::move(grid);
}

Field::Field(int n, int m) {
  vector<vector<Cell>> t;
  t.resize(n);
  for (int i = 0; i < n; i++) {
    t[i].resize(m);
  }
  new (this) Field(n, m, t);
}

Field::Field() { new (this) Field(0, 0); }

int Field::length() const { return n; }

int Field::width() const { return m; }

vector<vector<Cell>> Field::field() { return grid; }

Field Field::rec_add(Field cur, vector<string> s, int pos) {
  if (pos == s.size()) {
    Field result = Field(cur.length(), cur.width(), cur.field());
    return result;
  }
  Parse p = Parse();
  pair<int, int> x = p.point(s[pos]);
  return rec_add(cur.with(x.first - 1, x.second - 1, Cell(true)), s, pos + 1);
}

void Field::rec_line_print(int depth) {
  if (depth == m * 2 + add) {
    cout << "\n";
    return;
  }
  cout << "-";
  rec_line_print(depth + 1);
}

void Field::rec_grid_print(int x, int y) {

  if (x >= n) {
    return;
  }

  if (y >= m) {
    cout << " |\n";
    rec_grid_print(x + 1, 0);
    return;
  }

  if (y == 0) {
    cout << "|  ";
  }

  if (grid[x][y].status()) {
    cout << "o ";
  } else {
    cout << ". ";
  }
  rec_grid_print(x, y + 1);
}

Field Field::rec_live(int x, int y, Field cur, bool flag) {
  if (y == m) {
    return rec_live(x + 1, 0, cur, flag);
  }

  if (x == n) {
    Field result = Field(cur.length(), cur.width(), cur.field());
    return result;
  }
  Cell replace;
  if (flag) {
    replace = cur.field()[x][y].live(x, y, n, m, grid);
  } else {
    replace = Cell(false);
  }
  return rec_live(x, y + 1, cur.with(x, y, replace), flag);
}

void Field::print() {
  rec_line_print(0);
  rec_grid_print(0, 0);
  rec_line_print(0);
}

Field Field::live() {
  Field obj = Field(n, m, grid);
  return rec_live(0, 0, obj, true);
}

Field Field::with(int x, int y, Cell a) {
  vector<vector<Cell>> next = grid;
  next[x][y] = a;
  return Field(n, m, next);
}
