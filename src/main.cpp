#include <unistd.h>
#include "../include/field.h"
#include "../include/parse.h"

const int t = 1000;

void sleep(int x) {
  unsigned int microsecond = t * x;
  usleep(microsecond);
}

Field f;
Parse p;
void rec(int depth, int max_depth, bool flag, Field cur) {
  cout << "\033[2J\033[1;1H";
  if (depth > max_depth) {
    return;
  }
  cur.print();
  Field new_field = cur.live();
  if (flag) {
    cout << "If you want to play more press \"n\", else \"q\"." << endl;
    string s;
    cin >> s;
    if (s == "n") {
      rec(depth, max_depth, true, new_field);
    } else {
      return;
    }
  } else {
    sleep(p.get_vm()["sleep"].as<int>());
    rec(depth + 1, max_depth, false, new_field);
  }
}
const int def_val = 1000;
int main(int ac, char *av[]) {
  int opt;
  po::options_description desc("Allowed options");
  desc.add_options()("help", "produce help message")(
      "batch", po::value<int>(),
      "if set, program runs automatically and you should state the number of "
      "cycles")("sleep", po::value<int>(&opt)->default_value(def_val),
                "the number of miliseconds to wait before new generation "
                "generated, default value is 1000")(
      "size", po::value<string>(),
      "the size of the grid, you can state this value by passing NxM where N "
      "the number of rows, M the number of columns, for example --size 20x30")(
      "put", po::value<vector<string>>(),
      "initial alive cells, you can type many cells by passing NxM where N the "
      "number of row and M the number of column, for example --put 3x7 --put "
      "5x4");
  po::variables_map vm;
  po::store(po::parse_command_line(ac, av, desc), vm);
  po::notify(vm);

  p = Parse(vm);
  p.build_all();
  Field clear_f = Field(p.get_n(), p.get_m());
  Field filled_f = clear_f.rec_for_constructor(0, 0, clear_f);
  f = filled_f.rec_to_add_points(filled_f,p.get_grid(),0);
  if (vm.count("batch") > 0) {
    rec(0, vm["batch"].as<int>(), false, f);
  } else {
    rec(0, 0, true, f);
  }
}