#include "../include/cell.h"

Cell::Cell(bool state){
    this->state = state;
}

bool Cell::get_state(){
    return state;
}

Cell Cell::live(int x,int y, Field *f){
    int cnt = 0;
    int n = f->get_n();
    int m = f->get_m();
    vector<vector<Cell>> grid = f->get_grid();
    // counting the number of alive neighbours
    if(x + 1 < n){
        cnt += grid[x + 1][y].get_state();
        if(y > 0){
            cnt += grid[x + 1][y -  1].get_state();
        }
        if(y < m - 1){
            cnt += grid[x + 1][y + 1].get_state();
        }
    }
    if(x > 0){
        cnt += grid[x - 1][y].get_state();
        if(y > 0){
            cnt += grid[x - 1][y - 1].get_state();
        }
        if(y < m - 1){
            cnt += grid[x - 1][y + 1].get_state();
        }
    }
    if(y > 0){
        cnt += grid[x][y - 1].get_state();
    }
    if(y < m - 1){
        cnt += grid[x][y + 1].get_state();
    }
    
    return Cell(g[x][y].get_state() && (cnt == 2 || cnt == 3) || !g[x][y].get_state() && (cnt == 3));

}