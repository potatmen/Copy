
#ifndef _OOP_PARSE_H_
#define  _OOP_PARSE_H_

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
  Parse(){}; // constructor

  Parse(po::variables_map vm);

  bool is_set(int x, int y);
  int get_n();
  int get_m();
  vector<string> get_grid(); // getters
  po::variables_map get_vm();
  
  bool has_x(string s);
  bool is_valid(string s);
  pair<int,int> get_point(string s);
  void get_cells();
  pair<int,int> split(string s);
  void build_all(); // builders and checkers
  };

#endif //_OOP_PARSE_H_