#include "../include/cell.h"

Cell::Cell(bool state) { this->state = state; }

Cell::Cell() { new (this) Cell(false); }

bool Cell::status() const { return state; }

Cell Cell::live(int x, int y, int n, int m, vector<vector<Cell>> grid) {
  int cnt = 0;
  // counting the number of alive neighbours
  if (x + 1 < n) {
    cnt += static_cast<int>(grid[x + 1][y].status());
    if (y > 0) {
      cnt += static_cast<int>(grid[x + 1][y - 1].status());
    }
    if (y < m - 1) {
      cnt += static_cast<int>(grid[x + 1][y + 1].status());
    }
  }
  if (x > 0) {
    cnt += static_cast<int>(grid[x - 1][y].status());
    if (y > 0) {
      cnt += static_cast<int>(grid[x - 1][y - 1].status());
    }
    if (y < m - 1) {
      cnt += static_cast<int>(grid[x - 1][y + 1].status());
    }
  }
  if (y > 0) {
    cnt += static_cast<int>(grid[x][y - 1].status());
  }
  if (y < m - 1) {
    cnt += static_cast<int>(grid[x][y + 1].status());
  }

  return {grid[x][y].status() && (cnt == 2 || cnt == 3) ||
          !grid[x][y].status() && (cnt == 3)};
}