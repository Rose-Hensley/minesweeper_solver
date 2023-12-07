#include <iostream>
#include <random>
#include <string>
#include "Controller.h"
#include "argh.h"

using std::cout, std::endl;

void help_msg() {
    std::cout << "Runs and solves a game of minesweeper" << endl <<
        "  -h or --help" << endl <<
        "    display this message" << endl <<
        "  -s or --smart" << endl <<
        "    sets the solver to smart solving" << endl <<
        "  -n or --novice" << endl <<
        "    Beginner board, 9x9 with 8 bombs" << endl <<
        "  -i or --intermediate" << endl <<
        "    Intermediate board, 16x16 with 40 bombs" << endl <<
        "  -e or --expert" << endl <<
        "    Expert board, 30x16 with 99 bombs" << endl <<
        "  -w=<int> or --width=<int>" << endl <<
        "    sets the board width to <int>" << endl <<
        "  -h=<int> or --height=<int>" << endl <<
        "    sets the board height to <int>" << endl <<
        "  -b=<int> or --bombs=<int>" << endl <<
        "    sets number of bombs to <int>" << endl;
}

int main(int argc, char* argv[]) {
    srand(time(0));

    auto cmdl = argh::parser(argc, argv);
    int wd, ht, bs;
    bool is_smart = false;

    if (cmdl[{"-h", "--help"}]) {
        help_msg();
        return 0;
    }

    if (cmdl[{ "-s", "--smart" }])
        is_smart = true;

    std::string dif = "";
    if (cmdl[{ "-n", "--novice" }])
        dif = "n";

    if (cmdl[{ "-i", "--intermediate" }])
        dif = "i";

    if (cmdl[{ "-e", "--expert" }])
        dif = "e";

    int def_w, def_h, def_b;
    if (!dif.compare("e")) {
        def_w = 30;
        def_h = 16;
        def_b = 99;
    }
    else if (!dif.compare("i")) {
        def_w = 16;
        def_h = 16;
        def_b = 40;
    }
    else {
        def_w = 9;
        def_h = 9;
        def_b = 8;
    }

    cmdl({"-w", "--width"}, def_w) >> wd;
    cmdl({"-h", "--height"}, def_h) >> ht;
    cmdl({"-b", "--bombs"}, def_b) >> bs;

    Controller c(wd,ht,bs);
    if (is_smart) {
        c.solve_smart();
    }
    else {
        c.solve_dumb();
    }

    return 0;
}
