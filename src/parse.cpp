#include "../include/parse.h"


Parse::Parse(po::variables_map vm){
  this->vm = vm;
}

int Parse::get_n(){
  return n;
}

int Parse::get_m(){
  return m;
}

vector<string> Parse::get_grid(){
  return points;
}

bool Parse::is_set(int x, int y) {
  string s1 = to_string(x) + "x" + to_string(y);
  string s2 = to_string(y) + "x" + to_string(x);
  vector<string> v = vm["put"].as<vector<string>>(); 
  for(int i = 0; i < v.size(); i++){
    if(s1 == v[i] ||s2 == v[i] ){
      return true;
    }
  }
  return false;
 }

bool Parse::has_x(string s) {
  return s.find('x') < s.length() - 1 && s.find('x') > 0;
}

pair<int, int> Parse::split(string s) {
  int pos = s.find('x');
  int left = stoi(s.substr(0, pos));
  int right = stoi(s.substr(pos + 1, s.length()));
  return {left, right};
}

bool Parse::is_valid(string s) {
  pair<int, int> x = split(s);
  return x.first > 0 && x.second > 0;
}

pair<int, int> Parse::get_point(string s) {
  if (has_x(s) && is_valid(s)) {
    return split(s);
  } else {
    cout << "Incorrect input in size or put" << endl;
    exit(0);
  }
}

po::variables_map  Parse::get_vm(){
  return vm;
}

void Parse::get_cells() {
  points = vm["put"].as<vector<string>>();
  for (int i = 0; i < points.size(); i++) {
    get_point(points[i]);
  }
}

void Parse::build_all() {
  pair<int, int> p = get_point(vm["size"].as<string>());
  n = p.first;
  m = p.second;
  get_cells();
}
