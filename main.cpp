#include "../include/field.h"
#include "../include/parse.h"
#include <unistd.h>
void sleep(int x) {
  unsigned int microsecond = time * x;
  usleep(microsecond);
}

int main(int ac, char *av[]) {
  Parse p = Parse(ac, av);
  Field f = Field(p.n, p.m, p.points);
  if (p.is_set("batch")) {
    for (int i = 0; i < p.vm["batch"] + 1; i++) {
      f.print();
      cout << "This iteration number " << i << endl;
      sleep(p.vm["sleep"]);
      f = f.live();
    }
  } else {
    while (true) {
      f.print();
      cout << "If you want to continue playing press \"b\", else \"q\".";
      string s;
      cin >> s;
      if (s == "n") {
        f = f.live();
      } else {
        break;
      }
    }
  }
}