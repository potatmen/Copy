#include "../include/field.h"
#include "../include/parse.h"
#include <unistd.h>

void sleep(int x) {
  unsigned int microsecond = time * x;
  usleep(microsecond);
}

int main(int ac, char *av[]) {
  Parse p = Parse(ac, av);
  Field f = Field(p.get_n(), p.get_m(), p.get_points());
  
}