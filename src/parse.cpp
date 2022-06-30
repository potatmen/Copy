#include "../include/parse.h"
#include <boost/program_options.hpp>

Parse::Parse(int ac, char *av[]){
  int opt;
  desc.add_options()("help", "produce help message")("batch", po::value<int>(),
    "if set, program runs automatically and you should state the number of "
    "cycles")("sleep", po::value<int>(&opt)->default_value(def_val),
    "the number of miliseconds to wait before new generation "
    "generated, default value is 1000")("size", po::value<string>(),
    "the size of the grid, you can state this value by passing NxM where N "
    "the number of rows, M the number of columns, for example --size 20x30")(
    "put", po::value<vector<string>>(),
    "initial alive cells, you can type many cells by passing NxM where N the "
    "number of row and M the number of column, for example --put 3x7 --put "
    "5x4");

  po::variables_map vm;
  po::store(po::parse_command_line(ac, av, desc), vm);
  po::notify(vm);
  //
}

bool Parse::is_set(string s){
    return vm.count(s) > 0;
}

bool Parse::is_set(int x,int y){
    return points.count({x,y}) > 0;
}