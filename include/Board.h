#ifndef MINESWEEPER_BOARD_H
#define MINESWEEPER_BOARD_H

#include <memory>
#include <vector>
#include "Cell.h"

using std::vector, std::unique_ptr;

class Board {
private:
    // the cells on this board
    vector<vector<unique_ptr<Cell>>> cells;

    //
    int width;

    int height;

    int bombs;

    void init_bombs();

    void set_vals();

    int calc_val(int x, int y);

    bool oob(int x, int y);

public:
    Board(int wd, int ht, int bs);

    // Returns -2 if nothing happened
    // Returns -1 if there was a bomb
    // Returns a number from 0-8 if it was a value
    // If it was a zero, recursively clicks all adjacent cells automatically
    int click_cell(int x, int y);

    bool has_won();

};

#endif //MINESWEEPER_BOARD_H
