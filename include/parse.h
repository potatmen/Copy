#include <boost/program_options.hpp>
namespace po = boost::program_options;
class Parse {
  po::options_description desc("Allowed options");
  po::variables_map vm;
  int n;
  int m;
  set<pair<int, int>> points;
  Parse(int ac, char *av[]);
  bool is_set(string s);
  bool is_set(int x, int y);
};