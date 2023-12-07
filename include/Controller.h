#ifndef MINESWEEPER_CONTROLLER_H
#define MINESWEEPER_CONTROLLER_H

using std::tuple, std::get;

#include "Board.h"
#include "Renderer.h"

class Controller {
private:
    Board b;

    Renderer r;

    int click_cell(int x, int y);

    void click_adjacent_non_flag(int x, int y);

    bool flag_cell(int x, int y);

    std::tuple<int, int> next_click_dumb();

    std::tuple<int, int> next_click_smart();

    bool flag_smart();

public:
    Controller(int wd, int ht, int bs);

    void solve_dumb();

    void solve_smart();

    void solve_really_smart();

    void test();
};

#endif //MINESWEEPER_CONTROLLER_H
