#include <iostream>
#include <random>
#include "Controller.h"
#include "argh.h"

int main(int argc, char* argv[]) {
    srand(time(0));
    int wd = 9, ht = 9, bs = 1;
    Controller c(wd,ht,bs);
    c.solve_dumb();
    return 0;
}
