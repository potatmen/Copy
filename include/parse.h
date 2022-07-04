
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

  int lenght() const;
  int width() const;
  vector<string> grid();
  po::variables_map opts(); // getters

  static bool has(const string &s, char c);
  bool valid(string const &s);
  pair<int, int> point(const string &s);
  void cells();
  static pair<int, int> split(const string &s);
  void build(); // builders and checkers
};

#endif //_OOP_PARSE_H_