using namespace std;
#include <bits/stdc++.h> 
#include "field.h" 
class Cell{
  bool state;
  Cell(bool state);
  Cell live(int x, int y, Field f);
};