
#ifndef _OOP_PARSE_H_
#define _OOP_PARSE_H_

#include <bits/stdc++.h>
#include <boost/program_options.hpp>
using namespace std;
namespace po = boost::program_options;
class Parse {
private:
  int n;
  int m;
  vector<string> points;
  po::variables_map vm;

public:
  Parse();
  Parse(po::variables_map vm); // constructor

  int lenght();
  int width();
  vector<string> grid();
  po::variables_map opts(); // getters

  bool has(string s, char c);
  bool valid(string s);
  pair<int, int> point(string s);
  void cells();
  pair<int, int> split(string s);
  void build(); // builders and checkers
};

#endif //_OOP_PARSE_H_