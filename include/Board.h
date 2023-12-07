#ifndef MINESWEEPER_BOARD_H
#define MINESWEEPER_BOARD_H

#include <memory>
#include <vector>
#include "Cell.h"

using std::vector, std::unique_ptr;

// Represents a board which contains
class Board {
private:
    // the cells on this board
    vector<vector<unique_ptr<Cell>>> cells;

    // the number of cells across
    int width;

    // number of cells tall
    int height;

    // number of bombs on this board
    int bombs;

    // adds bombs up to the number of bombs at random positions on the board
    void init_bombs();

    // initializes the values for all cells by looking for adjacent bombs
    void set_vals();

    // finds the values of the cell at (x, y)
    int calc_val(int x, int y);

    // checks if a position is out of bounds
    bool oob(int x, int y);

    // returns the number of visible squares
    int get_num_visible();

public:
    // Creates a board with wd cells across and ht cells high with bs bombs
    Board(int wd, int ht, int bs);

    int get_width();

    int get_height();

    // Returns -2 if nothing happened
    // Returns -1 if there was a bomb
    // Returns a number from 0-8 if it was a value
    // If it was a zero, recursively clicks all adjacent cells automatically
    int click_cell(int x, int y);

    // Flags a cell if it is not visible and not flagged, or unflags if it is flagged already
    bool flag_cell(int x, int y);

    // Returns whether the board has been won or not
    bool has_won();

    int get_value(int x, int y);

    int is_flagged(int x, int y);

    int is_visible(int x, int y);

    int get_num_adj_flags(int x, int y);

    int get_num_adj_invisible(int x, int y);
};

#endif //MINESWEEPER_BOARD_H
