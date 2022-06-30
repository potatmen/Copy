
#ifndef _OOP_PARSE_H_
#define  _OOP_PARSE_H_

#include <boost/program_options.hpp>
namespace po = boost::program_options;
class Parse {
  private:
  po::options_description desc("Allowed options");
  po::variables_map vm;
  int n;
  int m;
  set<pair<int, int>> points;

  public:
  Parse(int ac, char *av[]);
  bool is_have(string s);
  bool is_set(int x, int y);
  int get_n();
  int get_m();
  set<pair<int,int>> get_points();
  po::options_description get_desc();
  po::variables_map get_vm();
};

#endif //_OOP_PARSE_H_