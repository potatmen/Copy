#include "../include/parse.h"

Parse::Parse(po::variables_map vm) { this->vm = vm; }

Parse::Parse() { new (this) Parse(NULL); }

int Parse::lenght() { return n; }

int Parse::width() { return m; }

vector<string> Parse::grid() { return points; }

bool Parse::has(string s, char c) {
  return s.find(c) < s.length() - 1 && s.find(c) > 0;
}

pair<int, int> Parse::split(string s) {
  int pos = s.find('x');
  int left = stoi(s.substr(0, pos));
  int right = stoi(s.substr(pos + 1, s.length()));
  return {left, right};
}

bool Parse::valid(string s) {
  pair<int, int> x = split(s);
  return x.first > 0 && x.second > 0;
}

pair<int, int> Parse::point(string s) {
  if (has(s, 'x') && valid(s)) {
    return split(s);
  }
  cout << "Incorrect input in size or put";
  exit(0);
}

po::variables_map Parse::opts() { return vm; }

void Parse::cells() {
  points = vm["put"].as<vector<string>>();
  for (int i = 0; i < points.size(); i++) {
    point(points[i]);
  }
}

void Parse::build() {
  pair<int, int> p = point(vm["size"].as<string>());
  n = p.first;
  m = p.second;
  cells();
}
