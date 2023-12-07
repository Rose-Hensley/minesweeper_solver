#include <iostream>
#include <random>
#include "Controller.h"
#include "argh.h"

int main(int argc, char* argv[]) {
    srand(time(0));
    int wd = 16, ht = 16, bs = 32;
    Controller c(wd,ht,bs);
    c.solve_smart();
    return 0;
}
